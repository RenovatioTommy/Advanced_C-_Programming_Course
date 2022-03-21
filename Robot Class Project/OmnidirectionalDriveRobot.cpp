#include <math.h>
#include <iostream>
#include "Robot.h"
#include "DifferentialDriveRobot.h"
#include "OmnidirectionalDriveRobot.h"
#include "MobileRobot.h"
#include "Wheel.h"

using namespace std;

OmnidirectionalDriveRobot::OmnidirectionalDriveRobot(double r, double lrDist, double fbDist) : MobileRobot("Omnidirectional Drive"), frontLeftWheel(Wheel(r,0.5*fbDist, 0.5*lrDist)), 
                        frontRightWheel(Wheel(r, 0.5*fbDist, -0.5*lrDist)), backLeftWheel(r, -0.5*fbDist, 0.5*lrDist ), backRightWheel(r, -0.5*fbDist, -0.5*lrDist), lrDist(lrDist),
                        fbDist(fbDist), wheelRadius(r){} //member initializer list




double OmnidirectionalDriveRobot::getVx()
{
    double vX;

    //get the wheel rotational veolcities
    double thetaFR = frontRightWheel.getVelocity();
    double thetaFL = frontLeftWheel.getVelocity();
    double thetaBR = backRightWheel.getVelocity();
    double thetaBL = backLeftWheel.getVelocity();

    //Implement equation 6
    vX = 0.5 * (M_PI) * wheelRadius * (thetaFL + thetaFR + thetaBL + thetaBR);

    return vX;
}

double OmnidirectionalDriveRobot::getVy()
{
    double vY;

    //get the wheel rotational velocities
    double thetaFR = frontRightWheel.getVelocity();
    double thetaFL = frontLeftWheel.getVelocity();
    double thetaBR = backRightWheel.getVelocity();
    double thetaBL = backLeftWheel.getVelocity();

    //Implement equation 7
    vY = 0.5 * (M_PI * wheelRadius) * (thetaFR + thetaBL - thetaFL - thetaBR );

    return vY;
}

double OmnidirectionalDriveRobot::getVel()
{
    double linV;
    
    // get the velocities
    double vxLin = OmnidirectionalDriveRobot::getVy();
    double vyLin = OmnidirectionalDriveRobot::getVx();

    //Square them
    double sVxLin = vxLin*vxLin;
    double sVyLin = vyLin*vyLin;

    //Implement equation 10
    linV = sqrt(sVxLin + sVyLin);

    return linV;
}

double OmnidirectionalDriveRobot::getRotVel()
{
    double rotVel;

    //get the wheel rotational velocities
    double thetaFR = frontRightWheel.getVelocity();
    double thetaFL = frontLeftWheel.getVelocity();
    double thetaBR = backRightWheel.getVelocity();
    double thetaBL = backLeftWheel.getVelocity();

    //implement equation 8
    rotVel= ((M_PI * wheelRadius) / (fbDist + lrDist)) * (thetaFR + thetaBR - thetaFL - thetaBL);

    return rotVel;
}


void OmnidirectionalDriveRobot::print() //Given print fxn
{
    MobileRobot::print();
    cout << endl;
    cout << "--------------------------------------" << endl;
    cout << "----------------Wheels----------------" << endl;
    cout << "--------------------------------------" << endl;

    cout << "Front Left Wheel: " << endl;
    frontLeftWheel.print();
    cout << "--------------------------------------" << endl;

    cout << "Front Right Wheel: " << endl;
    frontRightWheel.print();
    cout << "--------------------------------------" << endl;

    cout << "Back Left Wheel: " << endl;
    backLeftWheel.print();
    cout << "--------------------------------------" << endl;

    cout << "Back Right Wheel: " << endl;
    backRightWheel.print();

    cout << endl;

    cout << "--------------------------------------" << endl;
    cout << "--------------Robot State-------------" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Linear Velocity:\t"		<< getVel()		<<  " m/s" << endl;
    cout << "Rotational Velocity:\t" << getRotVel()	<< " rad/s" << endl;
    cout << "Vx:\t\t\t" << getVx() << " m/s" << endl;
    cout << "Vy:\t\t\t" << getVy() << " m/s" << endl;
    cout << "--------------------------------------" << endl;

}

void OmnidirectionalDriveRobot::setFrontLeftWheelVelocity(double velocity)
{   
    //set the velocity of front left wheel
    this->frontLeftWheel.setVelocity(velocity);
}

void OmnidirectionalDriveRobot::setFrontRightWheelVelocity(double velocity)
{
    // set the velocity of front right wheel
    this->frontRightWheel.setVelocity(velocity);
}

void OmnidirectionalDriveRobot::setBackLeftWheelVelocity(double velocity)
{   
    // set the velocity of back left wheel
    this->backLeftWheel.setVelocity(velocity);
}

void OmnidirectionalDriveRobot::setBackRightWheelVelocity(double velocity)
{
    // set the velocity of back right wheel
    this->backRightWheel.setVelocity(velocity);
}

