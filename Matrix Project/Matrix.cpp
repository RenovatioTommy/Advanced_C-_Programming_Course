#include "Matrix.h"
#include <iostream>
#include <assert.h>
using namespace std;

Matrix::Matrix(int rows, int columns)  // Constructor that takes 2 integers
{
    this->rows = rows; // make input rows and cols member vars
    this->cols = columns; //^^^^^^^^^^^^^^^^

    this->data = new double *[rows]; // allocate memory for rows

    for (int a = 0; a < rows; a++) // allocate memory for all rows
    {
            this->data[a] = new double[cols];
            // set to 0
            for (int b = 0; b < cols; b++)
                this->data[a][b] = 0;

    }
}


Matrix::Matrix(const Matrix &another) //Implement copy constructor with constant reference to another class
{
    this->rows = another.rows; //make member vars
    this->cols = another.cols; //^

    this->data = new double *[rows];  // allocate memory for rows
    for (int i = 0; i < rows; i++)
    {
        this->data[i] = new double[cols];
        // set all elements to input matrix
        for (int j = 0; j < cols; j++)
            data[i][j] = another.data[i][j];

    }
}


// idiosynchratic method of insertion ostream
ostream &operator<<(ostream &os, const Matrix &another) 
{
    for(int i=0; i<another.rows; i++)
    {
        for( int j=0; j<another.cols; j++)
        {
            os << another.data[i][j] << " ";
        } 
        os<< "\n";
    }
    return os;
}


//idiosynchratic method of extraction istream
istream &operator>>(istream &is, const Matrix &another)
{
     for (int i = 0; i < another.rows; i++)
    {
        for (int j = 0; j < another.cols; j++)
        {
            is >> another.data[i][j];
            cout << " ";
        }
        cout << endl;
    }
    return is;
}


// elementwise addition + global overloading
Matrix Matrix::operator+(const Matrix &another) 
{
    assert((this->rows == another.rows) && (this->cols == another.cols)); //size check
    this->rows = another.rows;  // make input rows and cols member vars
    this->cols = another.cols;

    Matrix C(rows, cols); //Constructor for Matrix C

    for(int i=0; i<rows; i++) //traverse rows and columns
    {
        for(int j=0; j<cols; j++)
        {
            C.data[i][j] = data[i][j] + another.data[i][j]; //elementwise addition of the indexes
        }
    }
    return C; // return the Matrix C
}

// elementwise subtraction - global overloading
Matrix Matrix::operator-(const Matrix &another) 
{
    assert((this->rows == another.rows) && (this->cols == another.cols)); //size check
    this->rows = another.rows; // make input rows and cols member vars
    this->cols = another.cols;

    Matrix B(rows, cols); //Constructor for Matrix B

    for(int i=0; i<rows; i++) //traverse rows and columns
    {
        for(int j=0; j<cols; j++)
        {
            B.data[i][j] = data[i][j] - another.data[i][j]; //elementwise subtraction of the indexes
        }
    }
    return B; // return the Matrix B
}


// elementwise addition assignment
Matrix Matrix::operator+=(const Matrix &another)
{
    assert((this->rows == another.rows) && (this->cols == another.cols));

    for(int i=0; i<rows; i++) //traverse rows and columns
    {
        for(int j=0; j<cols; j++)
        {
            data[i][j] += another.data[i][j]; //elementwise addition of the indexes
        }
    }
    return *this; // return the Matrix 
}


// elementwise subtraction assignment -= global overloading
Matrix Matrix::operator-=(const Matrix &another) 
{
    assert((this->rows == another.rows) && (this->cols == another.cols)); //check size
    Matrix D(rows, cols); //Constructor for Matrix D

    for(int i=0; i<rows; i++) //traverse rows and columns
    {
        for(int j=0; j<cols; j++)
        {
            D.data[i][j] = (data[i][j] -= another.data[i][j]); //elementwise subtraction of the indexes
        }
    }
    return D; // return the Matrix D
}


// elementwise multiplication - global overloading
Matrix Matrix::operator*(const Matrix &another) 
{
    assert(this->cols == another.rows); //check that size of rows of A equals the size cols of B
    Matrix F(rows, cols); //Constructor for Matrix F

    for(int i=0; i<rows; i++) //traverse rows and columns
    {
        for(int j=0; j<cols; j++)
        {
            for(int k=0; k<cols; k++)
            {
                F.data[i][j] += data[i][k] * another.data[k][j]; //Multiply
            
            }
        }
    }
    return F; // return the Matrix F
}


Matrix::~Matrix() // destructor
{
    for (int i = 0; i < rows; i++)// deallocate all rows
        delete[] data[i];
            
     delete[] data;// delete data
}