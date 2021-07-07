#include "DialectModules.h"

#include "mlir-c/Bindings/Python/Interop.h"
#include "mlir-c/Registration.h"
#include "mlir/Bindings/Python/PybindAdaptors.h"
#include "ourlang-c/Dialect/Custom.h"

#include "llvm-c/ErrorHandling.h"
#include "llvm/Support/Signals.h"

#include <pybind11/pybind11.h>
namespace py = pybind11;

PYBIND11_MODULE(_ourlang, m) {
  m.doc() = "todo";
  llvm::sys::PrintStackTraceOnErrorSignal(/*argv=*/"");
  LLVMEnablePrettyStackTrace();

  m.def(
      "register_dialects",
      [](py::object capsule) {
        // Get the MlirContext capsule from PyMlirContext capsule.
        auto wrappedCapsule = capsule.attr(MLIR_PYTHON_CAPI_PTR_ATTR);
        MlirContext context = mlirPythonCapsuleToContext(wrappedCapsule.ptr());

        // Collect Ourlang dialects to register.
        MlirDialectHandle custom = mlirGetDialectHandle__custom__();
        mlirDialectHandleRegisterDialect(custom, context);
        mlirDialectHandleLoadDialect(custom, context);
      },
      "Register Ourlang dialects on a PyMlirContext.");

  py::module custom = m.def_submodule("_custom", "Custom API");
  ourlang::python::populateDialectCustomSubmodule(custom);
}