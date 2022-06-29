#include "servo.hpp"
#include "hwlib.hpp"

///ToDo: screenshots van logic analyzer toevoegen
int wait_ms = 20;
auto servo1 = servo(0x06); ///maak object voor servo, intialiseer
servo1.write(100); ///stuur servo naar 100 graden
hwlib::wait_ms(wait_ms);
servo1.write(0); //maximum berijk van servo
hwlib::wait_ms(wait_ms);
servo1.write(180); //maximum berijk van servo
hwlib::wait_ms(wait_ms);
servo1.write(-50); //gebeurt niks, dit is buiten berijk van deze servo
hwlib::wait_ms(wait_ms);
servo1.write(220); //gebeurt niks, dit is buiten berijk van deze servo

servo1.change_adress(0x41); //nu wordt adress 0x41 gebruikt
servo1.write(100);          //test programma op nieuwe adress
hwlib::wait_ms(wait_ms);
servo1.write(0);
hwlib::wait_ms(wait_ms);
servo1.write(180); 
hwlib::wait_ms(wait_ms;

servo1.change_prescale(0x78); //prescale is veranderd PWM signaal klopt nu waarschijnlijk niet meer voor deze chip
servo1.write(100);          //test programma met nieuwe prescale
hwlib::wait_ms(wait_ms);
servo1.write(0);
hwlib::wait_ms(wait_ms);
servo1.write(180); 
hwlib::wait_ms(wait_ms);