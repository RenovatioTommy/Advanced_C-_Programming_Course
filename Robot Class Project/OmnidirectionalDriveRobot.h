#ifndef OMNIDIRECTIONAL_DRIVE_ROBOT_H
#define OMNIDIRECTIONAL_DRIVE_ROBOT_H
#include "MobileRobot.h"
#include "Wheel.h"

class OmnidirectionalDriveRobot : public MobileRobot
{
    private: //Private Member Var
        Wheel frontLeftWheel;
        Wheel frontRightWheel;
        Wheel backLeftWheel;
        Wheel backRightWheel;
        double lrDist;
        double fbDist;
        double wheelRadius;
    
    public:
        OmnidirectionalDriveRobot(double r, double lrDist, double fbDist);
        double getVel();
        double getRotVel();
        double getVx();
        double getVy();
        void print();
        void setFrontLeftWheelVelocity(double);
        void setFrontRightWheelVelocity(double);
        void setBackLeftWheelVelocity(double);
        void setBackRightWheelVelocity(double);
        
};

#endif