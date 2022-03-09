add_library(adg2188 "")
target_sources(adg2188 PRIVATE
    # put source files here
    src/adg2188.cpp
)

target_include_directories(adg2188 PRIVATE 
    inc
    ../embedded_utils/inc
    ../stm32cube_workspace/G0B1KET6N/Drivers/CMSIS/Device/ST/STM32G0xx/Include
    ../stm32cube_workspace/G0B1KET6N/Drivers/CMSIS/Include
)