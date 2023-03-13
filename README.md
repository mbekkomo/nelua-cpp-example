# An example how to do C++ interoperability inside Nelua

This repository contains an example how to do C++ interoperability inside [Nelua](https://nelua.io). The method to get C++ interoperability inside Nelua is to compile the C++ code (that has `extern "C"` functions in it) into shared library.

## Build and Test

To build and test, run `make`. You should see an output like this.
```bash
# (EXT) is the extension of shared library, `.dylib` in Darwin (Mac os), `.so` in Linux
c++ -W -Wall -g -fPIC -shared hello.cpp -o libhello.(EXT)
nelua --cflags="./libhello.(EXT)" hello.nelua
Hello World!
Hello UrNightmaree!
```
