#ifndef DIFFERENTIAL_DRIVE_ROBOT_H
#define DIFFERENTIAL_DRIVE_ROBOT_H
#include "Robot.h"
#include "MobileRobot.h"
#include "Wheel.h"

class DifferentialDriveRobot : public MobileRobot
{
    private: //Private Member Var
        Wheel leftWheel;
        Wheel rightWheel;
        double wheelDist;
        double wheelRadius;

    public:
        DifferentialDriveRobot(double r, double d);
        double getVel();
        double getRotVel();
        double getVx();
        double getVy();
        void print();
        void setLeftWheelVelocity(double velocity);
        void setRightWheelVelocity(double velocity);

};

#endif