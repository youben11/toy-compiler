#ifndef OURLANG_PYTHON_DIALECTMODULES_H
#define OURLANG_PYTHON_DIALECTMODULES_H

#include <pybind11/pybind11.h>

namespace ourlang {
namespace python {

void populateDialectCustomSubmodule(pybind11::module &m);

} // namespace python
} // namespace ourlang

#endif // OURLANG_PYTHON_DIALECTMODULES_H