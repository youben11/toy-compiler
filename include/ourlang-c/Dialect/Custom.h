#ifndef OURLANG_C_DIALECT_CUSTOM_H
#define OURLANG_C_DIALECT_CUSTOM_H

#include "mlir-c/IR.h"
#include "mlir-c/Registration.h"

#ifdef __cplusplus
extern "C" {
#endif

MLIR_DECLARE_CAPI_DIALECT_REGISTRATION(Custom, custom);

MLIR_CAPI_EXPORTED MlirType customOurCustomTypeGet(MlirContext context,
                                                     unsigned custom);

MLIR_CAPI_EXPORTED bool customTypeIsAOurCustomType(MlirType);

#ifdef __cplusplus
}
#endif

#endif // OURLANG_C_DIALECT_CUSTOM_H
