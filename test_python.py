import ourlang
import ourlang.dialects.custom as custom
import mlir.dialects.builtin as builtin
import mlir.dialects.std as std
from mlir.ir import *


def main():
    with Context() as ctx, Location.unknown():
        ourlang.register_dialects(ctx)

        module = Module.create()
        custom_type = custom.OurCustomType.get(ctx, 0)
        with InsertionPoint(module.body):
            # func_types = [RankedTensorType.get((10, 10), custom_type) for _ in range(2)]
            func_types = [MemRefType.get((10, 10), custom_type) for _ in range(2)]

            @builtin.FuncOp.from_py_func(*func_types)
            def test(*arg):
                return arg[0]

        print(module)


if __name__ == "__main__":
    main()
