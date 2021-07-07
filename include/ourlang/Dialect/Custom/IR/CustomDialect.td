#ifndef OURLANG_DIALECT_CUSTOM_IR_CUSTOM_DIALECT
#define OURLANG_DIALECT_CUSTOM_IR_CUSTOM_DIALECT

include "mlir/IR/OpBase.td"

def Custom_Dialect : Dialect {
  let name = "Custom";
  let summary = "todo";
  let description = [{
    todo
  }];
  let cppNamespace = "::mlir::ourlang::Custom";
}

#endif
