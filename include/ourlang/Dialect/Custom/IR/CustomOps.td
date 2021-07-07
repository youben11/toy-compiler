#ifndef OURLANG_DIALECT_CUSTOM_IR_CUSTOM_OPS
#define OURLANG_DIALECT_CUSTOM_IR_CUSTOM_OPS

include "mlir/Interfaces/SideEffectInterfaces.td"
include "mlir/Interfaces/ControlFlowInterfaces.td"

include "ourlang/Dialect/Custom/IR/CustomDialect.td"
include "ourlang/Dialect/Custom/IR/CustomTypes.td"

class Custom_Op<string mnemonic, list<OpTrait> traits = []> :
    Op<Custom_Dialect, mnemonic, traits>;


#endif
