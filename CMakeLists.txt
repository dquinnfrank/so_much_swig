# This is a CMake example for swiging a c++ class for use with python and numpy

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project (swig_ex)

# Get swig
FIND_PACKAGE(SWIG REQUIRED)
INCLUDE(${SWIG_USE_FILE})

# Get python
FIND_PACKAGE(PythonLibs)
INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_PATH})
INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_DIRS})

# Basics
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES("..")

# Flags, C++ and include numpy
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-I/usr/lib/python2.7/dist-packages/numpy/core/include")

# No swig flags
SET(CMAKE_SWIG_FLAGS "")

 # Use c++ compilier
SET_SOURCE_FILES_PROPERTIES(so_much_swig.i PROPERTIES CPLUSPLUS ON)
#SET_SOURCE_FILES_PROPERTIES(arr_print.i PROPERTIES SWIG_FLAGS "-includeall") # This breaks iostream for some reason

# Actually build
SWIG_ADD_MODULE(so_much_swig python so_much_swig.i so_much_swig.cpp)

# No idea what this does
SWIG_LINK_LIBRARIES(so_much_swig ${PYTHON_LIBRARIES})
