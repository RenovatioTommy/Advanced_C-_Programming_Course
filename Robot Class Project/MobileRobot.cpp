#include "Robot.h"
#include "MobileRobot.h"
#include <iostream>


MobileRobot::MobileRobot(string model) : Robot(model) {}

void MobileRobot::print()
{ 
    cout << "--------------------------------------" << endl;
    cout << "----------------Model-----------------" << endl;
    cout << "--------------------------------------" << endl;
    cout << "\t" << model << endl;
    cout << "--------------------------------------" << endl;

}