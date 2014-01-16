/*
 * Copyright (C) 2009, 2013 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#ifndef ArrayBuffer_h
#define ArrayBuffer_h

#include "GCIncomingRefCounted.h"
#include "Weak.h"
#include <wtf/PassRefPtr.h>
#include <wtf/StdLibExtras.h>
#include <wtf/Vector.h>

namespace JSC {

class ArrayBuffer;
class ArrayBufferView;
class JSArrayBuffer;

class ArrayBufferContents {
    WTF_MAKE_NONCOPYABLE(ArrayBufferContents);
public:
    ArrayBufferContents() 
        : m_data(0)
        , m_sizeInBytes(0)
    { }

    inline ~ArrayBufferContents();
    
    void* data() { return m_data; }
    unsigned sizeInBytes() { return m_sizeInBytes; }

private:
    ArrayBufferContents(void* data, unsigned sizeInBytes) 
        : m_data(data)
        , m_sizeInBytes(sizeInBytes)
    { }

    friend class ArrayBuffer;

    enum InitializationPolicy {
        ZeroInitialize,
        DontInitialize
    };

    static inline void tryAllocate(unsigned numElements, unsigned elementByteSize, InitializationPolicy, ArrayBufferContents&);
    void transfer(ArrayBufferContents& other)
    {
        ASSERT(!other.m_data);
        other.m_data = m_data;
        other.m_sizeInBytes = m_sizeInBytes;
        m_data = 0;
        m_sizeInBytes = 0;
    }

    void copyTo(ArrayBufferContents& other)
    {
        ASSERT(!other.m_data);
        ArrayBufferContents::tryAllocate(m_sizeInBytes, sizeof(char), ArrayBufferContents::DontInitialize, other);
        if (!other.m_data)
            return;
        memcpy(other.m_data, m_data, m_sizeInBytes);
        other.m_sizeInBytes = m_sizeInBytes;
    }

    void* m_data;
    unsigned m_sizeInBytes;
};

class ArrayBuffer : public GCIncomingRefCounted<ArrayBuffer> {
public:
    static inline PassRefPtr<ArrayBuffer> create(unsigned numElements, unsigned elementByteSize);
    static inline PassRefPtr<ArrayBuffer> create(ArrayBuffer*);
    static inline PassRefPtr<ArrayBuffer> create(const void* source, unsigned byteLength);
    static inline PassRefPtr<ArrayBuffer> create(ArrayBufferContents&);
    static inline PassRefPtr<ArrayBuffer> createAdopted(const void* data, unsigned byteLength);

    // Only for use by Uint8ClampedArray::createUninitialized.
    static inline PassRefPtr<ArrayBuffer> createUninitialized(unsigned numElements, unsigned elementByteSize);

    inline void* data();
    inline const void* data() const;
    inline unsigned byteLength() const;
    
    inline size_t gcSizeEstimateInBytes() const;

    inline PassRefPtr<ArrayBuffer> slice(int begin, int end) const;
    inline PassRefPtr<ArrayBuffer> slice(int begin) const;
    
    inline void pin();
    inline void unpin();

    JS_EXPORT_PRIVATE bool transfer(ArrayBufferContents&);
    bool isNeutered() { return !m_contents.m_data; }
    
    static ptrdiff_t offsetOfData() { return OBJECT_OFFSETOF(ArrayBuffer, m_contents) + OBJECT_OFFSETOF(ArrayBufferContents, m_data); }

    ~ArrayBuffer() { }

private:
    static inline PassRefPtr<ArrayBuffer> create(unsigned numElements, unsigned elementByteSize, ArrayBufferContents::InitializationPolicy);

    inline ArrayBuffer(ArrayBufferContents&);
    inline PassRefPtr<ArrayBuffer> sliceImpl(unsigned begin, unsigned end) const;
    inline unsigned clampIndex(int index) const;
    static inline int clampValue(int x, int left, int right);

    unsigned m_pinCount;
    ArrayBufferContents m_contents;

public:
    Weak<JSArrayBuffer> m_wrapper;
};

int ArrayBuffer::clampValue(int x, int left, int right)
{
    ASSERT(left <= right);
    if (x < left)
        x = left;
    if (right < x)
        x = right;
    return x;
}

PassRefPtr<ArrayBuffer> ArrayBuffer::create(unsigned numElements, unsigned elementByteSize)
{
    return create(numElements, elementByteSize, ArrayBufferContents::ZeroInitialize);
}

PassRefPtr<ArrayBuffer> ArrayBuffer::create(ArrayBuffer* other)
{
    return ArrayBuffer::create(other->data(), other->byteLength());
}

PassRefPtr<ArrayBuffer> ArrayBuffer::create(const void* source, unsigned byteLength)
{
    ArrayBufferContents contents;
    ArrayBufferContents::tryAllocate(byteLength, 1, ArrayBufferContents::ZeroInitialize, contents);
    if (!contents.m_data)
        return 0;
    RefPtr<ArrayBuffer> buffer = adoptRef(new ArrayBuffer(contents));
    ASSERT(!byteLength || source);
    memcpy(buffer->data(), source, byteLength);
    return buffer.release();
}

PassRefPtr<ArrayBuffer> ArrayBuffer::create(ArrayBufferContents& contents)
{
    return adoptRef(new ArrayBuffer(contents));
}

PassRefPtr<ArrayBuffer> ArrayBuffer::createAdopted(const void* data, unsigned byteLength)
{
    ArrayBufferContents contents(const_cast<void*>(data), byteLength);
    return create(contents);
}

PassRefPtr<ArrayBuffer> ArrayBuffer::createUninitialized(unsigned numElements, unsigned elementByteSize)
{
    return create(numElements, elementByteSize, ArrayBufferContents::DontInitialize);
}

PassRefPtr<ArrayBuffer> ArrayBuffer::create(unsigned numElements, unsigned elementByteSize, ArrayBufferContents::InitializationPolicy policy)
{
    ArrayBufferContents contents;
    ArrayBufferContents::tryAllocate(numElements, elementByteSize, policy, contents);
    if (!contents.m_data)
        return 0;
    return adoptRef(new ArrayBuffer(contents));
}

ArrayBuffer::ArrayBuffer(ArrayBufferContents& contents)
    : m_pinCount(0)
{
    contents.transfer(m_contents);
}

void* ArrayBuffer::data()
{
    return m_contents.m_data;
}

const void* ArrayBuffer::data() const
{
    return m_contents.m_data;
}

unsigned ArrayBuffer::byteLength() const
{
    return m_contents.m_sizeInBytes;
}

size_t ArrayBuffer::gcSizeEstimateInBytes() const
{
    return sizeof(ArrayBuffer) + static_cast<size_t>(byteLength());
}

PassRefPtr<ArrayBuffer> ArrayBuffer::slice(int begin, int end) const
{
    return sliceImpl(clampIndex(begin), clampIndex(end));
}

PassRefPtr<ArrayBuffer> ArrayBuffer::slice(int begin) const
{
    return sliceImpl(clampIndex(begin), byteLength());
}

PassRefPtr<ArrayBuffer> ArrayBuffer::sliceImpl(unsigned begin, unsigned end) const
{
    unsigned size = begin <= end ? end - begin : 0;
    return ArrayBuffer::create(static_cast<const char*>(data()) + begin, size);
}

unsigned ArrayBuffer::clampIndex(int index) const
{
    unsigned currentLength = byteLength();
    if (index < 0)
        index = currentLength + index;
    return clampValue(index, 0, currentLength);
}

void ArrayBuffer::pin()
{
    m_pinCount++;
}

void ArrayBuffer::unpin()
{
    m_pinCount--;
}

void ArrayBufferContents::tryAllocate(unsigned numElements, unsigned elementByteSize, ArrayBufferContents::InitializationPolicy policy, ArrayBufferContents& result)
{
    // Do not allow 31-bit overflow of the total size.
    if (numElements) {
        unsigned totalSize = numElements * elementByteSize;
        if (totalSize / numElements != elementByteSize
            || totalSize > static_cast<unsigned>(std::numeric_limits<int32_t>::max())) {
            result.m_data = 0;
            return;
        }
    }
    bool allocationSucceeded = false;
    if (policy == ZeroInitialize)
        allocationSucceeded = WTF::tryFastCalloc(numElements, elementByteSize).getValue(result.m_data);
    else {
        ASSERT(policy == DontInitialize);
        allocationSucceeded = WTF::tryFastMalloc(numElements * elementByteSize).getValue(result.m_data);
    }

    if (allocationSucceeded) {
        result.m_sizeInBytes = numElements * elementByteSize;
        return;
    }
    result.m_data = 0;
}

ArrayBufferContents::~ArrayBufferContents()
{
    WTF::fastFree(m_data);
}

} // namespace JSC

using JSC::ArrayBuffer;

#endif // ArrayBuffer_h
