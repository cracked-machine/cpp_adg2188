// MIT License

// Copyright (c) 2022 Chris Sutton

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

Driver::Driver(I2C_TypeDef *i2c_handle)
{
    // m_i2c_handle = std::unique_ptr<I2C_TypeDef>(i2c_handle);
    m_i2c_handle = i2c_handle;
    probe_i2c();
    clear_all();

    // // close/open asynchronously, i.e. one at a time
    // read_xline_switch_values(XLineRead::X2);
    // write_switch(Throw::close, Pole::x2_to_y0, Latch::set);
    // read_xline_switch_values(XLineRead::X2);
    // read_xline_switch_values(XLineRead::X1);
    // write_switch(Throw::close, Pole::x1_to_y0, Latch::set);
    // read_xline_switch_values(XLineRead::X1);
    // read_xline_switch_values(XLineRead::X2);
    // write_switch(Throw::open, Pole::x2_to_y0, Latch::set);
    // read_xline_switch_values(XLineRead::X2);
    // read_xline_switch_values(XLineRead::X1);
    // write_switch(Throw::open, Pole::x1_to_y0, Latch::set);
    // read_xline_switch_values(XLineRead::X1);

    // // close/open synchronously, i.e. at the same time
    // read_xline_switch_values(XLineRead::X1);
    // read_xline_switch_values(XLineRead::X2);
    // write_switch(Throw::close, Pole::x2_to_y0, Latch::reset);
    // write_switch(Throw::close, Pole::x1_to_y0, Latch::set);
    
    // write_switch(Throw::open, Pole::x2_to_y0, Latch::reset);
    // write_switch(Throw::open, Pole::x1_to_y0, Latch::set);
    // read_xline_switch_values(XLineRead::X1);
    // read_xline_switch_values(XLineRead::X2);    

}

bool Driver::clear_all()
{
    write_switch(Throw::open, Pole::x0_to_y0, Latch::set);
    write_switch(Throw::open, Pole::x1_to_y0, Latch::set);
    write_switch(Throw::open, Pole::x2_to_y0, Latch::set);
    write_switch(Throw::open, Pole::x3_to_y0, Latch::set);
    write_switch(Throw::open, Pole::x4_to_y0, Latch::set);
    write_switch(Throw::open, Pole::x5_to_y0, Latch::set);
    write_switch(Throw::open, Pole::x6_to_y0, Latch::set);
    write_switch(Throw::open, Pole::x7_to_y0, Latch::set);

    write_switch(Throw::open, Pole::x0_to_y1, Latch::set);
    write_switch(Throw::open, Pole::x1_to_y1, Latch::set);
    write_switch(Throw::open, Pole::x2_to_y1, Latch::set);
    write_switch(Throw::open, Pole::x3_to_y1, Latch::set);
    write_switch(Throw::open, Pole::x4_to_y1, Latch::set);
    write_switch(Throw::open, Pole::x5_to_y1, Latch::set);
    write_switch(Throw::open, Pole::x6_to_y1, Latch::set);
    write_switch(Throw::open, Pole::x7_to_y1, Latch::set);

    write_switch(Throw::open, Pole::x0_to_y2, Latch::set);
    write_switch(Throw::open, Pole::x1_to_y2, Latch::set);
    write_switch(Throw::open, Pole::x2_to_y2, Latch::set);
    write_switch(Throw::open, Pole::x3_to_y2, Latch::set);
    write_switch(Throw::open, Pole::x4_to_y2, Latch::set);
    write_switch(Throw::open, Pole::x5_to_y2, Latch::set);
    write_switch(Throw::open, Pole::x6_to_y2, Latch::set);
    write_switch(Throw::open, Pole::x7_to_y2, Latch::set);

    write_switch(Throw::open, Pole::x0_to_y3, Latch::set);
    write_switch(Throw::open, Pole::x1_to_y3, Latch::set);
    write_switch(Throw::open, Pole::x2_to_y3, Latch::set);
    write_switch(Throw::open, Pole::x3_to_y3, Latch::set);
    write_switch(Throw::open, Pole::x4_to_y3, Latch::set);
    write_switch(Throw::open, Pole::x5_to_y3, Latch::set);
    write_switch(Throw::open, Pole::x6_to_y3, Latch::set);
    write_switch(Throw::open, Pole::x7_to_y3, Latch::set);

    write_switch(Throw::open, Pole::x0_to_y4, Latch::set);
    write_switch(Throw::open, Pole::x1_to_y4, Latch::set);
    write_switch(Throw::open, Pole::x2_to_y4, Latch::set);
    write_switch(Throw::open, Pole::x3_to_y4, Latch::set);
    write_switch(Throw::open, Pole::x4_to_y4, Latch::set);
    write_switch(Throw::open, Pole::x5_to_y4, Latch::set);
    write_switch(Throw::open, Pole::x6_to_y4, Latch::set);
    write_switch(Throw::open, Pole::x7_to_y4, Latch::set);

    write_switch(Throw::open, Pole::x0_to_y5, Latch::set);
    write_switch(Throw::open, Pole::x1_to_y5, Latch::set);
    write_switch(Throw::open, Pole::x2_to_y5, Latch::set);
    write_switch(Throw::open, Pole::x3_to_y5, Latch::set);
    write_switch(Throw::open, Pole::x4_to_y5, Latch::set);
    write_switch(Throw::open, Pole::x5_to_y5, Latch::set);
    write_switch(Throw::open, Pole::x6_to_y5, Latch::set);
    write_switch(Throw::open, Pole::x7_to_y5, Latch::set);

    write_switch(Throw::open, Pole::x0_to_y6, Latch::set);
    write_switch(Throw::open, Pole::x1_to_y6, Latch::set);
    write_switch(Throw::open, Pole::x2_to_y6, Latch::set);
    write_switch(Throw::open, Pole::x3_to_y6, Latch::set);
    write_switch(Throw::open, Pole::x4_to_y6, Latch::set);
    write_switch(Throw::open, Pole::x5_to_y6, Latch::set);
    write_switch(Throw::open, Pole::x6_to_y6, Latch::set);
    write_switch(Throw::open, Pole::x7_to_y6, Latch::set);

    write_switch(Throw::open, Pole::x0_to_y7, Latch::set);
    write_switch(Throw::open, Pole::x1_to_y7, Latch::set);
    write_switch(Throw::open, Pole::x2_to_y7, Latch::set);
    write_switch(Throw::open, Pole::x3_to_y7, Latch::set);
    write_switch(Throw::open, Pole::x4_to_y7, Latch::set);
    write_switch(Throw::open, Pole::x5_to_y7, Latch::set);
    write_switch(Throw::open, Pole::x6_to_y7, Latch::set);
    write_switch(Throw::open, Pole::x7_to_y7, Latch::set);                        
    return true;
}

bool Driver::probe_i2c()
{
	bool success {true};

    // check ADG2188 is listening on 0xE0.
	if (stm32::i2c::send_addr(m_i2c_handle, i2c_addr, stm32::i2c::MsgType::PROBE) == stm32::i2c::Status::NACK) 
    {
        success = false;
    }
    return success;

}

// See page 20 of https://www.analog.com/media/en/technical-documentation/data-sheets/adg2188.pdf
bool Driver::write_switch(const Throw &sw_throw [[maybe_unused]], const Pole &sw_pole [[maybe_unused]], const Latch &sw_latch [[maybe_unused]])
{
    bool success {true};

#if not defined(X86_UNIT_TESTING_ONLY)
    // write this number of bytes: The data byte(s) AND the address byte
    stm32::i2c::set_numbytes(m_i2c_handle, 2);

    // check ADG2188 is listening on 0xE0 + 1.
	if (stm32::i2c::send_addr(m_i2c_handle, i2c_addr, stm32::i2c::MsgType::WRITE) == stm32::i2c::Status::NACK) 
    {
        success = false;
    }    

    // switch config byte
    uint8_t switch_configuration = (static_cast<uint8_t>(sw_throw) | static_cast<uint8_t>(sw_pole));
    stm32::i2c::send_byte(m_i2c_handle, switch_configuration);
    // latch byte
    if (sw_latch == Latch::set)
    {
        stm32::i2c::send_byte(m_i2c_handle, 0x01);
    }
    else
    {
        stm32::i2c::send_byte(m_i2c_handle, 0x00);
    }
    
    // Generate the stop condition
	stm32::i2c::generate_stop_condition(m_i2c_handle);
#endif

    return success;
}

// See page 22 of https://www.analog.com/media/en/technical-documentation/data-sheets/adg2188.pdf
bool Driver::read_xline_switch_values(XLineRead line [[maybe_unused]])
{
    bool success {true};

#if not defined(X86_UNIT_TESTING_ONLY)
    // write this number of bytes: The data byte(s) AND the address byte
	stm32::i2c::set_numbytes(m_i2c_handle, 2);

    // check ADG2188 is listening on 0xE0 + 1.
	if (stm32::i2c::send_addr(m_i2c_handle, i2c_addr, stm32::i2c::MsgType::WRITE) == stm32::i2c::Status::NACK) 
    {
        success = false;
    }
    // request the xline we want to read (second byte is don't care, so just repeat it)
    stm32::i2c::send_byte(m_i2c_handle, static_cast<uint8_t>(line));
    stm32::i2c::send_byte(m_i2c_handle, static_cast<uint8_t>(line));
    
    // Generate the stop condition
	stm32::i2c::generate_stop_condition(m_i2c_handle);

    // check ADG2188 is listening on 0xE0 + 0.
	if (stm32::i2c::send_addr(m_i2c_handle, i2c_addr, stm32::i2c::MsgType::READ) == stm32::i2c::Status::NACK) 
    {
        success = false;
    }    

    // receive the first byte and send back ACk to slave
    uint8_t rx_byte1 {0};
    stm32::i2c::receive_byte(m_i2c_handle, rx_byte1);
    stm32::i2c::send_ack(m_i2c_handle);

    // receive the second byte, send NACK and STOP to slave
    uint8_t rx_byte2 {0};
    stm32::i2c::receive_byte(m_i2c_handle, rx_byte2);
    stm32::i2c::send_nack(m_i2c_handle);
    
	stm32::i2c::generate_stop_condition(m_i2c_handle);
#endif
    return success;
}

} // namespace adg2188