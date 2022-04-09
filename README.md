[![CMake](https://github.com/cracked-machine/cpp_adg2188/actions/workflows/cmake.yml/badge.svg)](https://github.com/cracked-machine/cpp_adg2188/actions/workflows/cmake.yml)
[![Codecov](https://img.shields.io/codecov/c/github/cracked-machine/cpp_adg2188)](https://app.codecov.io/gh/cracked-machine/cpp_adg2188)

### cpp_adg2188

Library for ADG2188 "Analog Switch Array" for STM32

See the [wiki](https://github.com/cracked-machine/embedded_utils/wiki) for documentation / reference

See [readme](tests) for information on unit testing/mocking.


#### Adding this library to your STM32 Project

There are two ways to add this library to your project's CMakeLists.txt:

1. Implicitly include the [external.cmake](cmake/external.cmake):

```
set(BUILD_NAME "MyProject")
add_executable(${BUILD_NAME} "")
include(cmake/external.cmake)
```

2. Explicitly add [cpp_adg2188](https://github.com/cracked-machine/cpp_adg2188.git) to your project as a submodule and add the subdirectory:

```
add_subdirectory(cpp_adg2188)
```
