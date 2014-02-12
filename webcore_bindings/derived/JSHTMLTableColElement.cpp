/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSHTMLTableColElement.h"

#include "HTMLNames.h"
#include "HTMLTableColElement.h"
#include "URL.h"
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

/* Hash table */

static const HashTableValue JSHTMLTableColElementTableValues[] =
{
    { "align", DontDelete, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLTableColElementAlign), (intptr_t)setJSHTMLTableColElementAlign },
    { "ch", DontDelete, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLTableColElementCh), (intptr_t)setJSHTMLTableColElementCh },
    { "chOff", DontDelete, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLTableColElementChOff), (intptr_t)setJSHTMLTableColElementChOff },
    { "span", DontDelete, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLTableColElementSpan), (intptr_t)setJSHTMLTableColElementSpan },
    { "vAlign", DontDelete, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLTableColElementVAlign), (intptr_t)setJSHTMLTableColElementVAlign },
    { "width", DontDelete, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLTableColElementWidth), (intptr_t)setJSHTMLTableColElementWidth },
    { "constructor", DontEnum | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsHTMLTableColElementConstructor), (intptr_t)0 },
    { 0, 0, NoIntrinsic, 0, 0 }
};

static const HashTable JSHTMLTableColElementTable = { 17, 15, JSHTMLTableColElementTableValues, 0 };
/* Hash table for constructor */

static const HashTableValue JSHTMLTableColElementConstructorTableValues[] =
{
    { 0, 0, NoIntrinsic, 0, 0 }
};

static const HashTable JSHTMLTableColElementConstructorTable = { 1, 0, JSHTMLTableColElementConstructorTableValues, 0 };
const ClassInfo JSHTMLTableColElementConstructor::s_info = { "HTMLTableColElementConstructor", &Base::s_info, &JSHTMLTableColElementConstructorTable, 0, CREATE_METHOD_TABLE(JSHTMLTableColElementConstructor) };

JSHTMLTableColElementConstructor::JSHTMLTableColElementConstructor(Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
}

void JSHTMLTableColElementConstructor::finishCreation(VM& vm, JSDOMGlobalObject* globalObject)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));
    putDirect(vm, vm.propertyNames->prototype, JSHTMLTableColElementPrototype::self(vm, globalObject), DontDelete | ReadOnly);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), ReadOnly | DontDelete | DontEnum);
}

bool JSHTMLTableColElementConstructor::getOwnPropertySlot(JSObject* object, ExecState* exec, PropertyName propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLTableColElementConstructor, JSDOMWrapper>(exec, JSHTMLTableColElementConstructorTable, jsCast<JSHTMLTableColElementConstructor*>(object), propertyName, slot);
}

/* Hash table for prototype */

static const HashTableValue JSHTMLTableColElementPrototypeTableValues[] =
{
    { 0, 0, NoIntrinsic, 0, 0 }
};

static const HashTable JSHTMLTableColElementPrototypeTable = { 1, 0, JSHTMLTableColElementPrototypeTableValues, 0 };
const ClassInfo JSHTMLTableColElementPrototype::s_info = { "HTMLTableColElementPrototype", &Base::s_info, &JSHTMLTableColElementPrototypeTable, 0, CREATE_METHOD_TABLE(JSHTMLTableColElementPrototype) };

JSObject* JSHTMLTableColElementPrototype::self(VM& vm, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSHTMLTableColElement>(vm, globalObject);
}

const ClassInfo JSHTMLTableColElement::s_info = { "HTMLTableColElement", &Base::s_info, &JSHTMLTableColElementTable, 0 , CREATE_METHOD_TABLE(JSHTMLTableColElement) };

JSHTMLTableColElement::JSHTMLTableColElement(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<HTMLTableColElement> impl)
    : JSHTMLElement(structure, globalObject, impl)
{
}

void JSHTMLTableColElement::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));
}

JSObject* JSHTMLTableColElement::createPrototype(VM& vm, JSGlobalObject* globalObject)
{
    return JSHTMLTableColElementPrototype::create(vm, globalObject, JSHTMLTableColElementPrototype::createStructure(vm, globalObject, JSHTMLElementPrototype::self(vm, globalObject)));
}

bool JSHTMLTableColElement::getOwnPropertySlot(JSObject* object, ExecState* exec, PropertyName propertyName, PropertySlot& slot)
{
    JSHTMLTableColElement* thisObject = jsCast<JSHTMLTableColElement*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    return getStaticValueSlot<JSHTMLTableColElement, Base>(exec, JSHTMLTableColElementTable, thisObject, propertyName, slot);
}

EncodedJSValue jsHTMLTableColElementAlign(ExecState* exec, EncodedJSValue slotBase, EncodedJSValue thisValue, PropertyName)
{
    JSHTMLTableColElement* castedThis = jsDynamicCast<JSHTMLTableColElement*>(JSValue::decode(thisValue));
    UNUSED_PARAM(slotBase);
    if (!castedThis)
        return throwVMTypeError(exec);
    UNUSED_PARAM(exec);
    HTMLTableColElement& impl = castedThis->impl();
    JSValue result = jsStringWithCache(exec, impl.fastGetAttribute(WebCore::HTMLNames::alignAttr));
    return JSValue::encode(result);
}


EncodedJSValue jsHTMLTableColElementCh(ExecState* exec, EncodedJSValue slotBase, EncodedJSValue thisValue, PropertyName)
{
    JSHTMLTableColElement* castedThis = jsDynamicCast<JSHTMLTableColElement*>(JSValue::decode(thisValue));
    UNUSED_PARAM(slotBase);
    if (!castedThis)
        return throwVMTypeError(exec);
    UNUSED_PARAM(exec);
    HTMLTableColElement& impl = castedThis->impl();
    JSValue result = jsStringWithCache(exec, impl.fastGetAttribute(WebCore::HTMLNames::charAttr));
    return JSValue::encode(result);
}


EncodedJSValue jsHTMLTableColElementChOff(ExecState* exec, EncodedJSValue slotBase, EncodedJSValue thisValue, PropertyName)
{
    JSHTMLTableColElement* castedThis = jsDynamicCast<JSHTMLTableColElement*>(JSValue::decode(thisValue));
    UNUSED_PARAM(slotBase);
    if (!castedThis)
        return throwVMTypeError(exec);
    UNUSED_PARAM(exec);
    HTMLTableColElement& impl = castedThis->impl();
    JSValue result = jsStringWithCache(exec, impl.fastGetAttribute(WebCore::HTMLNames::charoffAttr));
    return JSValue::encode(result);
}


EncodedJSValue jsHTMLTableColElementSpan(ExecState* exec, EncodedJSValue slotBase, EncodedJSValue thisValue, PropertyName)
{
    JSHTMLTableColElement* castedThis = jsDynamicCast<JSHTMLTableColElement*>(JSValue::decode(thisValue));
    UNUSED_PARAM(slotBase);
    if (!castedThis)
        return throwVMTypeError(exec);
    UNUSED_PARAM(exec);
    HTMLTableColElement& impl = castedThis->impl();
    JSValue result = jsNumber(impl.span());
    return JSValue::encode(result);
}


EncodedJSValue jsHTMLTableColElementVAlign(ExecState* exec, EncodedJSValue slotBase, EncodedJSValue thisValue, PropertyName)
{
    JSHTMLTableColElement* castedThis = jsDynamicCast<JSHTMLTableColElement*>(JSValue::decode(thisValue));
    UNUSED_PARAM(slotBase);
    if (!castedThis)
        return throwVMTypeError(exec);
    UNUSED_PARAM(exec);
    HTMLTableColElement& impl = castedThis->impl();
    JSValue result = jsStringWithCache(exec, impl.fastGetAttribute(WebCore::HTMLNames::valignAttr));
    return JSValue::encode(result);
}


EncodedJSValue jsHTMLTableColElementWidth(ExecState* exec, EncodedJSValue slotBase, EncodedJSValue thisValue, PropertyName)
{
    JSHTMLTableColElement* castedThis = jsDynamicCast<JSHTMLTableColElement*>(JSValue::decode(thisValue));
    UNUSED_PARAM(slotBase);
    if (!castedThis)
        return throwVMTypeError(exec);
    UNUSED_PARAM(exec);
    HTMLTableColElement& impl = castedThis->impl();
    JSValue result = jsStringWithCache(exec, impl.fastGetAttribute(WebCore::HTMLNames::widthAttr));
    return JSValue::encode(result);
}


EncodedJSValue jsHTMLTableColElementConstructor(ExecState* exec, EncodedJSValue thisValue, EncodedJSValue, PropertyName)
{
    JSHTMLTableColElement* domObject = jsDynamicCast<JSHTMLTableColElement*>(JSValue::decode(thisValue));
    if (!domObject)
        return throwVMTypeError(exec);
    if (!domObject)
        return throwVMTypeError(exec);
    return JSValue::encode(JSHTMLTableColElement::getConstructor(exec->vm(), domObject->globalObject()));
}

void JSHTMLTableColElement::put(JSCell* cell, ExecState* exec, PropertyName propertyName, JSValue value, PutPropertySlot& slot)
{
    JSHTMLTableColElement* thisObject = jsCast<JSHTMLTableColElement*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    lookupPut<JSHTMLTableColElement, Base>(exec, propertyName, value, JSHTMLTableColElementTable, thisObject, slot);
}

void setJSHTMLTableColElementAlign(ExecState* exec, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    JSValue value = JSValue::decode(encodedValue);
    UNUSED_PARAM(exec);
    JSHTMLTableColElement* castedThis = jsDynamicCast<JSHTMLTableColElement*>(JSValue::decode(thisValue));
    if (!castedThis) {
        throwVMTypeError(exec);
        return;
    }
    HTMLTableColElement& impl = castedThis->impl();
    const String& nativeValue(valueToStringWithNullCheck(exec, value));
    if (exec->hadException())
        return;
    impl.setAttribute(WebCore::HTMLNames::alignAttr, nativeValue);
}


void setJSHTMLTableColElementCh(ExecState* exec, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    JSValue value = JSValue::decode(encodedValue);
    UNUSED_PARAM(exec);
    JSHTMLTableColElement* castedThis = jsDynamicCast<JSHTMLTableColElement*>(JSValue::decode(thisValue));
    if (!castedThis) {
        throwVMTypeError(exec);
        return;
    }
    HTMLTableColElement& impl = castedThis->impl();
    const String& nativeValue(valueToStringWithNullCheck(exec, value));
    if (exec->hadException())
        return;
    impl.setAttribute(WebCore::HTMLNames::charAttr, nativeValue);
}


void setJSHTMLTableColElementChOff(ExecState* exec, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    JSValue value = JSValue::decode(encodedValue);
    UNUSED_PARAM(exec);
    JSHTMLTableColElement* castedThis = jsDynamicCast<JSHTMLTableColElement*>(JSValue::decode(thisValue));
    if (!castedThis) {
        throwVMTypeError(exec);
        return;
    }
    HTMLTableColElement& impl = castedThis->impl();
    const String& nativeValue(valueToStringWithNullCheck(exec, value));
    if (exec->hadException())
        return;
    impl.setAttribute(WebCore::HTMLNames::charoffAttr, nativeValue);
}


void setJSHTMLTableColElementSpan(ExecState* exec, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    JSValue value = JSValue::decode(encodedValue);
    UNUSED_PARAM(exec);
    JSHTMLTableColElement* castedThis = jsDynamicCast<JSHTMLTableColElement*>(JSValue::decode(thisValue));
    if (!castedThis) {
        throwVMTypeError(exec);
        return;
    }
    HTMLTableColElement& impl = castedThis->impl();
    int nativeValue(toInt32(exec, value, NormalConversion));
    if (exec->hadException())
        return;
    impl.setSpan(nativeValue);
}


void setJSHTMLTableColElementVAlign(ExecState* exec, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    JSValue value = JSValue::decode(encodedValue);
    UNUSED_PARAM(exec);
    JSHTMLTableColElement* castedThis = jsDynamicCast<JSHTMLTableColElement*>(JSValue::decode(thisValue));
    if (!castedThis) {
        throwVMTypeError(exec);
        return;
    }
    HTMLTableColElement& impl = castedThis->impl();
    const String& nativeValue(valueToStringWithNullCheck(exec, value));
    if (exec->hadException())
        return;
    impl.setAttribute(WebCore::HTMLNames::valignAttr, nativeValue);
}


void setJSHTMLTableColElementWidth(ExecState* exec, EncodedJSValue thisValue, EncodedJSValue encodedValue)
{
    JSValue value = JSValue::decode(encodedValue);
    UNUSED_PARAM(exec);
    JSHTMLTableColElement* castedThis = jsDynamicCast<JSHTMLTableColElement*>(JSValue::decode(thisValue));
    if (!castedThis) {
        throwVMTypeError(exec);
        return;
    }
    HTMLTableColElement& impl = castedThis->impl();
    const String& nativeValue(valueToStringWithNullCheck(exec, value));
    if (exec->hadException())
        return;
    impl.setAttribute(WebCore::HTMLNames::widthAttr, nativeValue);
}


JSValue JSHTMLTableColElement::getConstructor(VM& vm, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSHTMLTableColElementConstructor>(vm, jsCast<JSDOMGlobalObject*>(globalObject));
}


}