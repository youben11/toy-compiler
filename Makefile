build:
	cmake -B build . -DLLVM_DIR=${LLVM_PROJECT}/build/lib/cmake/llvm    -DMLIR_DIR=${LLVM_PROJECT}/build/lib/cmake/mlir

python:
	make -C build/ OurlangBindingsPython
