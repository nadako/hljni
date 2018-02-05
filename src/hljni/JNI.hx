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

// arguments
abstract JNIArgs(JvaluePointer) {
	public inline function new(count) this = JNIArgsHelper.argsAlloc(count);
	public inline function setJboolean(pos:Int, value:Jboolean) JNIArgsHelper.argsSetJboolean(this, pos, value);
	public inline function setJbyte(pos:Int, value:Jbyte) JNIArgsHelper.argsSetJbyte(this, pos, value);
	public inline function setJchar(pos:Int, value:Jchar) JNIArgsHelper.argsSetJchar(this, pos, value);
	public inline function setJshort(pos:Int, value:Jshort) JNIArgsHelper.argsSetJshort(this, pos, value);
	public inline function setJint(pos:Int, value:Jint) JNIArgsHelper.argsSetJint(this, pos, value);
	public inline function setJlong(pos:Int, value:Jlong) JNIArgsHelper.argsSetJlong(this, pos, value);
	public inline function setJfloat(pos:Int, value:Jfloat) JNIArgsHelper.argsSetJfloat(this, pos, value);
	public inline function setJdouble(pos:Int, value:Jdouble) JNIArgsHelper.argsSetJdouble(this, pos, value);
	public inline function setJobject(pos:Int, value:Jobject) JNIArgsHelper.argsSetJobject(this, pos, value);
}

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

private typedef JvaluePointer = hl.Abstract<"jvalue">;

@:hlNative("hljni")
private extern class JNIArgsHelper {
	static function argsAlloc(size:Int):JvaluePointer;
	static function argsSetJboolean(args:JvaluePointer, pos:Int, value:Jboolean):Void;
	static function argsSetJbyte(args:JvaluePointer, pos:Int, value:Jbyte):Void;
	static function argsSetJchar(args:JvaluePointer, pos:Int, value:Jchar):Void;
	static function argsSetJshort(args:JvaluePointer, pos:Int, value:Jshort):Void;
	static function argsSetJint(args:JvaluePointer, pos:Int, value:Jint):Void;
	static function argsSetJlong(args:JvaluePointer, pos:Int, value:Jlong):Void;
	static function argsSetJfloat(args:JvaluePointer, pos:Int, value:Jfloat):Void;
	static function argsSetJdouble(args:JvaluePointer, pos:Int, value:Jdouble):Void;
	static function argsSetJobject(args:JvaluePointer, pos:Int, value:Jobject):Void;
}

/** see https://docs.oracle.com/javase/8/docs/technotes/guides/jni/spec/functions.html **/
@:hlNative("hljni")
extern class JNI {
	static function GetVersion():Jint;
	static function DefineClass(name:ConstCharStar, loader:Jobject, buf:ConstJbyteStar, bufLen:Jsize):Jclass;
	static function FindClass(name:ConstCharStar):Jclass;
	static function GetSuperclass(clazz:Jclass):Jclass;
	static function IsAssignableFrom(clazz1:Jclass, clazz2:Jclass):Jboolean;
	static function Throw(obj:Jthrowable):Jint;
	static function ThrowNew(clazz:Jclass, message:ConstCharStar):Jint;
	static function ExceptionOccurred():Jthrowable;
	static function ExceptionDescribe():Void;
	static function ExceptionClear():Void;
	static function FatalError(msg:ConstCharStar):Void;
	static function ExceptionCheck():Jboolean;
	static function NewGlobalRef(obj:Jobject):Jobject;
	static function DeleteGlobalRef(globalRef:Jobject):Void;
	static function DeleteLocalRef(localRef:Jobject):Void;
	static function EnsureLocalCapacity(capacity:Jint):Jint;
	static function PushLocalFrame(capacity:Jint):Jint;
	static function PopLocalFrame(result:Jobject):Jobject;
	static function NewLocalRef(ref:Jobject):Jobject;
	static function NewWeakGlobalRef(obj:Jobject):Jweak;
	static function DeleteWeakGlobalRef(obj:Jweak):Void;
	static function AllocObject(clazz:Jclass):Jobject;
	static function NewObjectA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jobject;
	static function GetObjectClass(obj:Jobject):Jclass;
	static function GetObjectRefType(obj:Jobject):JobjectRefType;
	static function IsInstanceOf(obj:Jobject, clazz:Jclass):Jboolean;
	static function IsSameObject(ref1:Jobject, ref2:Jobject):Jboolean;
	static function GetFieldID(clazz:Jclass, name:ConstCharStar, sig:ConstCharStar):JfieldID;
	static function GetObjectField(obj:Jobject, fieldID:JfieldID):Jobject;
	static function GetBooleanField(obj:Jobject, fieldID:JfieldID):Jboolean;
	static function GetByteField(obj:Jobject, fieldID:JfieldID):Jbyte;
	static function GetCharField(obj:Jobject, fieldID:JfieldID):Jchar;
	static function GetShortField(obj:Jobject, fieldID:JfieldID):Jshort;
	static function GetIntField(obj:Jobject, fieldID:JfieldID):Jint;
	static function GetLongField(obj:Jobject, fieldID:JfieldID):Jlong;
	static function GetFloatField(obj:Jobject, fieldID:JfieldID):Jfloat;
	static function GetDoubleField(obj:Jobject, fieldID:JfieldID):Jdouble;
	static function SetObjectField(obj:Jobject, fieldID:JfieldID, value:Jobject):Void;
	static function SetBooleanField(obj:Jobject, fieldID:JfieldID, value:Jboolean):Void;
	static function SetByteField(obj:Jobject, fieldID:JfieldID, value:Jbyte):Void;
	static function SetCharField(obj:Jobject, fieldID:JfieldID, value:Jchar):Void;
	static function SetShortField(obj:Jobject, fieldID:JfieldID, value:Jshort):Void;
	static function SetIntField(obj:Jobject, fieldID:JfieldID, value:Jint):Void;
	static function SetLongField(obj:Jobject, fieldID:JfieldID, value:Jlong):Void;
	static function SetFloatField(obj:Jobject, fieldID:JfieldID, value:Jfloat):Void;
	static function SetDoubleField(obj:Jobject, fieldID:JfieldID, value:Jdouble):Void;
	static function GetMethodID(clazz:Jclass, name:ConstCharStar, sig:ConstCharStar):JmethodID;
	static function CallVoidMethodA(obj:Jobject, methodID:JmethodID, args:JNIArgs):Void;
	static function CallObjectMethodA(obj:Jobject, methodID:JmethodID, args:JNIArgs):Jobject;
	static function CallBooleanMethodA(obj:Jobject, methodID:JmethodID, args:JNIArgs):Jboolean;
	static function CallByteMethodA(obj:Jobject, methodID:JmethodID, args:JNIArgs):Jbyte;
	static function CallCharMethodA(obj:Jobject, methodID:JmethodID, args:JNIArgs):Jchar;
	static function CallShortMethodA(obj:Jobject, methodID:JmethodID, args:JNIArgs):Jshort;
	static function CallIntMethodA(obj:Jobject, methodID:JmethodID, args:JNIArgs):Jint;
	static function CallLongMethodA(obj:Jobject, methodID:JmethodID, args:JNIArgs):Jlong;
	static function CallFloatMethodA(obj:Jobject, methodID:JmethodID, args:JNIArgs):Jfloat;
	static function CallDoubleMethodA(obj:Jobject, methodID:JmethodID, args:JNIArgs):Jdouble;
	static function CallNonvirtualVoidMethodA(obj:Jobject, clazz:Jclass, methodID:JmethodID, args:JNIArgs):Void;
	static function CallNonvirtualObjectMethodA(obj:Jobject, clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jobject;
	static function CallNonvirtualBooleanMethodA(obj:Jobject, clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jboolean;
	static function CallNonvirtualByteMethodA(obj:Jobject, clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jbyte;
	static function CallNonvirtualCharMethodA(obj:Jobject, clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jchar;
	static function CallNonvirtualShortMethodA(obj:Jobject, clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jshort;
	static function CallNonvirtualIntMethodA(obj:Jobject, clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jint;
	static function CallNonvirtualLongMethodA(obj:Jobject, clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jlong;
	static function CallNonvirtualFloatMethodA(obj:Jobject, clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jfloat;
	static function CallNonvirtualDoubleMethodA(obj:Jobject, clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jdouble;
	static function GetStaticFieldID(clazz:Jclass, name:ConstCharStar, sig:ConstCharStar):JfieldID;
	static function GetStaticObjectField(obj:Jclass, fieldID:JfieldID):Jobject;
	static function GetStaticBooleanField(obj:Jclass, fieldID:JfieldID):Jboolean;
	static function GetStaticByteField(obj:Jclass, fieldID:JfieldID):Jbyte;
	static function GetStaticCharField(obj:Jclass, fieldID:JfieldID):Jchar;
	static function GetStaticShortField(obj:Jclass, fieldID:JfieldID):Jshort;
	static function GetStaticIntField(obj:Jclass, fieldID:JfieldID):Jint;
	static function GetStaticLongField(obj:Jclass, fieldID:JfieldID):Jlong;
	static function GetStaticFloatField(obj:Jclass, fieldID:JfieldID):Jfloat;
	static function GetStaticDoubleField(obj:Jclass, fieldID:JfieldID):Jdouble;
	static function SetStaticObjectField(obj:Jclass, fieldID:JfieldID, value:Jobject):Void;
	static function SetStaticBooleanField(obj:Jclass, fieldID:JfieldID, value:Jboolean):Void;
	static function SetStaticByteField(obj:Jclass, fieldID:JfieldID, value:Jbyte):Void;
	static function SetStaticCharField(obj:Jclass, fieldID:JfieldID, value:Jchar):Void;
	static function SetStaticShortField(obj:Jclass, fieldID:JfieldID, value:Jshort):Void;
	static function SetStaticIntField(obj:Jclass, fieldID:JfieldID, value:Jint):Void;
	static function SetStaticLongField(obj:Jclass, fieldID:JfieldID, value:Jlong):Void;
	static function SetStaticFloatField(obj:Jclass, fieldID:JfieldID, value:Jfloat):Void;
	static function SetStaticDoubleField(obj:Jclass, fieldID:JfieldID, value:Jdouble):Void;
	static function GetStaticMethodID(clazz:Jclass, name:ConstCharStar, sig:ConstCharStar):JmethodID;
	static function CallStaticVoidMethodA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Void;
	static function CallStaticObjectMethodA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jobject;
	static function CallStaticBooleanMethodA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jboolean;
	static function CallStaticByteMethodA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jbyte;
	static function CallStaticCharMethodA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jchar;
	static function CallStaticShortMethodA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jshort;
	static function CallStaticIntMethodA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jint;
	static function CallStaticLongMethodA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jlong;
	static function CallStaticFloatMethodA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jfloat;
	static function CallStaticDoubleMethodA(clazz:Jclass, methodID:JmethodID, args:JNIArgs):Jdouble;
	static function NewString(unicodeChars:ConstJcharStar, len:Jsize):Jstring;
	static function GetStringLength(string:Jstring):Jsize;
	static function GetStringChars(string:Jstring, isCopy:hl.Ref<Jboolean>):ConstJcharStar;
	static function ReleaseStringChars(string:Jstring, chars:ConstJcharStar):Void;
	static function NewStringUTF(bytes:ConstCharStar):Jstring;
	static function GetStringUTFLength(string:Jstring):Jsize;
	static function GetStringUTFChars(string:Jstring, isCopy:hl.Ref<Jboolean>):ConstCharStar;
	static function ReleaseStringUTFChars(string:Jstring, utf:ConstCharStar):Void;
	static function GetStringRegion(str:Jstring, start:Jsize, len:Jsize, buf:BytesOf<Jchar>):Void;
	static function GetStringUTFRegion(str:Jstring, start:Jsize, len:Jsize, buf:hl.Bytes):Void;
	static function GetStringCritical(string:Jstring, isCopy:hl.Ref<Jboolean>):ConstJcharStar;
	static function ReleaseStringCritical(string:Jstring, carray:ConstJcharStar):Void;
	static function GetArrayLength(array:Jarray):Jsize;
	static function NewObjectArray(length:Jsize, elementClass:Jclass, initialElement:Jobject):JobjectArray;
	static function GetObjectArrayElement(array:JobjectArray, index:Jsize):Jobject;
	static function SetObjectArrayElement(array:JobjectArray, index:Jsize, value:Jobject):Void;
	static function NewBooleanArray(length:Jsize):JbooleanArray;
	static function NewByteArray(length:Jsize):JbyteArray;
	static function NewCharArray(length:Jsize):JcharArray;
	static function NewShortArray(length:Jsize):JshortArray;
	static function NewIntArray(length:Jsize):JintArray;
	static function NewLongArray(length:Jsize):JlongArray;
	static function NewFloatArray(length:Jsize):JfloatArray;
	static function NewDoubleArray(length:Jsize):JdoubleArray;
	static function GetBooleanArrayElements(array:JbooleanArray, isCopy:hl.Ref<Jboolean>):BytesOf<Jboolean>;
	static function GetByteArrayElements(array:JbyteArray, isCopy:hl.Ref<Jboolean>):BytesOf<Jbyte>;
	static function GetCharArrayElements(array:JcharArray, isCopy:hl.Ref<Jboolean>):BytesOf<Jchar>;
	static function GetShortArrayElements(array:JshortArray, isCopy:hl.Ref<Jboolean>):BytesOf<Jshort>;
	static function GetIntArrayElements(array:JintArray, isCopy:hl.Ref<Jboolean>):BytesOf<Jint>;
	static function GetLongArrayElements(array:JlongArray, isCopy:hl.Ref<Jboolean>):BytesOf<Jlong>;
	static function GetFloatArrayElements(array:JfloatArray, isCopy:hl.Ref<Jboolean>):BytesOf<Jfloat>;
	static function GetDoubleArrayElements(array:JdoubleArray, isCopy:hl.Ref<Jboolean>):BytesOf<Jdouble>;
	static function ReleaseBooleanArrayElements(array:JbooleanArray, elems:BytesOf<Jboolean>, mode:Jint):Void;
	static function ReleaseByteArrayElements(array:JbyteArray, elems:BytesOf<Jbyte>, mode:Jint):Void;
	static function ReleaseCharArrayElements(array:JcharArray, elems:BytesOf<Jchar>, mode:Jint):Void;
	static function ReleaseShortArrayElements(array:JshortArray, elems:BytesOf<Jshort>, mode:Jint):Void;
	static function ReleaseIntArrayElements(array:JintArray, elems:BytesOf<Jint>, mode:Jint):Void;
	static function ReleaseLongArrayElements(array:JlongArray, elems:BytesOf<Jlong>, mode:Jint):Void;
	static function ReleaseFloatArrayElements(array:JfloatArray, elems:BytesOf<Jfloat>, mode:Jint):Void;
	static function ReleaseDoubleArrayElements(array:JdoubleArray, elems:BytesOf<Jdouble>, mode:Jint):Void;
	static function GetBooleanArrayRegion(array:JbooleanArray, start:Jsize, len:Jsize, buf:BytesOf<Jboolean>):Void;
	static function GetByteArrayRegion(array:JbyteArray, start:Jsize, len:Jsize, buf:BytesOf<Jbyte>):Void;
	static function GetCharArrayRegion(array:JcharArray, start:Jsize, len:Jsize, buf:BytesOf<Jchar>):Void;
	static function GetShortArrayRegion(array:JshortArray, start:Jsize, len:Jsize, buf:BytesOf<Jshort>):Void;
	static function GetIntArrayRegion(array:JintArray, start:Jsize, len:Jsize, buf:BytesOf<Jint>):Void;
	static function GetLongArrayRegion(array:JlongArray, start:Jsize, len:Jsize, buf:BytesOf<Jlong>):Void;
	static function GetFloatArrayRegion(array:JfloatArray, start:Jsize, len:Jsize, buf:BytesOf<Jfloat>):Void;
	static function GetDoubleArrayRegion(array:JdoubleArray, start:Jsize, len:Jsize, buf:BytesOf<Jdouble>):Void;
	static function SetBooleanArrayRegion(array:JbooleanArray, start:Jsize, len:Jsize, buf:BytesOf<Jboolean>):Void;
	static function SetByteArrayRegion(array:JbyteArray, start:Jsize, len:Jsize, buf:BytesOf<Jbyte>):Void;
	static function SetCharArrayRegion(array:JcharArray, start:Jsize, len:Jsize, buf:BytesOf<Jchar>):Void;
	static function SetShortArrayRegion(array:JshortArray, start:Jsize, len:Jsize, buf:BytesOf<Jshort>):Void;
	static function SetIntArrayRegion(array:JintArray, start:Jsize, len:Jsize, buf:BytesOf<Jint>):Void;
	static function SetLongArrayRegion(array:JlongArray, start:Jsize, len:Jsize, buf:BytesOf<Jlong>):Void;
	static function SetFloatArrayRegion(array:JfloatArray, start:Jsize, len:Jsize, buf:BytesOf<Jfloat>):Void;
	static function SetDoubleArrayRegion(array:JdoubleArray, start:Jsize, len:Jsize, buf:BytesOf<Jdouble>):Void;
	static function GetPrimitiveArrayCritical(array:Jarray, isCopy:hl.Ref<Jboolean>):hl.Bytes;
	static function ReleasePrimitiveArrayCritical(array:Jarray, carray:hl.Bytes, mode:Jint):Void;
}
