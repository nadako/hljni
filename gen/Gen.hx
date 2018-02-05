#if macro
import haxe.macro.Context;
import haxe.macro.Expr;
import haxe.macro.Type;
using haxe.macro.Tools;

class Gen {
	static function getPrelude() return sys.io.File.getContent(Context.resolvePath("hljni_prelude.c"));

	static function getJNIClass() return switch Context.getType("hljni.JNI.JNIEnv") { case TAbstract(a, _): a.get().impl.get(); case _: throw "assert"; };

	static function getNativeName(name) return ~/([A-Z]+)/g.replace(name, "_$1").toLowerCase();

	static function getTypeInfo(type:Type, pos:Position) return switch type.toString() {
		case "hljni.Jboolean": {c: "jboolean", prim: "_BOOL"};
		case "hljni.Jint": {c: "jint", prim: "_I32"};
		case "hljni.Jsize": {c: "jsize", prim: "_I32"};
		case "hljni.Jbyte": {c: "jbyte", prim: "_I8"};
		case "hljni.Jchar": {c: "jchar", prim: "_I16"};
		case "hljni.Jshort": {c: "jshort", prim: "_I16"};
		case "hljni.Jlong": {c: "jlong", prim: "_I64"};
		case "hljni.Jfloat": {c: "jfloat", prim: "_F32"};
		case "hljni.Jdouble": {c: "jdouble", prim: "_F64"};
		case "hljni.Jclass": {c: "jclass", prim: "_JOBJECT"};
		case "hljni.Jobject": {c: "jobject", prim: "_JOBJECT"};
		case "hljni.Jthrowable": {c: "jobject", prim: "_JOBJECT"};
		case "hljni.Jweak": {c: "jweak", prim: "_JOBJECT"};
		case "hljni.ConstCharStar": {c: "const char*", prim: "_BYTES"};
		case "hljni.ConstJbyteStar": {c: "const jbyte*", prim: "_BYTES"};
		case "hljni.ConstJcharStar": {c: "const jchar*", prim: "_BYTES"};
		case "hljni.JmethodID": {c: "jmethodID", prim: "_ABSTRACT(_jmethodID)"};
		case "hljni.JfieldID": {c: "jfieldID", prim: "_ABSTRACT(_jfieldID)"};
		case "hljni.JNIArgs": {c: "jvalue*", prim: "_JNIARGS"};
		case "hljni.JNINativeMethods": {c: "JNINativeMethod*", prim: "_JNATIVEMETHODS"};
		case "hljni.JobjectRefType": {c: "jobjectRefType", prim: "_I32"};
		case "hljni.Jstring": {c: "jstring", prim: "_JOBJECT"};
		case "hl.Ref<hljni.Jboolean>": {c: "jboolean*", prim: "_REF(_BOOL)"};
		case "hljni.Jarray": {c: "jarray", prim: "_JOBJECT"};
		case "hljni.JobjectArray": {c: "jobjectArray", prim: "_JOBJECT"};
		case "hljni.JbooleanArray": {c: "jbooleanArray", prim: "_JOBJECT"};
		case "hljni.JbyteArray": {c: "jbyteArray", prim: "_JOBJECT"};
		case "hljni.JcharArray": {c: "jcharArray", prim: "_JOBJECT"};
		case "hljni.JshortArray": {c: "jshortArray", prim: "_JOBJECT"};
		case "hljni.JintArray": {c: "jintArray", prim: "_JOBJECT"};
		case "hljni.JlongArray": {c: "jlongArray", prim: "_JOBJECT"};
		case "hljni.JfloatArray": {c: "jfloatArray", prim: "_JOBJECT"};
		case "hljni.JdoubleArray": {c: "jdoubleArray", prim: "_JOBJECT"};
		case "hl.Bytes": {c: "char*", prim: "_BYTES"};
		case "hljni.BytesOf<hljni.Jboolean>": {c: "jboolean*", prim: "_BYTES"};
		case "hljni.BytesOf<hljni.Jbyte>": {c: "jbyte*", prim: "_BYTES"};
		case "hljni.BytesOf<hljni.Jchar>": {c: "jchar*", prim: "_BYTES"};
		case "hljni.BytesOf<hljni.Jshort>": {c: "jshort*", prim: "_BYTES"};
		case "hljni.BytesOf<hljni.Jint>": {c: "jint*", prim: "_BYTES"};
		case "hljni.BytesOf<hljni.Jlong>": {c: "jlong*", prim: "_BYTES"};
		case "hljni.BytesOf<hljni.Jfloat>": {c: "jfloat*", prim: "_BYTES"};
		case "hljni.BytesOf<hljni.Jdouble>": {c: "jdouble*", prim: "_BYTES"};
		case "Void": {c: "void", prim: "_VOID"};
		case unsupported: throw new Error('Unsupported type: $unsupported', pos);
	}

	static function run(outPath:String) {
		var content = [
			"// This file is auto-generated, do not edit!",
			getPrelude(),
		];

		var jniClass = getJNIClass();

		for (method in jniClass.statics.get()) {
			var args, ret;
			switch method.type {
				case TFun(a, r): args = a; ret = r;
				case _: throw new Error("not a method", method.pos);
			}

			var nativeName = getNativeName(method.name);

			var ret = getTypeInfo(ret, method.pos);
			var nativeRet = ret.c;
			var primRet = ret.prim;

			var firstArg = args.shift();
			if (firstArg.t.toString() != 'hl.Abstract<"JNIEnv">')
				throw "assert";

			var nativeArgs = ["JNIEnv* env"];
			var primArgs = ["_JNIENV"];
			var callArgs = ["env"];

			for (arg in args) {
				var t = getTypeInfo(arg.t, method.pos);
				nativeArgs.push('${t.c} ${arg.name}');
				primArgs.push(t.prim);
				callArgs.push(arg.name);
			}

			content.push([
				'HL_PRIM $nativeRet HL_NAME($nativeName)(${nativeArgs.join(", ")}) {',
				'\t${if (nativeRet != "void") "return " else ""}(*env)->${method.name}(${callArgs.join(", ")});',
				'}',
				'DEFINE_PRIM($primRet, $nativeName, ${primArgs.join(" ")});',
			].join("\n"));
		}

		sys.io.File.saveContent('$outPath/hljni.c', content.join("\n\n"));
	}
}
#end
