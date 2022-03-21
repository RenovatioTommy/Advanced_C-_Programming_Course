#ifndef ROBOT_H
#define ROBOT_H
#include <string>
using namespace std;

class Robot
{
    protected:
        string model; //Protected Member Var

    public:
        Robot(string model); //Public Member Var and fxn
        string getModel();
        void setModel(string model);
        virtual void print() = 0;

};

#endif