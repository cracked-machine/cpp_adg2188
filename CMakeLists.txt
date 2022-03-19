# This file is for running X86 unit tests only.
cmake_minimum_required(VERSION 3.13)

project(ADG2188_TEST_SUITE VERSION 0.1 DESCRIPTION "ADG2188_TEST_SUITE")

# if this is the main project then configure the build for test_suite only
if(CMAKE_PROJECT_NAME STREQUAL ADG2188_TEST_SUITE)

    include(cmake/linux.cmake)
    
    # BUILD_NAME is set in cmake/linux.cmake
    add_executable(${BUILD_NAME} "")

    include(cmake/external.cmake)
    include(cmake/cppcheck.cmake)
    target_compile_features(${BUILD_NAME} PUBLIC cxx_std_20)

    # add catch2 test lib and unit test
    find_package(Catch2 3 REQUIRED)
    target_link_libraries(${BUILD_NAME} PRIVATE Catch2::Catch2WithMain)
    add_subdirectory(tests)

    target_include_directories(${BUILD_NAME} PRIVATE 
        ${CMAKE_BINARY_DIR}/embedded_utils/include
    )

endif()

# if this is submodule in another project then just build as standalone
add_subdirectory(src)


