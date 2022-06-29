#include "servo.hpp"
#include "hwlib.hpp"
#include "servo_controller.hpp"

///\brief
///constructor
///\details
///krijgt adress mee voor PWM kanaal, verwacht eerste van de 4 bytes van PWM adress
servo::servo(uint8_t PWM_nummer):
servo_controller(),
PWM_nummer(PWM_nummer)
{}


///\brief
///write maar PWM kanaal
///\details
///write een meegegeven aantal graden naar PWM kanaal.
///graden worden automatische omgezet naar juiste waarde voor de controller
void servo::write(int degrees){
    uint16_t value = map(degrees, 0, 180, 204, 408); //vertaal graden naar PWM waarde
    byte2 = value;
    byte3 = value >> 8; //als het getal groter is dan 1 byte verdeel over 2 bytes, big endian.
    {auto wtrans = hwlib::i2c_write_transaction(i2c_bus, adress);
    wtrans.write(PWM_nummer); //verteld naar welke register(s) er geschreven worden
    wtrans.write(0x00); //eerste 2 bytes worden niet gebruikt voor PWM, is voor LED aansturing
    wtrans.write(0x00); //eerste 2 bytes worden niet gebruikt voor PWM, is voor LED aansturing
    wtrans.write(byte2);
    wtrans.write(byte3);
    }
}

///\brief
///map range naar andere range
///\details
///returned waarde in range 1 naar juiste waarde in range 2.
int servo::map(int value, int in_min = 0, int in_max = 180, int out_min = 102, int out_max = 491){
    return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min; // berekening op internet gevonden.
}