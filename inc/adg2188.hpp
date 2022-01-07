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
    Driver();
    
    // @brief prevent copy construction of the I2C handle pointer
    Driver(Driver const &other) = delete;
    // @brief prevent copy assignment of the I2C handle pointer
    Driver &operator=(Driver const &other) = delete;

    bool probe_i2c();

    bool async_set_one_switch();
    bool sync_set_all_switches();
    bool read_xline_switch_values();

private:

    uint8_t i2c_addr { 0xE0 };
    std::unique_ptr<I2C_TypeDef> _i2c_handle;
};

} // namespace adg2188

#endif // __ADG2188_HPP__