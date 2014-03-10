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

#if ENABLE(DEVICE_ORIENTATION)

#include "JSDeviceOrientationEvent.h"

#include "DeviceOrientationEvent.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

/* Hash table */

static const HashTableValue JSDeviceOrientationEventTableValues[] =
{
    { "alpha", DontDelete | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsDeviceOrientationEventAlpha), (intptr_t)0 },
    { "beta", DontDelete | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsDeviceOrientationEventBeta), (intptr_t)0 },
    { "gamma", DontDelete | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsDeviceOrientationEventGamma), (intptr_t)0 },
    { "absolute", DontDelete | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsDeviceOrientationEventAbsolute), (intptr_t)0 },
    { "constructor", DontEnum | ReadOnly, NoIntrinsic, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsDeviceOrientationEventConstructor), (intptr_t)0 },
    { 0, 0, NoIntrinsic, 0, 0 }
};

static const HashTable JSDeviceOrientationEventTable = { 16, 15, JSDeviceOrientationEventTableValues, 0 };
/* Hash table for constructor */

static const HashTableValue JSDeviceOrientationEventConstructorTableValues[] =
{
    { 0, 0, NoIntrinsic, 0, 0 }
};

static const HashTable JSDeviceOrientationEventConstructorTable = { 1, 0, JSDeviceOrientationEventConstructorTableValues, 0 };
const ClassInfo JSDeviceOrientationEventConstructor::s_info = { "DeviceOrientationEventConstructor", &Base::s_info, &JSDeviceOrientationEventConstructorTable, 0, CREATE_METHOD_TABLE(JSDeviceOrientationEventConstructor) };

JSDeviceOrientationEventConstructor::JSDeviceOrientationEventConstructor(Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
}

void JSDeviceOrientationEventConstructor::finishCreation(VM& vm, JSDOMGlobalObject* globalObject)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));
    putDirect(vm, vm.propertyNames->prototype, JSDeviceOrientationEventPrototype::self(vm, globalObject), DontDelete | ReadOnly);
    putDirect(vm, vm.propertyNames->length, jsNumber(0), ReadOnly | DontDelete | DontEnum);
}

bool JSDeviceOrientationEventConstructor::getOwnPropertySlot(JSObject* object, ExecState* exec, PropertyName propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSDeviceOrientationEventConstructor, JSDOMWrapper>(exec, JSDeviceOrientationEventConstructorTable, jsCast<JSDeviceOrientationEventConstructor*>(object), propertyName, slot);
}

/* Hash table for prototype */

static const HashTableValue JSDeviceOrientationEventPrototypeTableValues[] =
{
    { "initDeviceOrientationEvent", JSC::Function, NoIntrinsic, (intptr_t)static_cast<NativeFunction>(jsDeviceOrientationEventPrototypeFunctionInitDeviceOrientationEvent), (intptr_t)0 },
    { 0, 0, NoIntrinsic, 0, 0 }
};

static const HashTable JSDeviceOrientationEventPrototypeTable = { 2, 1, JSDeviceOrientationEventPrototypeTableValues, 0 };
const ClassInfo JSDeviceOrientationEventPrototype::s_info = { "DeviceOrientationEventPrototype", &Base::s_info, &JSDeviceOrientationEventPrototypeTable, 0, CREATE_METHOD_TABLE(JSDeviceOrientationEventPrototype) };

JSObject* JSDeviceOrientationEventPrototype::self(VM& vm, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSDeviceOrientationEvent>(vm, globalObject);
}

bool JSDeviceOrientationEventPrototype::getOwnPropertySlot(JSObject* object, ExecState* exec, PropertyName propertyName, PropertySlot& slot)
{
    JSDeviceOrientationEventPrototype* thisObject = jsCast<JSDeviceOrientationEventPrototype*>(object);
    return getStaticFunctionSlot<JSObject>(exec, JSDeviceOrientationEventPrototypeTable, thisObject, propertyName, slot);
}

const ClassInfo JSDeviceOrientationEvent::s_info = { "DeviceOrientationEvent", &Base::s_info, &JSDeviceOrientationEventTable, 0 , CREATE_METHOD_TABLE(JSDeviceOrientationEvent) };

JSDeviceOrientationEvent::JSDeviceOrientationEvent(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<DeviceOrientationEvent> impl)
    : JSEvent(structure, globalObject, impl)
{
}

void JSDeviceOrientationEvent::finishCreation(VM& vm)
{
    Base::finishCreation(vm);
    ASSERT(inherits(info()));
}

JSObject* JSDeviceOrientationEvent::createPrototype(VM& vm, JSGlobalObject* globalObject)
{
    return JSDeviceOrientationEventPrototype::create(vm, globalObject, JSDeviceOrientationEventPrototype::createStructure(vm, globalObject, JSEventPrototype::self(vm, globalObject)));
}

bool JSDeviceOrientationEvent::getOwnPropertySlot(JSObject* object, ExecState* exec, PropertyName propertyName, PropertySlot& slot)
{
    JSDeviceOrientationEvent* thisObject = jsCast<JSDeviceOrientationEvent*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, info());
    return getStaticValueSlot<JSDeviceOrientationEvent, Base>(exec, JSDeviceOrientationEventTable, thisObject, propertyName, slot);
}

EncodedJSValue jsDeviceOrientationEventAlpha(ExecState* exec, EncodedJSValue slotBase, EncodedJSValue thisValue, PropertyName)
{
    JSDeviceOrientationEvent* castedThis = jsDynamicCast<JSDeviceOrientationEvent*>(JSValue::decode(thisValue));
    UNUSED_PARAM(slotBase);
    if (!castedThis)
        return throwVMTypeError(exec);
    return JSValue::encode(castedThis->alpha(exec));
}


EncodedJSValue jsDeviceOrientationEventBeta(ExecState* exec, EncodedJSValue slotBase, EncodedJSValue thisValue, PropertyName)
{
    JSDeviceOrientationEvent* castedThis = jsDynamicCast<JSDeviceOrientationEvent*>(JSValue::decode(thisValue));
    UNUSED_PARAM(slotBase);
    if (!castedThis)
        return throwVMTypeError(exec);
    return JSValue::encode(castedThis->beta(exec));
}


EncodedJSValue jsDeviceOrientationEventGamma(ExecState* exec, EncodedJSValue slotBase, EncodedJSValue thisValue, PropertyName)
{
    JSDeviceOrientationEvent* castedThis = jsDynamicCast<JSDeviceOrientationEvent*>(JSValue::decode(thisValue));
    UNUSED_PARAM(slotBase);
    if (!castedThis)
        return throwVMTypeError(exec);
    return JSValue::encode(castedThis->gamma(exec));
}


EncodedJSValue jsDeviceOrientationEventAbsolute(ExecState* exec, EncodedJSValue slotBase, EncodedJSValue thisValue, PropertyName)
{
    JSDeviceOrientationEvent* castedThis = jsDynamicCast<JSDeviceOrientationEvent*>(JSValue::decode(thisValue));
    UNUSED_PARAM(slotBase);
    if (!castedThis)
        return throwVMTypeError(exec);
    return JSValue::encode(castedThis->absolute(exec));
}


EncodedJSValue jsDeviceOrientationEventConstructor(ExecState* exec, EncodedJSValue thisValue, EncodedJSValue, PropertyName)
{
    JSDeviceOrientationEvent* domObject = jsDynamicCast<JSDeviceOrientationEvent*>(JSValue::decode(thisValue));
    if (!domObject)
        return throwVMTypeError(exec);
    if (!domObject)
        return throwVMTypeError(exec);
    return JSValue::encode(JSDeviceOrientationEvent::getConstructor(exec->vm(), domObject->globalObject()));
}

JSValue JSDeviceOrientationEvent::getConstructor(VM& vm, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSDeviceOrientationEventConstructor>(vm, jsCast<JSDOMGlobalObject*>(globalObject));
}

EncodedJSValue JSC_HOST_CALL jsDeviceOrientationEventPrototypeFunctionInitDeviceOrientationEvent(ExecState* exec)
{
    JSValue thisValue = exec->hostThisValue();
    JSDeviceOrientationEvent* castedThis = jsDynamicCast<JSDeviceOrientationEvent*>(thisValue);
    if (!castedThis)
        return throwVMTypeError(exec);
    ASSERT_GC_OBJECT_INHERITS(castedThis, JSDeviceOrientationEvent::info());
    return JSValue::encode(castedThis->initDeviceOrientationEvent(exec));
}


}

#endif // ENABLE(DEVICE_ORIENTATION)