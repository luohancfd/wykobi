cmake_minimum_required (VERSION 3.0)
project(wykobi VERSION 1.0)
set(BUILD_TARGET wykobi_build)
add_executable(${BUILD_TARGET} wykobi_build.cpp)
target_include_directories(${BUILD_TARGET} PUBLIC "/usr/include/eigen3/")
target_include_directories(${BUILD_TARGET} PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
