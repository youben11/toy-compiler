cmake_minimum_required(VERSION 3.13)

project(ourcompiler LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")

find_package(MLIR REQUIRED CONFIG)
message(STATUS "Using MLIR cmake file from: ${MLIR_DIR}")

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Using LLVM cmake file from: ${LLVM_DIR}")

list(APPEND CMAKE_MODULE_PATH "${MLIR_CMAKE_DIR}")
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(TableGen)
include(AddLLVM)
include(AddMLIR)

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${MLIR_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_BINARY_DIR}/include)
link_directories(${LLVM_BUILD_LIBRARY_DIR})
add_definitions(${LLVM_DEFINITIONS})


#-------------------------------------------------------------------------------
# Python Configuration
#-------------------------------------------------------------------------------

include(MLIRDetectPythonEnv)
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
message(STATUS "Found Python include dirs: ${Python3_INCLUDE_DIRS}")
message(STATUS "Found Python libraries: ${Python3_LIBRARIES}")
message(STATUS "Found Python executable: ${Python3_EXECUTABLE}")

mlir_detect_pybind11_install()
find_package(pybind11 2.6 CONFIG REQUIRED)
message(STATUS "Found pybind11 v${pybind11_VERSION}: ${pybind11_INCLUDE_DIR}")
message(STATUS "Python prefix = '${PYTHON_MODULE_PREFIX}', "
                "suffix = '${PYTHON_MODULE_SUFFIX}', "
                "extension = '${PYTHON_MODULE_EXTENSION}'")

add_subdirectory(include)
add_subdirectory(lib)
add_subdirectory(python)
