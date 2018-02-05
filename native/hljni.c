// This file is auto-generated, do not edit!

#define HL_NAME(n) hljni_##n
#include <hl.h>
#include <jni.h>

static JNIEnv* env;

HL_PRIM void HL_NAME(set_env)(JNIEnv* p_env) {
	env = p_env;
}

#define _JNIARGS _ABSTRACT(jvalue)
#define _JOBJECT _ABSTRACT(_jobject)

HL_PRIM jvalue* HL_NAME(args_alloc)(int count) {
	return hl_gc_alloc_noptr(sizeof(jvalue) * count);
}
DEFINE_PRIM(_JNIARGS, args_alloc, _I32);

#define DEFINE_ARGS_SET(type, letter, prim) \
	HL_PRIM void HL_NAME(args_set_##type)(jvalue* args, int pos, type value) { \
		args[pos].letter = value; \
	} \
	DEFINE_PRIM(_VOID, args_set_##type, _JNIARGS _I32 prim);

DEFINE_ARGS_SET(jboolean, z, _BOOL);
DEFINE_ARGS_SET(jbyte, b, _I8);
DEFINE_ARGS_SET(jchar, c, _I16);
DEFINE_ARGS_SET(jshort, s, _I16);
DEFINE_ARGS_SET(jint, i, _I32);
DEFINE_ARGS_SET(jlong, j, _I64);
DEFINE_ARGS_SET(jfloat, f, _F32);
DEFINE_ARGS_SET(jdouble, d, _F64);
DEFINE_ARGS_SET(jobject, l, _JOBJECT);


HL_PRIM jint HL_NAME(_get_version)() {
	return (*env)->GetVersion(env);
}
DEFINE_PRIM(_I32, _get_version, _NO_ARG);

HL_PRIM jclass HL_NAME(_define_class)(const char* name, jobject loader, const jbyte* buf, jsize bufLen) {
	return (*env)->DefineClass(env, name, loader, buf, bufLen);
}
DEFINE_PRIM(_JOBJECT, _define_class, _BYTES _JOBJECT _BYTES _I32);

HL_PRIM jclass HL_NAME(_find_class)(const char* name) {
	return (*env)->FindClass(env, name);
}
DEFINE_PRIM(_JOBJECT, _find_class, _BYTES);

HL_PRIM jclass HL_NAME(_get_superclass)(jclass clazz) {
	return (*env)->GetSuperclass(env, clazz);
}
DEFINE_PRIM(_JOBJECT, _get_superclass, _JOBJECT);

HL_PRIM jboolean HL_NAME(_is_assignable_from)(jclass clazz1, jclass clazz2) {
	return (*env)->IsAssignableFrom(env, clazz1, clazz2);
}
DEFINE_PRIM(_BOOL, _is_assignable_from, _JOBJECT _JOBJECT);

HL_PRIM jint HL_NAME(_throw)(jobject obj) {
	return (*env)->Throw(env, obj);
}
DEFINE_PRIM(_I32, _throw, _JOBJECT);

HL_PRIM jint HL_NAME(_throw_new)(jclass clazz, const char* message) {
	return (*env)->ThrowNew(env, clazz, message);
}
DEFINE_PRIM(_I32, _throw_new, _JOBJECT _BYTES);

HL_PRIM jobject HL_NAME(_exception_occurred)() {
	return (*env)->ExceptionOccurred(env);
}
DEFINE_PRIM(_JOBJECT, _exception_occurred, _NO_ARG);

HL_PRIM void HL_NAME(_exception_describe)() {
	(*env)->ExceptionDescribe(env);
}
DEFINE_PRIM(_VOID, _exception_describe, _NO_ARG);

HL_PRIM void HL_NAME(_exception_clear)() {
	(*env)->ExceptionClear(env);
}
DEFINE_PRIM(_VOID, _exception_clear, _NO_ARG);

HL_PRIM void HL_NAME(_fatal_error)(const char* msg) {
	(*env)->FatalError(env, msg);
}
DEFINE_PRIM(_VOID, _fatal_error, _BYTES);

HL_PRIM jboolean HL_NAME(_exception_check)() {
	return (*env)->ExceptionCheck(env);
}
DEFINE_PRIM(_BOOL, _exception_check, _NO_ARG);

HL_PRIM jobject HL_NAME(_new_global_ref)(jobject obj) {
	return (*env)->NewGlobalRef(env, obj);
}
DEFINE_PRIM(_JOBJECT, _new_global_ref, _JOBJECT);

HL_PRIM void HL_NAME(_delete_global_ref)(jobject globalRef) {
	(*env)->DeleteGlobalRef(env, globalRef);
}
DEFINE_PRIM(_VOID, _delete_global_ref, _JOBJECT);

HL_PRIM void HL_NAME(_delete_local_ref)(jobject localRef) {
	(*env)->DeleteLocalRef(env, localRef);
}
DEFINE_PRIM(_VOID, _delete_local_ref, _JOBJECT);

HL_PRIM jint HL_NAME(_ensure_local_capacity)(jint capacity) {
	return (*env)->EnsureLocalCapacity(env, capacity);
}
DEFINE_PRIM(_I32, _ensure_local_capacity, _I32);

HL_PRIM jint HL_NAME(_push_local_frame)(jint capacity) {
	return (*env)->PushLocalFrame(env, capacity);
}
DEFINE_PRIM(_I32, _push_local_frame, _I32);

HL_PRIM jobject HL_NAME(_pop_local_frame)(jobject result) {
	return (*env)->PopLocalFrame(env, result);
}
DEFINE_PRIM(_JOBJECT, _pop_local_frame, _JOBJECT);

HL_PRIM jobject HL_NAME(_new_local_ref)(jobject ref) {
	return (*env)->NewLocalRef(env, ref);
}
DEFINE_PRIM(_JOBJECT, _new_local_ref, _JOBJECT);

HL_PRIM jweak HL_NAME(_new_weak_global_ref)(jobject obj) {
	return (*env)->NewWeakGlobalRef(env, obj);
}
DEFINE_PRIM(_JOBJECT, _new_weak_global_ref, _JOBJECT);

HL_PRIM void HL_NAME(_delete_weak_global_ref)(jweak obj) {
	(*env)->DeleteWeakGlobalRef(env, obj);
}
DEFINE_PRIM(_VOID, _delete_weak_global_ref, _JOBJECT);

HL_PRIM jobject HL_NAME(_alloc_object)(jclass clazz) {
	return (*env)->AllocObject(env, clazz);
}
DEFINE_PRIM(_JOBJECT, _alloc_object, _JOBJECT);

HL_PRIM jobject HL_NAME(_new_object_a)(jclass clazz, jmethodID methodID, const jvalue* args) {
	return (*env)->NewObjectA(env, clazz, methodID, args);
}
DEFINE_PRIM(_JOBJECT, _new_object_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jclass HL_NAME(_get_object_class)(jobject obj) {
	return (*env)->GetObjectClass(env, obj);
}
DEFINE_PRIM(_JOBJECT, _get_object_class, _JOBJECT);

HL_PRIM jobjectRefType HL_NAME(_get_object_ref_type)(jobject obj) {
	return (*env)->GetObjectRefType(env, obj);
}
DEFINE_PRIM(_I32, _get_object_ref_type, _JOBJECT);

HL_PRIM jboolean HL_NAME(_is_instance_of)(jobject obj, jclass clazz) {
	return (*env)->IsInstanceOf(env, obj, clazz);
}
DEFINE_PRIM(_BOOL, _is_instance_of, _JOBJECT _JOBJECT);

HL_PRIM jboolean HL_NAME(_is_same_object)(jobject ref1, jobject ref2) {
	return (*env)->IsSameObject(env, ref1, ref2);
}
DEFINE_PRIM(_BOOL, _is_same_object, _JOBJECT _JOBJECT);

HL_PRIM jfieldID HL_NAME(_get_field_id)(jclass clazz, const char* name, const char* sig) {
	return (*env)->GetFieldID(env, clazz, name, sig);
}
DEFINE_PRIM(_ABSTRACT(_jfieldID), _get_field_id, _JOBJECT _BYTES _BYTES);

HL_PRIM jobject HL_NAME(_get_object_field)(jobject obj, jfieldID fieldID) {
	return (*env)->GetObjectField(env, obj, fieldID);
}
DEFINE_PRIM(_JOBJECT, _get_object_field, _JOBJECT _ABSTRACT(_jfieldID));

HL_PRIM jboolean HL_NAME(_get_boolean_field)(jobject obj, jfieldID fieldID) {
	return (*env)->GetBooleanField(env, obj, fieldID);
}
DEFINE_PRIM(_BOOL, _get_boolean_field, _JOBJECT _ABSTRACT(_jfieldID));

HL_PRIM jbyte HL_NAME(_get_byte_field)(jobject obj, jfieldID fieldID) {
	return (*env)->GetByteField(env, obj, fieldID);
}
DEFINE_PRIM(_I8, _get_byte_field, _JOBJECT _ABSTRACT(_jfieldID));

HL_PRIM jchar HL_NAME(_get_char_field)(jobject obj, jfieldID fieldID) {
	return (*env)->GetCharField(env, obj, fieldID);
}
DEFINE_PRIM(_I16, _get_char_field, _JOBJECT _ABSTRACT(_jfieldID));

HL_PRIM jshort HL_NAME(_get_short_field)(jobject obj, jfieldID fieldID) {
	return (*env)->GetShortField(env, obj, fieldID);
}
DEFINE_PRIM(_I16, _get_short_field, _JOBJECT _ABSTRACT(_jfieldID));

HL_PRIM jint HL_NAME(_get_int_field)(jobject obj, jfieldID fieldID) {
	return (*env)->GetIntField(env, obj, fieldID);
}
DEFINE_PRIM(_I32, _get_int_field, _JOBJECT _ABSTRACT(_jfieldID));

HL_PRIM jlong HL_NAME(_get_long_field)(jobject obj, jfieldID fieldID) {
	return (*env)->GetLongField(env, obj, fieldID);
}
DEFINE_PRIM(_I64, _get_long_field, _JOBJECT _ABSTRACT(_jfieldID));

HL_PRIM jfloat HL_NAME(_get_float_field)(jobject obj, jfieldID fieldID) {
	return (*env)->GetFloatField(env, obj, fieldID);
}
DEFINE_PRIM(_F32, _get_float_field, _JOBJECT _ABSTRACT(_jfieldID));

HL_PRIM jdouble HL_NAME(_get_double_field)(jobject obj, jfieldID fieldID) {
	return (*env)->GetDoubleField(env, obj, fieldID);
}
DEFINE_PRIM(_F64, _get_double_field, _JOBJECT _ABSTRACT(_jfieldID));

HL_PRIM void HL_NAME(_set_object_field)(jobject obj, jfieldID fieldID, jobject value) {
	(*env)->SetObjectField(env, obj, fieldID, value);
}
DEFINE_PRIM(_VOID, _set_object_field, _JOBJECT _ABSTRACT(_jfieldID) _JOBJECT);

HL_PRIM void HL_NAME(_set_boolean_field)(jobject obj, jfieldID fieldID, jboolean value) {
	(*env)->SetBooleanField(env, obj, fieldID, value);
}
DEFINE_PRIM(_VOID, _set_boolean_field, _JOBJECT _ABSTRACT(_jfieldID) _BOOL);

HL_PRIM void HL_NAME(_set_byte_field)(jobject obj, jfieldID fieldID, jbyte value) {
	(*env)->SetByteField(env, obj, fieldID, value);
}
DEFINE_PRIM(_VOID, _set_byte_field, _JOBJECT _ABSTRACT(_jfieldID) _I8);

HL_PRIM void HL_NAME(_set_char_field)(jobject obj, jfieldID fieldID, jchar value) {
	(*env)->SetCharField(env, obj, fieldID, value);
}
DEFINE_PRIM(_VOID, _set_char_field, _JOBJECT _ABSTRACT(_jfieldID) _I16);

HL_PRIM void HL_NAME(_set_short_field)(jobject obj, jfieldID fieldID, jshort value) {
	(*env)->SetShortField(env, obj, fieldID, value);
}
DEFINE_PRIM(_VOID, _set_short_field, _JOBJECT _ABSTRACT(_jfieldID) _I16);

HL_PRIM void HL_NAME(_set_int_field)(jobject obj, jfieldID fieldID, jint value) {
	(*env)->SetIntField(env, obj, fieldID, value);
}
DEFINE_PRIM(_VOID, _set_int_field, _JOBJECT _ABSTRACT(_jfieldID) _I32);

HL_PRIM void HL_NAME(_set_long_field)(jobject obj, jfieldID fieldID, jlong value) {
	(*env)->SetLongField(env, obj, fieldID, value);
}
DEFINE_PRIM(_VOID, _set_long_field, _JOBJECT _ABSTRACT(_jfieldID) _I64);

HL_PRIM void HL_NAME(_set_float_field)(jobject obj, jfieldID fieldID, jfloat value) {
	(*env)->SetFloatField(env, obj, fieldID, value);
}
DEFINE_PRIM(_VOID, _set_float_field, _JOBJECT _ABSTRACT(_jfieldID) _F32);

HL_PRIM void HL_NAME(_set_double_field)(jobject obj, jfieldID fieldID, jdouble value) {
	(*env)->SetDoubleField(env, obj, fieldID, value);
}
DEFINE_PRIM(_VOID, _set_double_field, _JOBJECT _ABSTRACT(_jfieldID) _F64);

HL_PRIM jmethodID HL_NAME(_get_method_id)(jclass clazz, const char* name, const char* sig) {
	return (*env)->GetMethodID(env, clazz, name, sig);
}
DEFINE_PRIM(_ABSTRACT(_jmethodID), _get_method_id, _JOBJECT _BYTES _BYTES);

HL_PRIM void HL_NAME(_call_void_method_a)(jobject obj, jmethodID methodID, const jvalue* args) {
	(*env)->CallVoidMethodA(env, obj, methodID, args);
}
DEFINE_PRIM(_VOID, _call_void_method_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jobject HL_NAME(_call_object_method_a)(jobject obj, jmethodID methodID, const jvalue* args) {
	return (*env)->CallObjectMethodA(env, obj, methodID, args);
}
DEFINE_PRIM(_JOBJECT, _call_object_method_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jboolean HL_NAME(_call_boolean_method_a)(jobject obj, jmethodID methodID, const jvalue* args) {
	return (*env)->CallBooleanMethodA(env, obj, methodID, args);
}
DEFINE_PRIM(_BOOL, _call_boolean_method_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jbyte HL_NAME(_call_byte_method_a)(jobject obj, jmethodID methodID, const jvalue* args) {
	return (*env)->CallByteMethodA(env, obj, methodID, args);
}
DEFINE_PRIM(_I8, _call_byte_method_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jchar HL_NAME(_call_char_method_a)(jobject obj, jmethodID methodID, const jvalue* args) {
	return (*env)->CallCharMethodA(env, obj, methodID, args);
}
DEFINE_PRIM(_I16, _call_char_method_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jshort HL_NAME(_call_short_method_a)(jobject obj, jmethodID methodID, const jvalue* args) {
	return (*env)->CallShortMethodA(env, obj, methodID, args);
}
DEFINE_PRIM(_I16, _call_short_method_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jint HL_NAME(_call_int_method_a)(jobject obj, jmethodID methodID, const jvalue* args) {
	return (*env)->CallIntMethodA(env, obj, methodID, args);
}
DEFINE_PRIM(_I32, _call_int_method_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jlong HL_NAME(_call_long_method_a)(jobject obj, jmethodID methodID, const jvalue* args) {
	return (*env)->CallLongMethodA(env, obj, methodID, args);
}
DEFINE_PRIM(_I64, _call_long_method_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jfloat HL_NAME(_call_float_method_a)(jobject obj, jmethodID methodID, const jvalue* args) {
	return (*env)->CallFloatMethodA(env, obj, methodID, args);
}
DEFINE_PRIM(_F32, _call_float_method_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jdouble HL_NAME(_call_double_method_a)(jobject obj, jmethodID methodID, const jvalue* args) {
	return (*env)->CallDoubleMethodA(env, obj, methodID, args);
}
DEFINE_PRIM(_F64, _call_double_method_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM void HL_NAME(_call_nonvirtual_void_method_a)(jobject obj, jclass clazz, jmethodID methodID, const jvalue* args) {
	(*env)->CallNonvirtualVoidMethodA(env, obj, clazz, methodID, args);
}
DEFINE_PRIM(_VOID, _call_nonvirtual_void_method_a, _JOBJECT _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jobject HL_NAME(_call_nonvirtual_object_method_a)(jobject obj, jclass clazz, jmethodID methodID, const jvalue* args) {
	return (*env)->CallNonvirtualObjectMethodA(env, obj, clazz, methodID, args);
}
DEFINE_PRIM(_JOBJECT, _call_nonvirtual_object_method_a, _JOBJECT _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jboolean HL_NAME(_call_nonvirtual_boolean_method_a)(jobject obj, jclass clazz, jmethodID methodID, const jvalue* args) {
	return (*env)->CallNonvirtualBooleanMethodA(env, obj, clazz, methodID, args);
}
DEFINE_PRIM(_BOOL, _call_nonvirtual_boolean_method_a, _JOBJECT _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jbyte HL_NAME(_call_nonvirtual_byte_method_a)(jobject obj, jclass clazz, jmethodID methodID, const jvalue* args) {
	return (*env)->CallNonvirtualByteMethodA(env, obj, clazz, methodID, args);
}
DEFINE_PRIM(_I8, _call_nonvirtual_byte_method_a, _JOBJECT _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jchar HL_NAME(_call_nonvirtual_char_method_a)(jobject obj, jclass clazz, jmethodID methodID, const jvalue* args) {
	return (*env)->CallNonvirtualCharMethodA(env, obj, clazz, methodID, args);
}
DEFINE_PRIM(_I16, _call_nonvirtual_char_method_a, _JOBJECT _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jshort HL_NAME(_call_nonvirtual_short_method_a)(jobject obj, jclass clazz, jmethodID methodID, const jvalue* args) {
	return (*env)->CallNonvirtualShortMethodA(env, obj, clazz, methodID, args);
}
DEFINE_PRIM(_I16, _call_nonvirtual_short_method_a, _JOBJECT _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jint HL_NAME(_call_nonvirtual_int_method_a)(jobject obj, jclass clazz, jmethodID methodID, const jvalue* args) {
	return (*env)->CallNonvirtualIntMethodA(env, obj, clazz, methodID, args);
}
DEFINE_PRIM(_I32, _call_nonvirtual_int_method_a, _JOBJECT _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jlong HL_NAME(_call_nonvirtual_long_method_a)(jobject obj, jclass clazz, jmethodID methodID, const jvalue* args) {
	return (*env)->CallNonvirtualLongMethodA(env, obj, clazz, methodID, args);
}
DEFINE_PRIM(_I64, _call_nonvirtual_long_method_a, _JOBJECT _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jfloat HL_NAME(_call_nonvirtual_float_method_a)(jobject obj, jclass clazz, jmethodID methodID, const jvalue* args) {
	return (*env)->CallNonvirtualFloatMethodA(env, obj, clazz, methodID, args);
}
DEFINE_PRIM(_F32, _call_nonvirtual_float_method_a, _JOBJECT _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jdouble HL_NAME(_call_nonvirtual_double_method_a)(jobject obj, jclass clazz, jmethodID methodID, const jvalue* args) {
	return (*env)->CallNonvirtualDoubleMethodA(env, obj, clazz, methodID, args);
}
DEFINE_PRIM(_F64, _call_nonvirtual_double_method_a, _JOBJECT _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jfieldID HL_NAME(_get_static_field_id)(jclass clazz, const char* name, const char* sig) {
	return (*env)->GetStaticFieldID(env, clazz, name, sig);
}
DEFINE_PRIM(_ABSTRACT(_jfieldID), _get_static_field_id, _JOBJECT _BYTES _BYTES);

HL_PRIM jobject HL_NAME(_get_static_object_field)(jclass obj, jfieldID fieldID) {
	return (*env)->GetStaticObjectField(env, obj, fieldID);
}
DEFINE_PRIM(_JOBJECT, _get_static_object_field, _JOBJECT _ABSTRACT(_jfieldID));

HL_PRIM jboolean HL_NAME(_get_static_boolean_field)(jclass obj, jfieldID fieldID) {
	return (*env)->GetStaticBooleanField(env, obj, fieldID);
}
DEFINE_PRIM(_BOOL, _get_static_boolean_field, _JOBJECT _ABSTRACT(_jfieldID));

HL_PRIM jbyte HL_NAME(_get_static_byte_field)(jclass obj, jfieldID fieldID) {
	return (*env)->GetStaticByteField(env, obj, fieldID);
}
DEFINE_PRIM(_I8, _get_static_byte_field, _JOBJECT _ABSTRACT(_jfieldID));

HL_PRIM jchar HL_NAME(_get_static_char_field)(jclass obj, jfieldID fieldID) {
	return (*env)->GetStaticCharField(env, obj, fieldID);
}
DEFINE_PRIM(_I16, _get_static_char_field, _JOBJECT _ABSTRACT(_jfieldID));

HL_PRIM jshort HL_NAME(_get_static_short_field)(jclass obj, jfieldID fieldID) {
	return (*env)->GetStaticShortField(env, obj, fieldID);
}
DEFINE_PRIM(_I16, _get_static_short_field, _JOBJECT _ABSTRACT(_jfieldID));

HL_PRIM jint HL_NAME(_get_static_int_field)(jclass obj, jfieldID fieldID) {
	return (*env)->GetStaticIntField(env, obj, fieldID);
}
DEFINE_PRIM(_I32, _get_static_int_field, _JOBJECT _ABSTRACT(_jfieldID));

HL_PRIM jlong HL_NAME(_get_static_long_field)(jclass obj, jfieldID fieldID) {
	return (*env)->GetStaticLongField(env, obj, fieldID);
}
DEFINE_PRIM(_I64, _get_static_long_field, _JOBJECT _ABSTRACT(_jfieldID));

HL_PRIM jfloat HL_NAME(_get_static_float_field)(jclass obj, jfieldID fieldID) {
	return (*env)->GetStaticFloatField(env, obj, fieldID);
}
DEFINE_PRIM(_F32, _get_static_float_field, _JOBJECT _ABSTRACT(_jfieldID));

HL_PRIM jdouble HL_NAME(_get_static_double_field)(jclass obj, jfieldID fieldID) {
	return (*env)->GetStaticDoubleField(env, obj, fieldID);
}
DEFINE_PRIM(_F64, _get_static_double_field, _JOBJECT _ABSTRACT(_jfieldID));

HL_PRIM void HL_NAME(_set_static_object_field)(jclass obj, jfieldID fieldID, jobject value) {
	(*env)->SetStaticObjectField(env, obj, fieldID, value);
}
DEFINE_PRIM(_VOID, _set_static_object_field, _JOBJECT _ABSTRACT(_jfieldID) _JOBJECT);

HL_PRIM void HL_NAME(_set_static_boolean_field)(jclass obj, jfieldID fieldID, jboolean value) {
	(*env)->SetStaticBooleanField(env, obj, fieldID, value);
}
DEFINE_PRIM(_VOID, _set_static_boolean_field, _JOBJECT _ABSTRACT(_jfieldID) _BOOL);

HL_PRIM void HL_NAME(_set_static_byte_field)(jclass obj, jfieldID fieldID, jbyte value) {
	(*env)->SetStaticByteField(env, obj, fieldID, value);
}
DEFINE_PRIM(_VOID, _set_static_byte_field, _JOBJECT _ABSTRACT(_jfieldID) _I8);

HL_PRIM void HL_NAME(_set_static_char_field)(jclass obj, jfieldID fieldID, jchar value) {
	(*env)->SetStaticCharField(env, obj, fieldID, value);
}
DEFINE_PRIM(_VOID, _set_static_char_field, _JOBJECT _ABSTRACT(_jfieldID) _I16);

HL_PRIM void HL_NAME(_set_static_short_field)(jclass obj, jfieldID fieldID, jshort value) {
	(*env)->SetStaticShortField(env, obj, fieldID, value);
}
DEFINE_PRIM(_VOID, _set_static_short_field, _JOBJECT _ABSTRACT(_jfieldID) _I16);

HL_PRIM void HL_NAME(_set_static_int_field)(jclass obj, jfieldID fieldID, jint value) {
	(*env)->SetStaticIntField(env, obj, fieldID, value);
}
DEFINE_PRIM(_VOID, _set_static_int_field, _JOBJECT _ABSTRACT(_jfieldID) _I32);

HL_PRIM void HL_NAME(_set_static_long_field)(jclass obj, jfieldID fieldID, jlong value) {
	(*env)->SetStaticLongField(env, obj, fieldID, value);
}
DEFINE_PRIM(_VOID, _set_static_long_field, _JOBJECT _ABSTRACT(_jfieldID) _I64);

HL_PRIM void HL_NAME(_set_static_float_field)(jclass obj, jfieldID fieldID, jfloat value) {
	(*env)->SetStaticFloatField(env, obj, fieldID, value);
}
DEFINE_PRIM(_VOID, _set_static_float_field, _JOBJECT _ABSTRACT(_jfieldID) _F32);

HL_PRIM void HL_NAME(_set_static_double_field)(jclass obj, jfieldID fieldID, jdouble value) {
	(*env)->SetStaticDoubleField(env, obj, fieldID, value);
}
DEFINE_PRIM(_VOID, _set_static_double_field, _JOBJECT _ABSTRACT(_jfieldID) _F64);

HL_PRIM jmethodID HL_NAME(_get_static_method_id)(jclass clazz, const char* name, const char* sig) {
	return (*env)->GetStaticMethodID(env, clazz, name, sig);
}
DEFINE_PRIM(_ABSTRACT(_jmethodID), _get_static_method_id, _JOBJECT _BYTES _BYTES);

HL_PRIM void HL_NAME(_call_static_void_method_a)(jclass clazz, jmethodID methodID, const jvalue* args) {
	(*env)->CallStaticVoidMethodA(env, clazz, methodID, args);
}
DEFINE_PRIM(_VOID, _call_static_void_method_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jobject HL_NAME(_call_static_object_method_a)(jclass clazz, jmethodID methodID, const jvalue* args) {
	return (*env)->CallStaticObjectMethodA(env, clazz, methodID, args);
}
DEFINE_PRIM(_JOBJECT, _call_static_object_method_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jboolean HL_NAME(_call_static_boolean_method_a)(jclass clazz, jmethodID methodID, const jvalue* args) {
	return (*env)->CallStaticBooleanMethodA(env, clazz, methodID, args);
}
DEFINE_PRIM(_BOOL, _call_static_boolean_method_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jbyte HL_NAME(_call_static_byte_method_a)(jclass clazz, jmethodID methodID, const jvalue* args) {
	return (*env)->CallStaticByteMethodA(env, clazz, methodID, args);
}
DEFINE_PRIM(_I8, _call_static_byte_method_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jchar HL_NAME(_call_static_char_method_a)(jclass clazz, jmethodID methodID, const jvalue* args) {
	return (*env)->CallStaticCharMethodA(env, clazz, methodID, args);
}
DEFINE_PRIM(_I16, _call_static_char_method_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jshort HL_NAME(_call_static_short_method_a)(jclass clazz, jmethodID methodID, const jvalue* args) {
	return (*env)->CallStaticShortMethodA(env, clazz, methodID, args);
}
DEFINE_PRIM(_I16, _call_static_short_method_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jint HL_NAME(_call_static_int_method_a)(jclass clazz, jmethodID methodID, const jvalue* args) {
	return (*env)->CallStaticIntMethodA(env, clazz, methodID, args);
}
DEFINE_PRIM(_I32, _call_static_int_method_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jlong HL_NAME(_call_static_long_method_a)(jclass clazz, jmethodID methodID, const jvalue* args) {
	return (*env)->CallStaticLongMethodA(env, clazz, methodID, args);
}
DEFINE_PRIM(_I64, _call_static_long_method_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jfloat HL_NAME(_call_static_float_method_a)(jclass clazz, jmethodID methodID, const jvalue* args) {
	return (*env)->CallStaticFloatMethodA(env, clazz, methodID, args);
}
DEFINE_PRIM(_F32, _call_static_float_method_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jdouble HL_NAME(_call_static_double_method_a)(jclass clazz, jmethodID methodID, const jvalue* args) {
	return (*env)->CallStaticDoubleMethodA(env, clazz, methodID, args);
}
DEFINE_PRIM(_F64, _call_static_double_method_a, _JOBJECT _ABSTRACT(_jmethodID) _JNIARGS);

HL_PRIM jstring HL_NAME(_new_string)(const jchar* unicodeChars, jsize len) {
	return (*env)->NewString(env, unicodeChars, len);
}
DEFINE_PRIM(_JOBJECT, _new_string, _BYTES _I32);

HL_PRIM jsize HL_NAME(_get_string_length)(jstring string) {
	return (*env)->GetStringLength(env, string);
}
DEFINE_PRIM(_I32, _get_string_length, _JOBJECT);

HL_PRIM const jchar* HL_NAME(_get_string_chars)(jstring string, jboolean* isCopy) {
	return (*env)->GetStringChars(env, string, isCopy);
}
DEFINE_PRIM(_BYTES, _get_string_chars, _JOBJECT _REF(_BOOL));

HL_PRIM void HL_NAME(_release_string_chars)(jstring string, const jchar* chars) {
	(*env)->ReleaseStringChars(env, string, chars);
}
DEFINE_PRIM(_VOID, _release_string_chars, _JOBJECT _BYTES);

HL_PRIM jstring HL_NAME(_new_string_utf)(const char* bytes) {
	return (*env)->NewStringUTF(env, bytes);
}
DEFINE_PRIM(_JOBJECT, _new_string_utf, _BYTES);

HL_PRIM jsize HL_NAME(_get_string_utflength)(jstring string) {
	return (*env)->GetStringUTFLength(env, string);
}
DEFINE_PRIM(_I32, _get_string_utflength, _JOBJECT);

HL_PRIM const char* HL_NAME(_get_string_utfchars)(jstring string, jboolean* isCopy) {
	return (*env)->GetStringUTFChars(env, string, isCopy);
}
DEFINE_PRIM(_BYTES, _get_string_utfchars, _JOBJECT _REF(_BOOL));

HL_PRIM void HL_NAME(_release_string_utfchars)(jstring string, const char* utf) {
	(*env)->ReleaseStringUTFChars(env, string, utf);
}
DEFINE_PRIM(_VOID, _release_string_utfchars, _JOBJECT _BYTES);

HL_PRIM void HL_NAME(_get_string_region)(jstring str, jsize start, jsize len, jchar* buf) {
	(*env)->GetStringRegion(env, str, start, len, buf);
}
DEFINE_PRIM(_VOID, _get_string_region, _JOBJECT _I32 _I32 _BYTES);

HL_PRIM void HL_NAME(_get_string_utfregion)(jstring str, jsize start, jsize len, char* buf) {
	(*env)->GetStringUTFRegion(env, str, start, len, buf);
}
DEFINE_PRIM(_VOID, _get_string_utfregion, _JOBJECT _I32 _I32 _BYTES);

HL_PRIM const jchar* HL_NAME(_get_string_critical)(jstring string, jboolean* isCopy) {
	return (*env)->GetStringCritical(env, string, isCopy);
}
DEFINE_PRIM(_BYTES, _get_string_critical, _JOBJECT _REF(_BOOL));

HL_PRIM void HL_NAME(_release_string_critical)(jstring string, const jchar* carray) {
	(*env)->ReleaseStringCritical(env, string, carray);
}
DEFINE_PRIM(_VOID, _release_string_critical, _JOBJECT _BYTES);

HL_PRIM jsize HL_NAME(_get_array_length)(jarray array) {
	return (*env)->GetArrayLength(env, array);
}
DEFINE_PRIM(_I32, _get_array_length, _JOBJECT);

HL_PRIM jobjectArray HL_NAME(_new_object_array)(jsize length, jclass elementClass, jobject initialElement) {
	return (*env)->NewObjectArray(env, length, elementClass, initialElement);
}
DEFINE_PRIM(_JOBJECT, _new_object_array, _I32 _JOBJECT _JOBJECT);

HL_PRIM jobject HL_NAME(_get_object_array_element)(jobjectArray array, jsize index) {
	return (*env)->GetObjectArrayElement(env, array, index);
}
DEFINE_PRIM(_JOBJECT, _get_object_array_element, _JOBJECT _I32);

HL_PRIM void HL_NAME(_set_object_array_element)(jobjectArray array, jsize index, jobject value) {
	(*env)->SetObjectArrayElement(env, array, index, value);
}
DEFINE_PRIM(_VOID, _set_object_array_element, _JOBJECT _I32 _JOBJECT);

HL_PRIM jbooleanArray HL_NAME(_new_boolean_array)(jsize length) {
	return (*env)->NewBooleanArray(env, length);
}
DEFINE_PRIM(_JOBJECT, _new_boolean_array, _I32);

HL_PRIM jbyteArray HL_NAME(_new_byte_array)(jsize length) {
	return (*env)->NewByteArray(env, length);
}
DEFINE_PRIM(_JOBJECT, _new_byte_array, _I32);

HL_PRIM jcharArray HL_NAME(_new_char_array)(jsize length) {
	return (*env)->NewCharArray(env, length);
}
DEFINE_PRIM(_JOBJECT, _new_char_array, _I32);

HL_PRIM jshortArray HL_NAME(_new_short_array)(jsize length) {
	return (*env)->NewShortArray(env, length);
}
DEFINE_PRIM(_JOBJECT, _new_short_array, _I32);

HL_PRIM jintArray HL_NAME(_new_int_array)(jsize length) {
	return (*env)->NewIntArray(env, length);
}
DEFINE_PRIM(_JOBJECT, _new_int_array, _I32);

HL_PRIM jlongArray HL_NAME(_new_long_array)(jsize length) {
	return (*env)->NewLongArray(env, length);
}
DEFINE_PRIM(_JOBJECT, _new_long_array, _I32);

HL_PRIM jfloatArray HL_NAME(_new_float_array)(jsize length) {
	return (*env)->NewFloatArray(env, length);
}
DEFINE_PRIM(_JOBJECT, _new_float_array, _I32);

HL_PRIM jdoubleArray HL_NAME(_new_double_array)(jsize length) {
	return (*env)->NewDoubleArray(env, length);
}
DEFINE_PRIM(_JOBJECT, _new_double_array, _I32);

HL_PRIM jboolean* HL_NAME(_get_boolean_array_elements)(jbooleanArray array, jboolean* isCopy) {
	return (*env)->GetBooleanArrayElements(env, array, isCopy);
}
DEFINE_PRIM(_BYTES, _get_boolean_array_elements, _JOBJECT _REF(_BOOL));

HL_PRIM jbyte* HL_NAME(_get_byte_array_elements)(jbyteArray array, jboolean* isCopy) {
	return (*env)->GetByteArrayElements(env, array, isCopy);
}
DEFINE_PRIM(_BYTES, _get_byte_array_elements, _JOBJECT _REF(_BOOL));

HL_PRIM jchar* HL_NAME(_get_char_array_elements)(jcharArray array, jboolean* isCopy) {
	return (*env)->GetCharArrayElements(env, array, isCopy);
}
DEFINE_PRIM(_BYTES, _get_char_array_elements, _JOBJECT _REF(_BOOL));

HL_PRIM jshort* HL_NAME(_get_short_array_elements)(jshortArray array, jboolean* isCopy) {
	return (*env)->GetShortArrayElements(env, array, isCopy);
}
DEFINE_PRIM(_BYTES, _get_short_array_elements, _JOBJECT _REF(_BOOL));

HL_PRIM jint* HL_NAME(_get_int_array_elements)(jintArray array, jboolean* isCopy) {
	return (*env)->GetIntArrayElements(env, array, isCopy);
}
DEFINE_PRIM(_BYTES, _get_int_array_elements, _JOBJECT _REF(_BOOL));

HL_PRIM jlong* HL_NAME(_get_long_array_elements)(jlongArray array, jboolean* isCopy) {
	return (*env)->GetLongArrayElements(env, array, isCopy);
}
DEFINE_PRIM(_BYTES, _get_long_array_elements, _JOBJECT _REF(_BOOL));

HL_PRIM jfloat* HL_NAME(_get_float_array_elements)(jfloatArray array, jboolean* isCopy) {
	return (*env)->GetFloatArrayElements(env, array, isCopy);
}
DEFINE_PRIM(_BYTES, _get_float_array_elements, _JOBJECT _REF(_BOOL));

HL_PRIM jdouble* HL_NAME(_get_double_array_elements)(jdoubleArray array, jboolean* isCopy) {
	return (*env)->GetDoubleArrayElements(env, array, isCopy);
}
DEFINE_PRIM(_BYTES, _get_double_array_elements, _JOBJECT _REF(_BOOL));

HL_PRIM void HL_NAME(_release_boolean_array_elements)(jbooleanArray array, jboolean* elems, jint mode) {
	(*env)->ReleaseBooleanArrayElements(env, array, elems, mode);
}
DEFINE_PRIM(_VOID, _release_boolean_array_elements, _JOBJECT _BYTES _I32);

HL_PRIM void HL_NAME(_release_byte_array_elements)(jbyteArray array, jbyte* elems, jint mode) {
	(*env)->ReleaseByteArrayElements(env, array, elems, mode);
}
DEFINE_PRIM(_VOID, _release_byte_array_elements, _JOBJECT _BYTES _I32);

HL_PRIM void HL_NAME(_release_char_array_elements)(jcharArray array, jchar* elems, jint mode) {
	(*env)->ReleaseCharArrayElements(env, array, elems, mode);
}
DEFINE_PRIM(_VOID, _release_char_array_elements, _JOBJECT _BYTES _I32);

HL_PRIM void HL_NAME(_release_short_array_elements)(jshortArray array, jshort* elems, jint mode) {
	(*env)->ReleaseShortArrayElements(env, array, elems, mode);
}
DEFINE_PRIM(_VOID, _release_short_array_elements, _JOBJECT _BYTES _I32);

HL_PRIM void HL_NAME(_release_int_array_elements)(jintArray array, jint* elems, jint mode) {
	(*env)->ReleaseIntArrayElements(env, array, elems, mode);
}
DEFINE_PRIM(_VOID, _release_int_array_elements, _JOBJECT _BYTES _I32);

HL_PRIM void HL_NAME(_release_long_array_elements)(jlongArray array, jlong* elems, jint mode) {
	(*env)->ReleaseLongArrayElements(env, array, elems, mode);
}
DEFINE_PRIM(_VOID, _release_long_array_elements, _JOBJECT _BYTES _I32);

HL_PRIM void HL_NAME(_release_float_array_elements)(jfloatArray array, jfloat* elems, jint mode) {
	(*env)->ReleaseFloatArrayElements(env, array, elems, mode);
}
DEFINE_PRIM(_VOID, _release_float_array_elements, _JOBJECT _BYTES _I32);

HL_PRIM void HL_NAME(_release_double_array_elements)(jdoubleArray array, jdouble* elems, jint mode) {
	(*env)->ReleaseDoubleArrayElements(env, array, elems, mode);
}
DEFINE_PRIM(_VOID, _release_double_array_elements, _JOBJECT _BYTES _I32);

HL_PRIM void HL_NAME(_get_boolean_array_region)(jbooleanArray array, jsize start, jsize len, jboolean* buf) {
	(*env)->GetBooleanArrayRegion(env, array, start, len, buf);
}
DEFINE_PRIM(_VOID, _get_boolean_array_region, _JOBJECT _I32 _I32 _BYTES);

HL_PRIM void HL_NAME(_get_byte_array_region)(jbyteArray array, jsize start, jsize len, jbyte* buf) {
	(*env)->GetByteArrayRegion(env, array, start, len, buf);
}
DEFINE_PRIM(_VOID, _get_byte_array_region, _JOBJECT _I32 _I32 _BYTES);

HL_PRIM void HL_NAME(_get_char_array_region)(jcharArray array, jsize start, jsize len, jchar* buf) {
	(*env)->GetCharArrayRegion(env, array, start, len, buf);
}
DEFINE_PRIM(_VOID, _get_char_array_region, _JOBJECT _I32 _I32 _BYTES);

HL_PRIM void HL_NAME(_get_short_array_region)(jshortArray array, jsize start, jsize len, jshort* buf) {
	(*env)->GetShortArrayRegion(env, array, start, len, buf);
}
DEFINE_PRIM(_VOID, _get_short_array_region, _JOBJECT _I32 _I32 _BYTES);

HL_PRIM void HL_NAME(_get_int_array_region)(jintArray array, jsize start, jsize len, jint* buf) {
	(*env)->GetIntArrayRegion(env, array, start, len, buf);
}
DEFINE_PRIM(_VOID, _get_int_array_region, _JOBJECT _I32 _I32 _BYTES);

HL_PRIM void HL_NAME(_get_long_array_region)(jlongArray array, jsize start, jsize len, jlong* buf) {
	(*env)->GetLongArrayRegion(env, array, start, len, buf);
}
DEFINE_PRIM(_VOID, _get_long_array_region, _JOBJECT _I32 _I32 _BYTES);

HL_PRIM void HL_NAME(_get_float_array_region)(jfloatArray array, jsize start, jsize len, jfloat* buf) {
	(*env)->GetFloatArrayRegion(env, array, start, len, buf);
}
DEFINE_PRIM(_VOID, _get_float_array_region, _JOBJECT _I32 _I32 _BYTES);

HL_PRIM void HL_NAME(_get_double_array_region)(jdoubleArray array, jsize start, jsize len, jdouble* buf) {
	(*env)->GetDoubleArrayRegion(env, array, start, len, buf);
}
DEFINE_PRIM(_VOID, _get_double_array_region, _JOBJECT _I32 _I32 _BYTES);

HL_PRIM void HL_NAME(_set_boolean_array_region)(jbooleanArray array, jsize start, jsize len, jboolean* buf) {
	(*env)->SetBooleanArrayRegion(env, array, start, len, buf);
}
DEFINE_PRIM(_VOID, _set_boolean_array_region, _JOBJECT _I32 _I32 _BYTES);

HL_PRIM void HL_NAME(_set_byte_array_region)(jbyteArray array, jsize start, jsize len, jbyte* buf) {
	(*env)->SetByteArrayRegion(env, array, start, len, buf);
}
DEFINE_PRIM(_VOID, _set_byte_array_region, _JOBJECT _I32 _I32 _BYTES);

HL_PRIM void HL_NAME(_set_char_array_region)(jcharArray array, jsize start, jsize len, jchar* buf) {
	(*env)->SetCharArrayRegion(env, array, start, len, buf);
}
DEFINE_PRIM(_VOID, _set_char_array_region, _JOBJECT _I32 _I32 _BYTES);

HL_PRIM void HL_NAME(_set_short_array_region)(jshortArray array, jsize start, jsize len, jshort* buf) {
	(*env)->SetShortArrayRegion(env, array, start, len, buf);
}
DEFINE_PRIM(_VOID, _set_short_array_region, _JOBJECT _I32 _I32 _BYTES);

HL_PRIM void HL_NAME(_set_int_array_region)(jintArray array, jsize start, jsize len, jint* buf) {
	(*env)->SetIntArrayRegion(env, array, start, len, buf);
}
DEFINE_PRIM(_VOID, _set_int_array_region, _JOBJECT _I32 _I32 _BYTES);

HL_PRIM void HL_NAME(_set_long_array_region)(jlongArray array, jsize start, jsize len, jlong* buf) {
	(*env)->SetLongArrayRegion(env, array, start, len, buf);
}
DEFINE_PRIM(_VOID, _set_long_array_region, _JOBJECT _I32 _I32 _BYTES);

HL_PRIM void HL_NAME(_set_float_array_region)(jfloatArray array, jsize start, jsize len, jfloat* buf) {
	(*env)->SetFloatArrayRegion(env, array, start, len, buf);
}
DEFINE_PRIM(_VOID, _set_float_array_region, _JOBJECT _I32 _I32 _BYTES);

HL_PRIM void HL_NAME(_set_double_array_region)(jdoubleArray array, jsize start, jsize len, jdouble* buf) {
	(*env)->SetDoubleArrayRegion(env, array, start, len, buf);
}
DEFINE_PRIM(_VOID, _set_double_array_region, _JOBJECT _I32 _I32 _BYTES);

HL_PRIM char* HL_NAME(_get_primitive_array_critical)(jarray array, jboolean* isCopy) {
	return (*env)->GetPrimitiveArrayCritical(env, array, isCopy);
}
DEFINE_PRIM(_BYTES, _get_primitive_array_critical, _JOBJECT _REF(_BOOL));

HL_PRIM void HL_NAME(_release_primitive_array_critical)(jarray array, char* carray, jint mode) {
	(*env)->ReleasePrimitiveArrayCritical(env, array, carray, mode);
}
DEFINE_PRIM(_VOID, _release_primitive_array_critical, _JOBJECT _BYTES _I32);