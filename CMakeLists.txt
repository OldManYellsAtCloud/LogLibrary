cmake_minimum_required(VERSION 3.14)

project(LogLibrary LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(LogLibrary SHARED
  loglibrary.h
)

set_target_properties(LogLibrary PROPERTIES LINKER_LANGUAGE CXX)

target_compile_definitions(LogLibrary PRIVATE LOGLIBRARY_LIBRARY)
