#include <math.h>
#include <iostream>
#include <string>
#include "Robot.h"

Robot::Robot(string model) : model(model){}

/*
{
    this -> model = model;
}
*/

string Robot::getModel()
{
    return model;
}

void Robot::setModel(string model)
{
    this -> model = model;
}