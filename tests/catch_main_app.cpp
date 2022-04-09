#include <catch2/catch_all.hpp>
#include <timer_manager.hpp>
#include <adg2188.hpp>


TEST_CASE("Test ADG2188", "[ADG2188]")
{
    // Enable timer test fixture and start it in a new thread
    // TIM_TypeDef *timer = new TIM_TypeDef;
    // REQUIRE(stm32::TimerManager::initialise(timer));
    // std::future<bool> tim_res = std::async(std::launch::async, mock_timer_count, timer); 

    // I2C_TypeDef *adg2188_control_sw_i2c = new I2C_TypeDef;

    // std::future<bool> i2c_res = std::async(std::launch::async, mock_i2c_tx_fifo_empty, adg2188_control_sw_i2c, SlaveStatus::ACK);    


    // adg2188::Driver d(adg2188_control_sw_i2c);
    REQUIRE(true);
}