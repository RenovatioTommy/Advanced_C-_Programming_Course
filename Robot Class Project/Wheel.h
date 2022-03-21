#ifndef WHEEL_H
#define WHEEL_H

class Wheel
{
    private: //Private Member Var
        double radius;
        double posX;
        double posY;
        double velocity;

    public:  //Public Member Var and fxn
        Wheel(double radius, double x, double y);
        double getRadius();
        double getX();
        double getY();
        double getVelocity();
        void setX(double x);
        void setY(double y);
        void setVelocity(double velocity);
        void print();
};

#endif