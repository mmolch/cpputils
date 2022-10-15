cmake_minimum_required(VERSION 3.13)
project(cpputils
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

add_library(cpputils STATIC
    src/BaseObject.cpp
    src/getFileContent.cpp
)

target_include_directories(cpputils PUBLIC
    src
)

if(CMAKE_SOURCE_DIR MATCHES ${CMAKE_CURRENT_LIST_DIR})
    include(CTest)
    if(BUILD_TESTING)
        add_subdirectory(tests)
    endif()
endif()
