add_mlir_dialect_library(CustomDialect
  CustomDialect.cpp
  CustomOps.cpp

  ADDITIONAL_HEADER_DIRS
  ${PROJECT_SOURCE_DIR}/include/ourlang/Dialect/Custom

  DEPENDS
  MLIRCustomOpsIncGen

  LINK_LIBS PUBLIC
  MLIRIR)

target_link_libraries(CustomDialect PUBLIC MLIRIR)
