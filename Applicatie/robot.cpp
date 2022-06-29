#include "robot.hpp"
#include "servo.hpp"
#include "hwlib.hpp"


///\brief
///constructor
///\details
///constructor krijgt PWM adressen mee en maakt 2 variabelen voor elke poot van de robot
/// je kan nu elke beweeg punt apart een waarde meegeven(in graden) waar de servo heen draait
robot::robot(uint8_t F_R_Yaw_adress, uint8_t F_R_Pitch_adress,
             uint8_t F_L_Yaw_adress, uint8_t F_L_Pitch_adress,
             uint8_t R_R_Yaw_adress, uint8_t R_R_Pitch_adress,
             uint8_t R_L_Yaw_adress, uint8_t R_L_Pitch_adress) :
             
    F_R_Yaw(F_R_Yaw_adress),
    F_R_Pitch(F_R_Pitch_adress),
    
    F_L_Yaw(F_L_Yaw_adress),
    F_L_Pitch(F_L_Pitch_adress),
    
    R_R_Yaw(R_R_Yaw_adress),
    R_R_Pitch(R_R_Pitch_adress),
    
    R_L_Yaw(R_L_Yaw_adress),
    R_L_Pitch(R_L_Pitch_adress)    
    {}


void robot::F_R_Voor(){
    F_R_Pitch.write(150); //omhoog
    hwlib::wait_ms(wait_ms);
    F_R_Yaw.write(150); //naar voren
    hwlib::wait_ms(wait_ms);
    F_R_Pitch.write(180); //omlaag
    hwlib::wait_ms(wait_ms);
}

void robot::R_R_Voor(){
    R_R_Pitch.write(30); //omhoog
    hwlib::wait_ms(wait_ms);
    R_R_Yaw.write(150); //naar voren
    hwlib::wait_ms(wait_ms);
    R_R_Pitch.write(0); //omlaag
    hwlib::wait_ms(wait_ms);
}

void robot::F_L_Voor(){
    F_L_Pitch.write(50);
    hwlib::wait_ms(wait_ms);
    F_L_Yaw.write(30);
    hwlib::wait_ms(wait_ms);
    F_L_Pitch.write(80);
    hwlib::wait_ms(wait_ms);
}

void robot::R_L_Voor(){
    R_L_Pitch.write(150); //omhoog
    hwlib::wait_ms(wait_ms);
    R_L_Yaw.write(50); //naar voren
    hwlib::wait_ms(wait_ms);
    R_L_Pitch.write(180); //omlaag
    hwlib::wait_ms(wait_ms);
}

void robot::R_R_Achter(){
    R_R_Pitch.write(30); //omhoog
    hwlib::wait_ms(wait_ms);
    R_R_Yaw.write(50); //naar achter
    hwlib::wait_ms(wait_ms);
    R_R_Pitch.write(0); //omlaag
    hwlib::wait_ms(wait_ms);
}

void robot::F_R_Achter(){
    F_R_Pitch.write(150); //omhoog
    hwlib::wait_ms(wait_ms);
    F_R_Yaw.write(50); //naar achter
    hwlib::wait_ms(wait_ms);
    F_R_Pitch.write(180); //omlaag
    hwlib::wait_ms(wait_ms);
}

void robot::R_L_Achter(){
    R_L_Pitch.write(150); //omhoog
    hwlib::wait_ms(wait_ms);
    R_L_Yaw.write(130); //naar achter
    hwlib::wait_ms(wait_ms);
    R_L_Pitch.write(180); //omlaag
    hwlib::wait_ms(wait_ms);
}

void robot::F_L_Achter(){
    F_L_Pitch.write(50);
    hwlib::wait_ms(wait_ms);
    F_L_Yaw.write(130);
    hwlib::wait_ms(wait_ms);
    F_L_Pitch.write(80);
    hwlib::wait_ms(wait_ms);
}


///\brief
///loop naar voren
///\details
///doet "times" keer de naar voren beweging
void robot::walk_forward(int times){
    F_R_Yaw.write(90);  //allemaal recht
    F_L_Yaw.write(90);
    R_R_Yaw.write(90);
    R_L_Yaw.write(90);
    hwlib::wait_ms(wait_ms);
    
    for(int i=0; i<times; i++){
        F_R_Voor();
        R_R_Voor();
        F_L_Voor();
        R_L_Voor();
    
    F_R_Yaw.write(50);
    F_L_Yaw.write(130);
    R_R_Yaw.write(50);
    R_L_Yaw.write(130);
    hwlib::wait_ms(wait_ms); //allemaal naar achter 
    }
    
    F_R_Yaw.write(90);  //allemaal recht
    F_L_Yaw.write(90);
    R_R_Yaw.write(90);
    R_L_Yaw.write(90);
    hwlib::wait_ms(wait_ms);
    
}
    
    

///\brief
///loop naar achter
///\details
///doet "times" keer de naar achter beweging   
void robot::walk_backward(int times){
    int wait_ms = 300;
    F_R_Yaw.write(90);  //allemaal recht
    F_L_Yaw.write(90);
    R_R_Yaw.write(90);
    R_L_Yaw.write(90);
    hwlib::wait_ms(wait_ms);
    
    for(int i=0; i<times; i++){
        R_R_Achter();
        F_R_Achter();
        R_L_Achter();
        F_L_Achter();       
    
    F_R_Yaw.write(150);
    F_L_Yaw.write(30);
    R_R_Yaw.write(150);
    R_L_Yaw.write(50);
    hwlib::wait_ms(wait_ms); //allemaal naar voor 
    }
    
    F_R_Yaw.write(90);  //allemaal recht
    F_L_Yaw.write(90);
    R_R_Yaw.write(90);
    R_L_Yaw.write(90);
    hwlib::wait_ms(wait_ms);
    
}

void robot::turn_left(int times){
    F_R_Yaw.write(90);  //allemaal recht
    F_L_Yaw.write(90);
    R_R_Yaw.write(90);
    R_L_Yaw.write(90);
    hwlib::wait_ms(wait_ms);
    for(int i=0; i<times; i++){
    F_R_Voor();
    R_R_Voor();
    F_L_Achter();
    R_L_Achter();
    
    F_L_Yaw.write(30);
    R_L_Yaw.write(50);
    F_R_Yaw.write(50);
    R_R_Yaw.write(50);
    }
    
    F_R_Yaw.write(90);  //allemaal recht
    F_L_Yaw.write(90);
    R_R_Yaw.write(90);
    R_L_Yaw.write(90);
    hwlib::wait_ms(wait_ms);
    
}

void robot::turn_right(int times){
    F_R_Yaw.write(90);  //allemaal recht
    F_L_Yaw.write(90);
    R_R_Yaw.write(90);
    R_L_Yaw.write(90);
    hwlib::wait_ms(wait_ms);
    for(int i=0; i<times; i++){
        R_R_Achter();
        F_R_Achter();
        R_L_Voor();
        F_L_Voor();
        
    F_L_Yaw.write(130);
    R_L_Yaw.write(130);
    F_R_Yaw.write(150);
    R_R_Yaw.write(150);
    }
    F_R_Yaw.write(90);  //allemaal recht
    F_L_Yaw.write(90);
    R_R_Yaw.write(90);
    R_L_Yaw.write(90);
    hwlib::wait_ms(wait_ms);
}