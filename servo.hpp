#ifndef SERVO_HPP
#define SERVO_HPP

#include "servo_controller.hpp"

class servo : public servo_controller::servo_controller {
private:
uint_fast8_t byte2 = 0x00;
uint_fast8_t byte3 = 0x00;
uint16_t value = 0x00;
uint8_t PWM_nummer;
public:
    servo(uint8_t PWM_nummer);
    void write(int degree);
    int map(int value, int in_min, int in_max, int out_min, int out_max); // functie om waarde in range 1 om te zetten naar waarde in range 2

};

#endif // SERVO_HPP
