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
