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

#include <adg2188.hpp>


namespace adg2188
{

Driver::Driver()
{
    _i2c_handle = std::unique_ptr<I2C_TypeDef>(I2C2);
    probe_i2c();
}

bool Driver::probe_i2c()
{
	bool success {true};

    // check ADG2188 is listening on 0xE0.
	if (stm32::i2c::send_addr(_i2c_handle, i2c_addr, stm32::i2c::MsgType::PROBE) == stm32::i2c::Status::NACK) 
    {
        success = false;
    }
    return success;

}

// bool Driver::read_xline_switch_values()
// {
//     bool success {true};

//     // check ADG2188 is listening on 0xE0.
// 	if (stm32::i2c::send_addr(_i2c_handle.get(), i2c_addr, stm32::i2c::MsgType::PROBE) == stm32::i2c::Status::NACK) 
//     {
//         success = false;
//     }
//     return success;
// }

} // namespace adg2188