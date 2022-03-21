#include <iostream>
#include <math.h>
#include "Robot.h"
#include "DifferentialDriveRobot.h"
#include "MobileRobot.h"
#include "Wheel.h"

using namespace std;

DifferentialDriveRobot::DifferentialDriveRobot(double r, double d) : MobileRobot("DifferentialDrive"),
leftWheel(Wheel(r,0,0.5*d)), rightWheel(Wheel(r,0,-0.5*d)), wheelDist(d), wheelRadius(r) {}

//calculated x and y from d (page 2)
double DifferentialDriveRobot::getVel()
{
    double v;

    //get the wheel velocities
    double theta_R = rightWheel.getVelocity();
    double theta_L = leftWheel.getVelocity();

    //      v = pi*r * (lVel + rVel)
    v = M_PI * wheelRadius * (theta_L + theta_R);

    return v;
}

double DifferentialDriveRobot::getRotVel()
{
    double w;

    //get the wheel rotational velocities
    double theta_R = rightWheel.getVelocity();
    double theta_L = leftWheel.getVelocity();

    //      w = ((2*pi*r)/d) * (rVel - lVel)
    w = (2 * M_PI * wheelRadius / wheelDist) * (theta_R - theta_L);

    return w;
}

double DifferentialDriveRobot::getVx()
{
    double vX;

    //get the X velocity
    double theta_R = rightWheel.getVelocity();
    double theta_L = leftWheel.getVelocity();

    // vX = v cos(w)
    vX = M_PI * wheelRadius * (theta_L + theta_R) * cos((2 * M_PI * wheelRadius / wheelDist) * (theta_R - theta_L));

    return vX;
}

double DifferentialDriveRobot::getVy()
{
    double vY;

    //get the Y velocity
    double theta_R = rightWheel.getVelocity();
    double theta_L = leftWheel.getVelocity();

    // vY = v sin(w)
    vY = M_PI * wheelRadius * (theta_L + theta_R) * sin((2 * M_PI * wheelRadius / wheelDist) * (theta_R - theta_L));

    return vY;
}

void DifferentialDriveRobot::print() //Use provided print fxn
{
    MobileRobot::print();

    cout << endl;
    cout << "--------------------------------------" << endl;
    cout << "----------------Wheels----------------" << endl;
    cout << "--------------------------------------" << endl;

    cout << "Left Wheel: " << endl;
    leftWheel.print();

    cout << "--------------------------------------" << endl;
    cout << "Right Wheel: " << endl;
    rightWheel.print();

    cout << endl;

    cout << "--------------------------------------" << endl;
    cout << "--------------Robot State-------------" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Linear Velocity:\t"<< getVel() <<  " m/s" << endl;
    cout << "Rotational Velocity:\t" << getRotVel()	<< " rad/s" << endl;
    cout << "Vx:\t\t\t" << getVx() << " m/s" << endl;
    cout << "Vy:\t\t\t" << getVy() << " m/s" << endl;
    cout << "--------------------------------------" << endl;
}

void DifferentialDriveRobot::setLeftWheelVelocity(double velocity)
{
    this->leftWheel.setVelocity(velocity);
}

void DifferentialDriveRobot::setRightWheelVelocity(double velocity)
{
    this->rightWheel.setVelocity(velocity);
}


