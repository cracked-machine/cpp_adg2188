target_sources(${BUILD_NAME} PRIVATE
    catch_main_app.cpp
    ${CMAKE_BINARY_DIR}/embedded_utils/src/i2c_utils.cpp
)

target_include_directories(${BUILD_NAME} PRIVATE 
    .
    ${CMAKE_BINARY_DIR}/embedded_utils/include
)
