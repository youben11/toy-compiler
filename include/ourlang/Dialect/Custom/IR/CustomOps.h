#ifndef OURLANG_DIALECT_CUSTOM_IR_CUSTOMOPS_H
#define OURLANG_DIALECT_CUSTOM_IR_CUSTOMOPS_H

#include <mlir/IR/BuiltinOps.h>
#include <mlir/IR/BuiltinTypes.h>
#include <mlir/Interfaces/ControlFlowInterfaces.h>
#include <mlir/Interfaces/SideEffectInterfaces.h>

#include "ourlang/Dialect/Custom/IR/CustomTypes.h"

#define GET_OP_CLASSES
#include "ourlang/Dialect/Custom/IR/CustomOps.h.inc"

#endif
