cmake_minimum_required(VERSION 3.14)

project(LogLibrary LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(LogLibrary SHARED
  include/loglibrary.h
)

set_target_properties(LogLibrary PROPERTIES LINKER_LANGUAGE CXX)

set_target_properties(LogLibrary PROPERTIES VERSION "1.0")
set_target_properties(LogLibrary PROPERTIES SOVERSION "1")
set_target_properties(LogLibrary PROPERTIES PUBLIC_HEADER include/loglibrary.h)

target_compile_definitions(LogLibrary PRIVATE LOGLIBRARY_LIBRARY)

install(TARGETS LogLibrary
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        "LogLibraryConfig.cmake"
        VERSION 1.0
        COMPATIBILITY AnyNewerVersion)


install(FILES "${CMAKE_CURRENT_BINARY_DIR}/LogLibraryConfig.cmake"
        DESTINATION lib/cmake/LogLibrary)
