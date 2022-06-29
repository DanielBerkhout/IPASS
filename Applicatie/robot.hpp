#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "servo.hpp"

class robot {
private:
    servo F_R_Yaw;
    servo F_R_Pitch;
    
    servo F_L_Yaw;
    servo F_L_Pitch;
    
    servo R_R_Yaw;
    servo R_R_Pitch;
    
    servo R_L_Yaw;
    servo R_L_Pitch;
    
    int wait_ms = 100;
void F_R_Voor();
void F_R_Achter();
void F_L_Voor();
void F_L_Achter();
void R_R_Voor();
void R_R_Achter();
void R_L_Voor();
void R_L_Achter();

public:
    robot(uint8_t F_R_Yaw, uint8_t F_R_Pitch,
          uint8_t F_L_Yaw, uint8_t F_L_Pitch,
          uint8_t R_R_Yaw, uint8_t R_R_Pitch,
          uint8_t R_L_Yaw, uint8_t R_L_Pitch);
    void walk_forward(int times);
    void walk_backward(int times);
    void turn_left(int times);
    void turn_right(int times);

};

#endif // ROBOT_HPP
