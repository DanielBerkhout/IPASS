#include "servo_controller.hpp"
#include "hwlib.hpp"


///\brief
///constructor
///\details
///zet de PWM controller op adress 0x40 in de juiste modus 
servo_controller::servo_controller()
{
send_setup_bytes();
}



///\brief
///verander adress
///\details
///geef een nieuw/ander chip adress mee, de standaard voor deze chip is 0x40
///hoeft niet gebruikt te worden, 0x40 wordt gebruikt tenzij hiermee anders aangegeven
///setup bytes worden ook naar nieuwe adress gestuurd
void servo_controller::change_adress(uint8_t new_adress){
    adress = new_adress; ///verander adress waar tegen gepraat wordt
    servo_controller::send_setup_bytes(); ///zet juiste instelling in nieuwe adress/chip
}



///\brief
///verander prescale
///\details
///verander de oscillator snelheid, probeer een paar waarde uit tot gewenst resultaat.
///verschilt per chip, oscillators zijn niet heel precies gebouwd.
///setup wordt hierna opnieuw uitgevoerd
void servo_controller::change_prescale(uint8_t new_prescale){
    prescale = new_prescale; ///verander prescale
    servo_controller::send_setup_bytes(); ///voer aanpassing uit
}



///\brief
///verstuurt de setup bytes naar de bus
///\details
///in volgorde wordt:
///de chip in slaap modus gezet(nodig om de prescale aan te passen)
///de standaard prescale(of als aangegeven de nieuwe) ingesteld
///de chip uit slaap modus, en auto increment aan
void servo_controller::send_setup_bytes(){
{auto wtrans = hwlib::i2c_write_transaction(i2c_bus, adress);
wtrans.write(0x00); //mode register 1
wtrans.write(0xB0); //sleep bit naar 1, oscillator uit
}

{auto wtrans = hwlib::i2c_write_transaction(i2c_bus, adress);
wtrans.write(0xFE); //prescale register
wtrans.write(prescale); //prescale goed zetten, verschilt per controller omdat oscillator is niet heel precies
}

{auto wtrans = hwlib::i2c_write_transaction(i2c_bus, adress);
wtrans.write(0x00); // mode register 1
wtrans.write(0xA0); //oscillator weer aan en auto increment aan
}

hwlib::wait_ms(10); //wacht even tot de oscillator gestabiliseerd is
}