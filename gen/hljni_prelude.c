#define HL_NAME(n) hljni_##n
#include <hl.h>
#include <jni.h>

#define _JNIENV _ABSTRACT(JNIEnv)
#define _JNIARGS _ABSTRACT(jvalue)
#define _JNATIVEMETHODS _ABSTRACT(JNINativeMethod)
#define _JOBJECT _ABSTRACT(_jobject)

HL_PRIM jvalue* HL_NAME(args__new)(int count) {
	return hl_gc_alloc_noptr(sizeof(jvalue) * count);
}
DEFINE_PRIM(_JNIARGS, args__new, _I32);

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

HL_PRIM JNINativeMethod* HL_NAME(native_methods__new)(int count) {
	return hl_gc_alloc_noptr(sizeof(JNINativeMethod) * count);
}
DEFINE_PRIM(_JNATIVEMETHODS, native_methods__new, _I32);

HL_PRIM void HL_NAME(native_methods_set)(JNINativeMethod* methods, int pos, char* name, char* signature, vclosure* fn) {
	if (fn->hasValue) {
		hl_error("Only static methods are supported for JNINativeMethods.set");
		return;
	}
	JNINativeMethod* method = &methods[pos];
	method->name = name;
	method->signature = signature;
	method->fnPtr = fn->fun;
}
DEFINE_PRIM(_VOID, native_methods_set, _JNATIVEMETHODS _I32 _BYTES _BYTES _REF(_VOID));

