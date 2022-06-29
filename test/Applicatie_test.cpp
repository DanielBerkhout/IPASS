#include "hwlib.hpp"
#include "robot.hpp"

int main(){
auto spider_robot = robot(0x06, 0x0A, 0x0E, 0x12, 0x16, 0x1A, 0x1E, 0x22);

spider_robot.walk_forward(2); //loopt 2 stappen naar voor
spider_robot.turn_right(3); //draait 3 stappen naar rechts
spider_robot.walk_backward(2); //loopt 2 stappen naar achter
spider_robot.turn_left(3); //draait 3 stappen naar links


}