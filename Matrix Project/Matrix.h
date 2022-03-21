#ifndef MATRIX_H_
#define MATRIX_H_
#include <iostream>
using namespace std;

class Matrix
{
    private:
    int rows, cols; //private int for rows and cols
    double** data; //private double for the data
    
    public:

        Matrix(const Matrix &another); //copy constructor

        //Overloading the addition operator
        Matrix operator+(const Matrix &another);

        //Overloading subtraction operator
        Matrix operator-(const Matrix &another);

        //Overloading addition assignment operator
        Matrix operator+=(const Matrix &another);

        //Overloading subtraction assignement operator
        Matrix operator-=(const Matrix &another);

        //Overloading multiplication operator
        Matrix operator*(const Matrix &another);

        //Ovrloaded frnd fxn stream insertion
        
        friend ostream &operator<<(ostream &os, const Matrix &another); // idiosynchratic method of insertion ostream

        //Overloading stream extraction
        friend istream& operator>>(istream& is, const Matrix &another);

        //memory allocation
        Matrix(int, int); 

        ~Matrix(); // destructor

};

#endif