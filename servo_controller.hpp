#ifndef SERVO_CONTROLLER_HPP
#define SERVO_CONTROLLER_HPP

#include "hwlib.hpp"

class servo_controller {
private:
    hwlib::target::pin_oc scl = hwlib::target::pin_oc(hwlib::target::pins::scl);
    hwlib::target::pin_oc sda = hwlib::target::pin_oc(hwlib::target::pins::sda);
    uint8_t prescale = 0x7E;
protected:
    hwlib::i2c_bus_bit_banged_scl_sda i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
    uint_fast8_t adress = 0x40;
public:
    servo_controller();
    void change_adress(uint8_t new_adress);
    void change_prescale(uint8_t new_prescale);
    void send_setup_bytes();

};

#endif // SERVO_CONTROLLER_HPP
