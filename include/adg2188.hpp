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

#ifndef __ADG2188_HPP__
#define __ADG2188_HPP__

#include <i2c_utils_ref.hpp>

// disable dynamic allocation/copying
#include <restricted_base.hpp>

namespace adg2188
{

// @brief Class to control the ADG2188 CrossPoint "Analog Switch Array"
class Driver : public RestrictedBase
{
public:
  explicit Driver(I2C_TypeDef *i2c_handle);

  // @brief prevent copy construction of the I2C handle pointer
  Driver(Driver const &other) = delete;
  // @brief prevent copy assignment of the I2C handle pointer
  Driver &operator=(Driver const &other) = delete;

  enum class XLineRead
  {
    X0 = 0x34, //  00110100
    X1 = 0x3C, //  00111100
    X2 = 0x74, //  01110100
    X3 = 0x3E, //  01111100
    X4 = 0x35, //  00110101
    X5 = 0x3D, //  00111101
    X6 = 0x75, //  01110101
    X7 = 0x7D  //  01111101
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
    open  = 0x00,
    close = 0x80,
  };

  enum class Pole
  {
    x0_to_y0 = 0x00,
    x0_to_y1 = 0x01,
    x0_to_y2 = 0x02,
    x0_to_y3 = 0x03,
    x0_to_y4 = 0x04,
    x0_to_y5 = 0x05,
    x0_to_y6 = 0x06,
    x0_to_y7 = 0x07,

    x1_to_y0 = 0x08,
    x1_to_y1 = 0x09,
    x1_to_y2 = 0x0A,
    x1_to_y3 = 0x0B,
    x1_to_y4 = 0x0C,
    x1_to_y5 = 0x0D,
    x1_to_y6 = 0x0E,
    x1_to_y7 = 0x0F,

    x2_to_y0 = 0x10,
    x2_to_y1 = 0x11,
    x2_to_y2 = 0x12,
    x2_to_y3 = 0x13,
    x2_to_y4 = 0x14,
    x2_to_y5 = 0x15,
    x2_to_y6 = 0x16,
    x2_to_y7 = 0x17,

    x3_to_y0 = 0x18,
    x3_to_y1 = 0x19,
    x3_to_y2 = 0x1A,
    x3_to_y3 = 0x1B,
    x3_to_y4 = 0x1C,
    x3_to_y5 = 0x1D,
    x3_to_y6 = 0x1E,
    x3_to_y7 = 0x1F,

    x4_to_y0 = 0x20,
    x4_to_y1 = 0x21,
    x4_to_y2 = 0x22,
    x4_to_y3 = 0x23,
    x4_to_y4 = 0x24,
    x4_to_y5 = 0x25,
    x4_to_y6 = 0x26,
    x4_to_y7 = 0x27,

    x5_to_y0 = 0x28,
    x5_to_y1 = 0x29,
    x5_to_y2 = 0x2A,
    x5_to_y3 = 0x2B,
    x5_to_y4 = 0x2C,
    x5_to_y5 = 0x2D,
    x5_to_y6 = 0x2E,
    x5_to_y7 = 0x2F,

    x6_to_y0 = 0x40,
    x6_to_y1 = 0x41,
    x6_to_y2 = 0x42,
    x6_to_y3 = 0x43,
    x6_to_y4 = 0x44,
    x6_to_y5 = 0x45,
    x6_to_y6 = 0x46,
    x6_to_y7 = 0x47,

    x7_to_y0 = 0x48,
    x7_to_y1 = 0x49,
    x7_to_y2 = 0x4A,
    x7_to_y3 = 0x4B,
    x7_to_y4 = 0x4C,
    x7_to_y5 = 0x4D,
    x7_to_y6 = 0x4E,
    x7_to_y7 = 0x4F,
  };

  bool probe_i2c();

  // @brief Tell the crosspoint IC to open or close a switch pole
  // @param sw_throw Throw::open or Throw::close
  // @param sw_pole The x and y pole configuration to throw
  // @param sw_latch Set the switch now or not
  // @return Always true
  bool write_switch(const Throw &sw_throw, const Pole &sw_pole, const Latch &sw_latch);

  // @brief Opens all switch poles.
  // @return Always true
  bool clear_all();

  // @brief Read the register. Useful for debuggin.
  // @param line The all the X poles from the switch
  // @return always True
  bool read_xline_switch_values(XLineRead line);

private:
  uint8_t i2c_addr{0xE0};

  I2C_TypeDef &m_i2c_handle;
};

} // namespace adg2188

#endif // __ADG2188_HPP__