include(AddMLIRPython)

################################################################################
# Generate dialect-specific bindings.
################################################################################

add_mlir_dialect_python_bindings(OURLANGBindingsPythonCustomOps
	TD_FILE CustomOps.td
	DIALECT_NAME Custom)
add_dependencies(OURLANGBindingsPythonSources OURLANGBindingsPythonCustomOps)


################################################################################
# Installation.
################################################################################

install(
  DIRECTORY ${PROJECT_BINARY_DIR}/python/ourlang/dialects
  DESTINATION python/ourlang
  COMPONENT OURLANGBindingsPythonDialects
  FILES_MATCHING PATTERN "_*_gen.py"
  PATTERN "__pycache__" EXCLUDE
  PATTERN "__init__.py" EXCLUDE
)

if (NOT LLVM_ENABLE_IDE)
  add_llvm_install_targets(
    install-OURLANGBindingsPythonDialects
    DEPENDS OURLANGBindingsPythonSources
    COMPONENT OURLANGBindingsPythonDialects)
endif()
