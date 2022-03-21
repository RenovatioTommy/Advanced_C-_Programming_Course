#include <iostream>
#include "PGM.h"
#include "ImageProcessing.h"


using namespace std;

void medianFilter(int** original, int** modedFiles, int height, int width);
int swapValues(int *aPtr, int *bPtr);

int main()
{
    string fileName;
    string modedFileName;

    //Choice variables
    int choice;
    /*
    const int copy = 0 ;
    const int flipVertical = 1;
    const int flipHorizontal = 2;
    const int medianFilter = 3; 
    */

    cout << "Enter file name for operation: "; //Prompt for file name input
    cin >> fileName; //File to be operated on declared
    cout << "Enter name for the modified file: "; //Prompt for file name for the moded file
    cin >> modedFileName; //File to be saved declared

    //Get the user's desired operation
    cout << "Type 0 to 3 for operation to images: " << endl;
    cout << "(0) Copy Image\n";
    cout << "(1) Flip Vertical\n";
    cout << "(2) Flip Horizontal \n";
    cout << "(3) Mediam Filter\n";

    cout << "Type desired operation here: ";
    cin >> choice;

    if(choice < 0 || choice > 3) // Make sure the user chose correctly
    {
        cout << "Bad choice! Try again\n";
        cout << "Type desired operation here: ";
        cin >> choice;
    }
        
    //Open File set information
    if( openPGM(fileName))
    {
        // Get Image Size Information
        int width = getPGMWidth();
        int height = getPGMHeight();

        // Declare and allocate memory for data
        int** original; 
        int** modedFiles;    

        original = new int*[ height]; // make rows for the orignial 2d array 
        modedFiles = new int*[height]; // make rows for the moded 2d array

        for(int i = 0; i < height; i++){ 
            original[i] = new int[width]; // make columns for the orignial 2d array 
            modedFiles[i] = new int[width]; // make columns for the moded 2d array	              
        }
        
        // Get the data
        getPGMData(original);	

        if(choice == 0)
            {
            cout << "Performing Operation..." << endl;
            copyImage(original, modedFiles, height, width);
            cout << "Writing out the File..." << endl;
            writePGM(modedFileName, modedFiles);
            }
        else if (choice == 1)
            {
            cout << "Performing Operation..." << endl;
            verticalFlip(original, modedFiles, height, width);
            cout << "Writing out the File..." << endl;
            writePGM(modedFileName, modedFiles);
            }
        else if (choice == 2)
            {
            cout << "Performing Operation..." << endl;
            horizontalFlip(original, modedFiles, height, width);
            cout << "Writing out the File..." << endl;
            writePGM(modedFileName, modedFiles);
            }
        else if (choice == 3)
            {
            cout << "Performing Operation..." << endl;
            medianFilter(original, modedFiles, height, width);
            cout << "Writing out the File..." << endl;
            writePGM(modedFileName, modedFiles);
            }
        else
        {
            cout << "Bad choice!";
        }
        
        // Clean up memory
        cout << "Cleaning up memory...\n";
        for(int i = 0; i < height; i++){
            delete[] original[i]; 
            delete[] modedFiles[i]; 	            
        }	         
        delete original;
        delete modedFiles;
        cout << "Clean-up finished!\n";
    }
}
