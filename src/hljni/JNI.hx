package hljni;

// primitive
typedef Jboolean = Bool;
typedef Jbyte = hl.UI8;
typedef Jchar = hl.UI16;
typedef Jshort = hl.UI16;
typedef Jint = Int;
typedef Jlong = hl.I64;
typedef Jfloat = Single;
typedef Jdouble = Float;
typedef Jsize = Jint;

// reference
abstract Jobject(hl.Abstract<"_jobject">) {}
abstract Jclass(Jobject) to Jobject {}
abstract Jstring(Jobject) to Jobject {}
abstract Jarray(Jobject) to Jobject {}
abstract JobjectArray(Jarray) to Jarray {}
abstract JbooleanArray(Jarray) to Jarray {}
abstract JbyteArray(Jarray) to Jarray {}
abstract JcharArray(Jarray) to Jarray {}
abstract JshortArray(Jarray) to Jarray {}
abstract JintArray(Jarray) to Jarray {}
abstract JlongArray(Jarray) to Jarray {}
abstract JfloatArray(Jarray) to Jarray {}
abstract JdoubleArray(Jarray) to Jarray {}
abstract Jthrowable(Jobject) to Jobject {}
abstract Jweak(Jobject) to Jobject {}

// field pointers
abstract JmethodID(hl.Abstract<"_jmethodID">) {}
abstract JfieldID(hl.Abstract<"_jfieldID">) {}

// misc
typedef ConstCharStar = hl.Bytes;
typedef ConstJcharStar = hl.Bytes;
typedef ConstJbyteStar = hl.Bytes;
typedef BytesOf<T> = hl.Bytes;

@:enum abstract JobjectRefType(Int) {
	var JNIInvalidRefType = 0;
	var JNILocalRefType = 1;
	var JNIGlobalRefType = 2;
	var JNIWeakGlobalRefType = 3;
}

// arguments
@:hlNative("hljni", "args_")
extern abstract JNIArgs(hl.Abstract<"jvalue">) {
	function new(count:Int);
	function setJboolean(pos:Int, value:Jboolean):Void;
	function setJbyte(pos:Int, value:Jbyte):Void;
	function setJchar(pos:Int, value:Jchar):Void;
	function setJshort(pos:Int, value:Jshort):Void;
	function setJint(pos:Int, value:Jint):Void;
	function setJlong(pos:Int, value:Jlong):Void;
	function setJfloat(pos:Int, value:Jfloat):Void;
	function setJdouble(pos:Int, value:Jdouble):Void;
	function setJobject(pos:Int, value:Jobject):Void;
}

// native methods array
@:hlNative("hljni", "native_methods_")
extern abstract JNINativeMethods(hl.Abstract<"JNINativeMethod">) {
	function new(count:Int);
	function set(pos:Int, name:hl.Bytes, signature:hl.Bytes, fn:haxe.Constraints.Function):Void;
}

@:hlNative("hljni")
extern abstract JNIEnv(hl.Abstract<"JNIEnv">) {
	function GetVersion():Jint;
	function DefineClass(name:ConstCharStar, loader:Jobject, buf:ConstJbyteStar, bufLen:Jsize):Jclass;
	function FindClass(name:ConstCharStar):Jclass;
	function GetSuperclass(clazz:Jclass):Jclass;
	function IsAssignableFrom(clazz1:Jclass, clazz2:Jclass):Jboolean;
	function Throw(obj:Jthrowable):Jint;
	function ThrowNew(clazz:Jclass, message:ConstCharStar):Jint;
	function ExceptionOccurred():Jthrowable;
	function ExceptionDescribe():Void;
	function ExceptionClear():Void;
	function FatalError(msg:ConstCharStar):Void;
	function ExceptionCheck():Jboolean;
	function NewGlobalRef(obj:Jobject):Jobject;
	function DeleteGlobalRef(globalRef:Jobject):Void;
	function DeleteLocalRef(localRef:Jobject):Void;
	function EnsureLocalCapacity(capacity:Jint):Jint;
	function PushLocalFrame(capacity:Jint):Jint;
	function PopLocalFrame(result:Jobject):Jobject;
	function NewLocalRef(ref:Jobject):Jobject;
	function NewWeakGlobalRef(obj:Jobject):Jweak;
	function DeleteWeakGlobalRef(obj:Jweak):Void;
	function AllocObject(clazz:Jclass):Jobject;
	function NewObjectA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jobject;
	function GetObjectClass(obj:Jobject):Jclass;
	function GetObjectRefType(obj:Jobject):JobjectRefType;
	function IsInstanceOf(obj:Jobject, clazz:Jclass):Jboolean;
	function IsSameObject(ref1:Jobject, ref2:Jobject):Jboolean;
	function GetFieldID(clazz:Jclass, name:ConstCharStar, sig:ConstCharStar):JfieldID;
	function GetObjectField(obj:Jobject, fieldID:JfieldID):Jobject;
	function GetBooleanField(obj:Jobject, fieldID:JfieldID):Jboolean;
	function GetByteField(obj:Jobject, fieldID:JfieldID):Jbyte;
	function GetCharField(obj:Jobject, fieldID:JfieldID):Jchar;
	function GetShortField(obj:Jobject, fieldID:JfieldID):Jshort;
	function GetIntField(obj:Jobject, fieldID:JfieldID):Jint;
	function GetLongField(obj:Jobject, fieldID:JfieldID):Jlong;
	function GetFloatField(obj:Jobject, fieldID:JfieldID):Jfloat;
	function GetDoubleField(obj:Jobject, fieldID:JfieldID):Jdouble;
	function SetObjectField(obj:Jobject, fieldID:JfieldID, value:Jobject):Void;
	function SetBooleanField(obj:Jobject, fieldID:JfieldID, value:Jboolean):Void;
	function SetByteField(obj:Jobject, fieldID:JfieldID, value:Jbyte):Void;
	function SetCharField(obj:Jobject, fieldID:JfieldID, value:Jchar):Void;
	function SetShortField(obj:Jobject, fieldID:JfieldID, value:Jshort):Void;
	function SetIntField(obj:Jobject, fieldID:JfieldID, value:Jint):Void;
	function SetLongField(obj:Jobject, fieldID:JfieldID, value:Jlong):Void;
	function SetFloatField(obj:Jobject, fieldID:JfieldID, value:Jfloat):Void;
	function SetDoubleField(obj:Jobject, fieldID:JfieldID, value:Jdouble):Void;
	function GetMethodID(clazz:Jclass, name:ConstCharStar, sig:ConstCharStar):JmethodID;
	function CallVoidMethodA(obj:Jobject, methodID:JmethodID, args:JNIArgs):Void;
	function CallObjectMethodA(obj:Jobject, methodID:JmethodID, args:JNIArgs):Jobject;
	function CallBooleanMethodA(obj:Jobject, methodID:JmethodID, args:JNIArgs):Jboolean;
	function CallByteMethodA(obj:Jobject, methodID:JmethodID, args:JNIArgs):Jbyte;
	function CallCharMethodA(obj:Jobject, methodID:JmethodID, args:JNIArgs):Jchar;
	function CallShortMethodA(obj:Jobject, methodID:JmethodID, args:JNIArgs):Jshort;
	function CallIntMethodA(obj:Jobject, methodID:JmethodID, args:JNIArgs):Jint;
	function CallLongMethodA(obj:Jobject, methodID:JmethodID, args:JNIArgs):Jlong;
	function CallFloatMethodA(obj:Jobject, methodID:JmethodID, args:JNIArgs):Jfloat;
	function CallDoubleMethodA(obj:Jobject, methodID:JmethodID, args:JNIArgs):Jdouble;
	function CallNonvirtualVoidMethodA(obj:Jobject, clazz:Jclass, methodID:JmethodID, args:JNIArgs):Void;
	function CallNonvirtualObjectMethodA(obj:Jobject, clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jobject;
	function CallNonvirtualBooleanMethodA(obj:Jobject, clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jboolean;
	function CallNonvirtualByteMethodA(obj:Jobject, clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jbyte;
	function CallNonvirtualCharMethodA(obj:Jobject, clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jchar;
	function CallNonvirtualShortMethodA(obj:Jobject, clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jshort;
	function CallNonvirtualIntMethodA(obj:Jobject, clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jint;
	function CallNonvirtualLongMethodA(obj:Jobject, clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jlong;
	function CallNonvirtualFloatMethodA(obj:Jobject, clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jfloat;
	function CallNonvirtualDoubleMethodA(obj:Jobject, clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jdouble;
	function GetStaticFieldID(clazz:Jclass, name:ConstCharStar, sig:ConstCharStar):JfieldID;
	function GetStaticObjectField(obj:Jclass, fieldID:JfieldID):Jobject;
	function GetStaticBooleanField(obj:Jclass, fieldID:JfieldID):Jboolean;
	function GetStaticByteField(obj:Jclass, fieldID:JfieldID):Jbyte;
	function GetStaticCharField(obj:Jclass, fieldID:JfieldID):Jchar;
	function GetStaticShortField(obj:Jclass, fieldID:JfieldID):Jshort;
	function GetStaticIntField(obj:Jclass, fieldID:JfieldID):Jint;
	function GetStaticLongField(obj:Jclass, fieldID:JfieldID):Jlong;
	function GetStaticFloatField(obj:Jclass, fieldID:JfieldID):Jfloat;
	function GetStaticDoubleField(obj:Jclass, fieldID:JfieldID):Jdouble;
	function SetStaticObjectField(obj:Jclass, fieldID:JfieldID, value:Jobject):Void;
	function SetStaticBooleanField(obj:Jclass, fieldID:JfieldID, value:Jboolean):Void;
	function SetStaticByteField(obj:Jclass, fieldID:JfieldID, value:Jbyte):Void;
	function SetStaticCharField(obj:Jclass, fieldID:JfieldID, value:Jchar):Void;
	function SetStaticShortField(obj:Jclass, fieldID:JfieldID, value:Jshort):Void;
	function SetStaticIntField(obj:Jclass, fieldID:JfieldID, value:Jint):Void;
	function SetStaticLongField(obj:Jclass, fieldID:JfieldID, value:Jlong):Void;
	function SetStaticFloatField(obj:Jclass, fieldID:JfieldID, value:Jfloat):Void;
	function SetStaticDoubleField(obj:Jclass, fieldID:JfieldID, value:Jdouble):Void;
	function GetStaticMethodID(clazz:Jclass, name:ConstCharStar, sig:ConstCharStar):JmethodID;
	function CallStaticVoidMethodA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Void;
	function CallStaticObjectMethodA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jobject;
	function CallStaticBooleanMethodA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jboolean;
	function CallStaticByteMethodA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jbyte;
	function CallStaticCharMethodA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jchar;
	function CallStaticShortMethodA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jshort;
	function CallStaticIntMethodA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jint;
	function CallStaticLongMethodA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jlong;
	function CallStaticFloatMethodA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jfloat;
	function CallStaticDoubleMethodA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jdouble;
	function NewString(unicodeChars:ConstJcharStar, len:Jsize):Jstring;
	function GetStringLength(string:Jstring):Jsize;
	function GetStringChars(string:Jstring, isCopy:hl.Ref<Jboolean>):ConstJcharStar;
	function ReleaseStringChars(string:Jstring, chars:ConstJcharStar):Void;
	function NewStringUTF(bytes:ConstCharStar):Jstring;
	function GetStringUTFLength(string:Jstring):Jsize;
	function GetStringUTFChars(string:Jstring, isCopy:hl.Ref<Jboolean>):ConstCharStar;
	function ReleaseStringUTFChars(string:Jstring, utf:ConstCharStar):Void;
	function GetStringRegion(str:Jstring, start:Jsize, len:Jsize, buf:BytesOf<Jchar>):Void;
	function GetStringUTFRegion(str:Jstring, start:Jsize, len:Jsize, buf:hl.Bytes):Void;
	function GetStringCritical(string:Jstring, isCopy:hl.Ref<Jboolean>):ConstJcharStar;
	function ReleaseStringCritical(string:Jstring, carray:ConstJcharStar):Void;
	function GetArrayLength(array:Jarray):Jsize;
	function NewObjectArray(length:Jsize, elementClass:Jclass, initialElement:Jobject):JobjectArray;
	function GetObjectArrayElement(array:JobjectArray, index:Jsize):Jobject;
	function SetObjectArrayElement(array:JobjectArray, index:Jsize, value:Jobject):Void;
	function NewBooleanArray(length:Jsize):JbooleanArray;
	function NewByteArray(length:Jsize):JbyteArray;
	function NewCharArray(length:Jsize):JcharArray;
	function NewShortArray(length:Jsize):JshortArray;
	function NewIntArray(length:Jsize):JintArray;
	function NewLongArray(length:Jsize):JlongArray;
	function NewFloatArray(length:Jsize):JfloatArray;
	function NewDoubleArray(length:Jsize):JdoubleArray;
	function GetBooleanArrayElements(array:JbooleanArray, isCopy:hl.Ref<Jboolean>):BytesOf<Jboolean>;
	function GetByteArrayElements(array:JbyteArray, isCopy:hl.Ref<Jboolean>):BytesOf<Jbyte>;
	function GetCharArrayElements(array:JcharArray, isCopy:hl.Ref<Jboolean>):BytesOf<Jchar>;
	function GetShortArrayElements(array:JshortArray, isCopy:hl.Ref<Jboolean>):BytesOf<Jshort>;
	function GetIntArrayElements(array:JintArray, isCopy:hl.Ref<Jboolean>):BytesOf<Jint>;
	function GetLongArrayElements(array:JlongArray, isCopy:hl.Ref<Jboolean>):BytesOf<Jlong>;
	function GetFloatArrayElements(array:JfloatArray, isCopy:hl.Ref<Jboolean>):BytesOf<Jfloat>;
	function GetDoubleArrayElements(array:JdoubleArray, isCopy:hl.Ref<Jboolean>):BytesOf<Jdouble>;
	function ReleaseBooleanArrayElements(array:JbooleanArray, elems:BytesOf<Jboolean>, mode:Jint):Void;
	function ReleaseByteArrayElements(array:JbyteArray, elems:BytesOf<Jbyte>, mode:Jint):Void;
	function ReleaseCharArrayElements(array:JcharArray, elems:BytesOf<Jchar>, mode:Jint):Void;
	function ReleaseShortArrayElements(array:JshortArray, elems:BytesOf<Jshort>, mode:Jint):Void;
	function ReleaseIntArrayElements(array:JintArray, elems:BytesOf<Jint>, mode:Jint):Void;
	function ReleaseLongArrayElements(array:JlongArray, elems:BytesOf<Jlong>, mode:Jint):Void;
	function ReleaseFloatArrayElements(array:JfloatArray, elems:BytesOf<Jfloat>, mode:Jint):Void;
	function ReleaseDoubleArrayElements(array:JdoubleArray, elems:BytesOf<Jdouble>, mode:Jint):Void;
	function GetBooleanArrayRegion(array:JbooleanArray, start:Jsize, len:Jsize, buf:BytesOf<Jboolean>):Void;
	function GetByteArrayRegion(array:JbyteArray, start:Jsize, len:Jsize, buf:BytesOf<Jbyte>):Void;
	function GetCharArrayRegion(array:JcharArray, start:Jsize, len:Jsize, buf:BytesOf<Jchar>):Void;
	function GetShortArrayRegion(array:JshortArray, start:Jsize, len:Jsize, buf:BytesOf<Jshort>):Void;
	function GetIntArrayRegion(array:JintArray, start:Jsize, len:Jsize, buf:BytesOf<Jint>):Void;
	function GetLongArrayRegion(array:JlongArray, start:Jsize, len:Jsize, buf:BytesOf<Jlong>):Void;
	function GetFloatArrayRegion(array:JfloatArray, start:Jsize, len:Jsize, buf:BytesOf<Jfloat>):Void;
	function GetDoubleArrayRegion(array:JdoubleArray, start:Jsize, len:Jsize, buf:BytesOf<Jdouble>):Void;
	function SetBooleanArrayRegion(array:JbooleanArray, start:Jsize, len:Jsize, buf:BytesOf<Jboolean>):Void;
	function SetByteArrayRegion(array:JbyteArray, start:Jsize, len:Jsize, buf:BytesOf<Jbyte>):Void;
	function SetCharArrayRegion(array:JcharArray, start:Jsize, len:Jsize, buf:BytesOf<Jchar>):Void;
	function SetShortArrayRegion(array:JshortArray, start:Jsize, len:Jsize, buf:BytesOf<Jshort>):Void;
	function SetIntArrayRegion(array:JintArray, start:Jsize, len:Jsize, buf:BytesOf<Jint>):Void;
	function SetLongArrayRegion(array:JlongArray, start:Jsize, len:Jsize, buf:BytesOf<Jlong>):Void;
	function SetFloatArrayRegion(array:JfloatArray, start:Jsize, len:Jsize, buf:BytesOf<Jfloat>):Void;
	function SetDoubleArrayRegion(array:JdoubleArray, start:Jsize, len:Jsize, buf:BytesOf<Jdouble>):Void;
	function GetPrimitiveArrayCritical(array:Jarray, isCopy:hl.Ref<Jboolean>):hl.Bytes;
	function ReleasePrimitiveArrayCritical(array:Jarray, carray:hl.Bytes, mode:Jint):Void;
	function RegisterNatives(clazz:Jclass, methods:JNINativeMethods, nMethods:Jint):Jint;
	function UnregisterNatives(clazz:Jclass):Jint;
}
