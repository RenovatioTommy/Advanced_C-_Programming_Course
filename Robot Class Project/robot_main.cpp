#include <iostream>
#include "Robot.h"
#include "DifferentialDriveRobot.h"
#include "OmnidirectionalDriveRobot.h"
#include "MobileRobot.h"
#include "Wheel.h"

using namespace std;

const int ROBOT_TYPE_DIFF = 1;
const int ROBOT_TYPE_OMNI = 2;

int main(void)
{

	MobileRobot* robot;

	do{
		int type;
		double radius;

		cout << "Select Robot Type: \n";
		cout << "(1) Differential Drive \n";
		cout << "(2) Omnidirectional Drive \n";
		cout << "Enter Selection: ";
		cin >> type;

		switch(type)
		{
		case ROBOT_TYPE_DIFF:
			// Query for Diff wheel radius and distances
			double wheelDist;
			cout << "Enter Wheel Radius: ";
			cin >> radius;

			cout << "Enter Distance Between Wheels: ";
			cin >> wheelDist;

			// Create differential robot
			robot = new DifferentialDriveRobot(radius,wheelDist);

			do{
				// Query for the wheel velocities
				double lVel, rVel;
				cout << "Enter Left Wheel Velocity (rev/s): ";
				cin >> lVel;
				cout << "Enter Right Wheel Velocity (rev/s):";
				cin >> rVel;

				DifferentialDriveRobot* diff = dynamic_cast<DifferentialDriveRobot*>(robot);

				// Downcast to an Diff robot and set the wheel velocities
				if( diff ){
					diff->setLeftWheelVelocity(lVel);
					diff->setRightWheelVelocity(rVel);
				}else{
					cout << "Bad Diff Robot, check config\n";
				}

				// Use generic robot print
				robot->print();

				cout << "Try different velocities (y/n)? "; 
				cin.sync();
			}while( cin.get() != 'n' );

			break;

		case ROBOT_TYPE_OMNI:

			// Query for Omni wheel radius and distances
			double lrDist;
			double fbDist;

			cout << "Enter Wheel Radius: ";
			cin >> radius;

			cout << "Enter Distance Between Left-Right Wheels: ";
			cin >> lrDist;

			cout << "Enter Distance Between Front-Back Wheels: ";
			cin >> fbDist;

			// Create Omni Robot
			robot = new OmnidirectionalDriveRobot(radius,lrDist, fbDist);

			do{
				// Query for the wheel velocities
				double flVel, frVel, blVel, brVel;
				cout << "Enter Front Left Wheel Velocity (rev/s): ";
				cin >> flVel;
				cout << "Enter Front Right Wheel Velocity (rev/s):";
				cin >> frVel;
				cout << "Enter Back Left Wheel Velocity (rev/s): ";
				cin >> blVel;
				cout << "Enter Back Right Wheel Velocity (rev/s):";
				cin >> brVel;

				// Downcast to an Omni robot and set the wheel velocities
				OmnidirectionalDriveRobot* omni = dynamic_cast<OmnidirectionalDriveRobot*>(robot);
				if(  omni ) {
					omni->setFrontLeftWheelVelocity(flVel);
					omni->setFrontRightWheelVelocity(frVel);
					omni->setBackLeftWheelVelocity(blVel);
					omni->setBackRightWheelVelocity(brVel);
				}else{
					cout << "Bad Omni Robot, check config\n";
				}

				// Use generic robot print
				robot->print();

				cout << "Try different velocities (y/n)? "; 
				cin.sync();
			}while( cin.get() != 'n' );

			break;

		}

		cout << "Try different model (y/n)? ";
		cin.sync();
	}while( cin.get() != 'n' );

	delete robot;

	return 0;
}


