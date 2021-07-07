#ifndef OURLANG_DIALECT_CUSTOM_IR_CUSTOM_TYPES
#define OURLANG_DIALECT_CUSTOM_IR_CUSTOM_TYPES

include "ourlang/Dialect/Custom/IR/CustomDialect.td"
include "mlir/IR/BuiltinTypes.td"

class Custom_Type<string name, list<Trait> traits = []> :
  TypeDef<Custom_Dialect, name, traits> { }

def OurCustomType : Custom_Type<"OurCustom",
        [MemRefElementTypeInterface]> {
  let mnemonic = "oct";

  let summary = "todo";

  let description = [{
    TODO
  }];

  let parameters = (ins "unsigned":$custom);

  // We define the printer inline.
  let printer = [{
    $_printer << "oct<" << getImpl()->custom << ">";
  }];

  // The parser is defined here also.
  let parser = [{
    if ($_parser.parseLess())
      return Type();
    int custom;
    if ($_parser.parseInteger(custom))
      return Type();
    if ($_parser.parseGreater())
      return Type();
    return get($_ctxt, custom);
  }];
}

#endif
