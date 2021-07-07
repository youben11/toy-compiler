#include "ourlang/Dialect/Custom/IR/CustomDialect.h"
#include "ourlang/Dialect/Custom/IR/CustomOps.h"
#include "ourlang/Dialect/Custom/IR/CustomTypes.h"

#define GET_TYPEDEF_CLASSES
#include "ourlang/Dialect/Custom/IR/CustomOpsTypes.cpp.inc"

using namespace mlir::ourlang::Custom;

void CustomDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "ourlang/Dialect/Custom/IR/CustomOps.cpp.inc"
      >();

  addTypes<
#define GET_TYPEDEF_LIST
#include "ourlang/Dialect/Custom/IR/CustomOpsTypes.cpp.inc"
      >();
}

::mlir::Type CustomDialect::parseType(::mlir::DialectAsmParser &parser) const {
  if (parser.parseKeyword("oct").failed())
    return ::mlir::Type();

  return OurCustomType::parse(this->getContext(), parser);
}

void CustomDialect::printType(::mlir::Type type,
                             ::mlir::DialectAsmPrinter &printer) const {
  mlir::ourlang::Custom::OurCustomType custom =
      type.dyn_cast_or_null<mlir::ourlang::Custom::OurCustomType>();
  if (custom != nullptr) {
    custom.print(printer);
    return;
  }
  printer << "unknwontype";
}