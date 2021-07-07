#include "DialectModules.h"

#include "ourlang-c/Dialect/Custom.h"

#include "mlir-c/BuiltinAttributes.h"
#include "mlir/Bindings/Python/PybindAdaptors.h"
#include "llvm/ADT/SmallString.h"
#include "llvm/Support/raw_ostream.h"

#include <pybind11/pybind11.h>
#include <pybind11/pytypes.h>
#include <pybind11/stl.h>
namespace py = pybind11;

using namespace ourlang;
using namespace mlir::python::adaptors;

void ourlang::python::populateDialectCustomSubmodule(py::module &m) {
  m.doc() = "todo";

  mlir_type_subclass(m, "OurCustomType", customTypeIsAOurCustomType)
      .def_classmethod("get",
                       [](py::object cls, MlirContext ctx, unsigned custom) {
                         return cls(customOurCustomTypeGet(ctx, custom));
                       });
}