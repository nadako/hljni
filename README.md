# hljni - call Java from Haxe/HashLink

[![Build Status](https://travis-ci.org/nadako/hljni.svg?branch=master)](https://travis-ci.org/nadako/hljni)

This [Haxe](https://github.com/HaxeFoundation/haxe) + [HashLink](https://github.com/HaxeFoundation/hashlink) library provides bindings for the [Java Native Interface](https://docs.oracle.com/javase/8/docs/technotes/guides/jni/), allowing for interoperation between Java VM and HashLink run-time. In other words: we can call Java functions from Haxe, which is useful when e.g. running on Android!

## Usage

As with any HashLink bindings, this library consists of two parts:
 * native glue that exposes JNI API in a HashLink-friendly way
 * Haxe externs for the glue

If you compile your Haxe/HL project to C, add the `native/hljni.c` file to your C compilation.

Before hljni functions can be used, the library must be initialized by setting
up global `JNIEnv*` with `hljni_set_env` function, found in the `native/hljni.h`
header. So do that in your application's entry point.

> TODO: bytecode/hdll use case, code examples, add helpers, etc.
