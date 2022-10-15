cmake_minimum_required(VERSION 3.13)
project(mmolch_cpputils
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

add_library(mmolch_cpputils STATIC
    src/getFileContent.cpp
)
add_library(mmolch::util ALIAS mmolch_cpputils)

target_include_directories(mmolch_cpputils PUBLIC
    include
)

if(CMAKE_SOURCE_DIR MATCHES ${CMAKE_CURRENT_LIST_DIR})
    include(CTest)
    if(BUILD_TESTING)
        add_subdirectory(tests)
    endif()
endif()
