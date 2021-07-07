#ifndef OURLANG_DIALECT_CUSTOM_IR_CUSTOMTYPES_H
#define OURLANG_DIALECT_CUSTOM_IR_CUSTOMTYPES_H

#include "llvm/ADT/TypeSwitch.h"
#include <mlir/IR/BuiltinOps.h>
#include <mlir/IR/BuiltinTypes.h>
#include <mlir/IR/DialectImplementation.h>

#define GET_TYPEDEF_CLASSES
#include "ourlang/Dialect/Custom/IR/CustomOpsTypes.h.inc"

#endif
