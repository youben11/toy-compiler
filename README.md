# toy-compiler

Minimal project to reproduce an issue reported [here](https://llvm.discourse.group/t/checking-types-between-different-python-extensions/3782)


## Building the project

You first need to build LLVM on your machine with Python bindings ON, and have exported the PYTHONPATH to use them.

```bash
$ mkdir build
$ export LLVM_PROJECT=/path/to/your/llvm
$ make build
$ make python
$ export PYTHONPATH=$PYTHONPATH:$PWD/build/python
```

then you can run the `test_python.py` script, and should get an error that the custom dialect type can't be used inside a MemRef.

