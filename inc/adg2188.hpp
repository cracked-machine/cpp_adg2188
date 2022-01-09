// MIT License

// Copyright (c) 2021 Chris Sutton

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __ADG2188_HPP__
#define __ADG2188_HPP__

// These are required cube-generated source files
#if defined(USE_SSD1306_HAL_DRIVER) || defined(USE_SSD1306_LL_DRIVER)

	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wvolatile"
		#include "main.h"
		#include "i2c.h"	
	#pragma GCC diagnostic pop

#endif

#include <memory>

#include <ll_i2c_utils.hpp>

namespace adg2188
{

// @brief Class to control the ADG2188 CrossPoint "Analog Switch Array" 
class Driver
{
public:
    Driver(I2C_TypeDef *i2c_handle);
    
    // @brief prevent copy construction of the I2C handle pointer
    Driver(Driver const &other) = delete;
    // @brief prevent copy assignment of the I2C handle pointer
    Driver &operator=(Driver const &other) = delete;

    enum class XLineRead
    {
        X0      = 0x34,     //  00110100
        X1      = 0x3C,     //  00111100
        X2      = 0x74,     //  01110100
        X3      = 0x3E,     //  01111100
        X4      = 0x35,     //  00110101
        X5      = 0x3D,     //  00111101
        X6      = 0x75,     //  01110101
        X7      = 0x7D      //  01111101
    };

    enum class Latch
    {
        // @brief set the latch after this switch instruction 
        set,
        // @brief do *not* set the latch after this instruction 
        reset
    };

    enum class Throw
    {
        open        = 0x00,
        close       = 0x80,        
    };

    enum class Pole
    {
        x0_to_y0    = 0x00,
        x0_to_y1    = 0x01,
        x0_to_y2    = 0x02,
        x0_to_y3    = 0x03,
        x0_to_y4    = 0x04,
        x0_to_y5    = 0x05,
        x0_to_y6    = 0x06,
        x0_to_y7    = 0x07,

        x1_to_y0    = 0x08,
        x1_to_y1    = 0x09,
        x1_to_y2    = 0x0A,
        x1_to_y3    = 0x0B,
        x1_to_y4    = 0x0C,
        x1_to_y5    = 0x0D,
        x1_to_y6    = 0x0E,
        x1_to_y7    = 0x0F,

        x2_to_y0    = 0x10,
        x2_to_y1    = 0x11,
        x2_to_y2    = 0x12,
        x2_to_y3    = 0x13,
        x2_to_y4    = 0x14,
        x2_to_y5    = 0x15,
        x2_to_y6    = 0x16,
        x2_to_y7    = 0x17,        

        x3_to_y0    = 0x18,
        x3_to_y1    = 0x19,
        x3_to_y2    = 0x1A,
        x3_to_y3    = 0x1B,
        x3_to_y4    = 0x1C,
        x3_to_y5    = 0x1D,
        x3_to_y6    = 0x1E,
        x3_to_y7    = 0x1F,

        x4_to_y0    = 0x20,
        x4_to_y1    = 0x21,
        x4_to_y2    = 0x22,
        x4_to_y3    = 0x23,
        x4_to_y4    = 0x24,
        x4_to_y5    = 0x25,
        x4_to_y6    = 0x26,
        x4_to_y7    = 0x27,

        x5_to_y0    = 0x28,
        x5_to_y1    = 0x29,
        x5_to_y2    = 0x2A,
        x5_to_y3    = 0x2B,
        x5_to_y4    = 0x2C,
        x5_to_y5    = 0x2D,
        x5_to_y6    = 0x2E,
        x5_to_y7    = 0x2F,

        x6_to_y0    = 0x30,
        x6_to_y1    = 0x31,
        x6_to_y2    = 0x32,
        x6_to_y3    = 0x33,
        x6_to_y4    = 0x34,
        x6_to_y5    = 0x35,
        x6_to_y6    = 0x36,
        x6_to_y7    = 0x37,

        x7_to_y0    = 0x38,
        x7_to_y1    = 0x39,
        x7_to_y2    = 0x3A,
        x7_to_y3    = 0x3B,
        x7_to_y4    = 0x3C,
        x7_to_y5    = 0x3D,
        x7_to_y6    = 0x3E,
        x7_to_y7    = 0x3F,
    };


    bool probe_i2c();

    bool write_switch(const Throw &sw_throw, const Pole &sw_pole, const Latch &sw_latch);
    //bool sync_set_all_switches();
    bool read_xline_switch_values(XLineRead line);



private:

    uint8_t i2c_addr { 0xE0 };
    std::unique_ptr<I2C_TypeDef> _i2c_handle;
};

} // namespace adg2188

#endif // __ADG2188_HPP__