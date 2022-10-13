cmake_minimum_required(VERSION 3.13)
project(cpputils
    LANGUAGES CXX
)

add_library(cpputils STATIC
    src/getFileContent.cpp
)

target_include_directories(cpputils PUBLIC
    src
)

include(CTest)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
