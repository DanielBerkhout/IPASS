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
public:
    robot(uint8_t F_R_Yaw, uint8_t F_R_Pitch,
          uint8_t F_L_Yaw, uint8_t F_L_Pitch,
          uint8_t R_R_Yaw, uint8_t R_R_Pitch,
          uint8_t R_L_Yaw, uint8_t R_L_Pitch);
    void walk_forward(int times);
    void walk_backward(int times);

};

#endif // ROBOT_HPP
