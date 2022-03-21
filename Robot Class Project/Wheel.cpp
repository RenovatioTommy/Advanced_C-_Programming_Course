#include <iostream>
#include "Wheel.h"

using namespace std;

Wheel::Wheel(double radius, double x, double y) : radius(radius), posX(x), posY(y){} //Member inntializer list

//Self-explanatory get and set velocity functions (accessors & mutators)
double Wheel::getRadius() 
{
    return this->radius;
}

double Wheel::getX()
{
    return this->posX;
}

double Wheel::getY()
{
    return this->posY;
}

double Wheel::getVelocity()
{
    return this->velocity;
}

void Wheel::setX(double x) 
{
    this -> posX = x;
}

void Wheel::setY(double y) 
{
    this -> posY = y;
}

void Wheel::setVelocity(double velocity)
{
    this->velocity = velocity;
}

void Wheel::print()
{   
    cout << "Position: \t(" << getX() << " m, " << getY() << " m) \n";
    cout << "Velocity: \t" << getVelocity() << " rev/s" << endl;
}