
set(tests
    getFileContent
    range
)

foreach(test ${tests})
    add_executable(${test}_ctest ${test}_ctest.cpp)
    target_link_libraries(${test}_ctest mmolch_cpputils::mmolch_cpputils)
    target_link_options(${test}_ctest PRIVATE -static-libgcc -static-libstdc++)
    add_test(${test}_ctest ${test}_ctest)
endforeach()
