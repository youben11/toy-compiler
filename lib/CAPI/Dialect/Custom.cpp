#include "ourlang-c/Dialect/Custom.h"
#include "ourlang/Dialect/Custom/IR/CustomDialect.h"
#include "ourlang/Dialect/Custom/IR/CustomOps.h"
#include "ourlang/Dialect/Custom/IR/CustomTypes.h"
#include "mlir/CAPI/IR.h"
#include "mlir/CAPI/Registration.h"
#include "mlir/CAPI/Support.h"

using namespace mlir::ourlang::Custom;

//===----------------------------------------------------------------------===//
// Dialect API.
//===----------------------------------------------------------------------===//

MLIR_DEFINE_CAPI_DIALECT_REGISTRATION(Custom, custom, CustomDialect)

//===----------------------------------------------------------------------===//
// Type API.
//===----------------------------------------------------------------------===//

bool customTypeIsAOurCustomType(MlirType type) {
  return unwrap(type).isa<OurCustomType>();
}

MlirType customOurCustomTypeGet(MlirContext ctx, unsigned custom) {
  return wrap(OurCustomType::get(unwrap(ctx), custom));
}
