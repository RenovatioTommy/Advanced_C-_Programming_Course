int selectionSort(int *numbers, int N); //prototyping
int swapValues(int *aPtr, int *bPtr);

void copyImage(int** original, int** modedFiles, int height, int width)
{
    for(int i = 0; i < height; i++) //Traversing the 2D array with rows first
    {
        for(int j = 0; j < width; j++) //Traversing the 2D array with columns second
        {
            modedFiles[i][j] = original[i][j]; // copying elementwise
        }
    }
}

void horizontalFlip(int** original, int** modedFiles, int height, int width) 
{
  for(int i = 0; i < height; i++) //Traversing the 2D array with rows first
    {
        for(int j = 0; j < width; j++) //Traversing the 2D array with columns second
        {
            modedFiles[i][j] = original[i][(width-1)-j]; // horiontal flip elementwise
        }
    }
}

void verticalFlip(int** original, int** modedFiles, int height, int width)
{
    for(int i = 0; i < height; i++) //Traversing the 2D array with rows first
    {
        for(int j = 0; j < width; j++) //Traversing the 2D array with columns second
        {
            modedFiles[i][j] = original[(height-1)-i][j]; // vertical flip elementwise
        }
    }
}

void medianFilter(int** original, int** modedFiles, int height, int width)
{
    const unsigned int N = 9;
    int median;
    int square[N*N]; // 

    // Copy the edge case elements before applying filter

    //copying the left edge
    for(int i = 0; i < height; i++) //Traversing the 2D array with rows first
    {
        for(int j = 0; j < 4; j++) //Traversing the 2D array with columns second
        {
            modedFiles[i][j] = original[i][j]; // copying elementwise
        }
    }

    //copying right edge
      for(int i = 0; i < height; i++) //Traversing the 2D array with rows first
    {
        for(int j = (width -5); j < width; j++) //Traversing the 2D array with columns second
        {
            modedFiles[i][j] = original[i][j]; // copying elementwise
        }
    }

    //copying the top edge
     for(int i = 0; i < 4; i++) //Traversing the 2D array with rows first
    {
        for(int j = 0; j < width; j++) //Traversing the 2D array with columns second
        {
            modedFiles[i][j] = original[i][j]; // copying elementwise
        }
    }

    
      //copying the bottom edge
     for(int i = (height -5); i < height; i++) //Traversing the 2D array with rows first
    {
        for(int j = 0; j < width; j++) //Traversing the 2D array with columns second
        {
            modedFiles[i][j] = original[i][j]; // copying elementwise
        }
    }
    

    
    for(int i = 0; i < (height-N); i++) //Traversing the 2D array with rows first
    {
        for(int j = 0; j < (width-N); j++) //Traversing the 2D array with columns second
        {
         int sC = 0; //squareCounter as anchor for the 9x9 square
            for(int l = 0; l < N; l++) //Traversing elements of the square array with rows first
            {
                for(int m = 0; m < N; m++) //Traversing the square with columns second
                {
                    square[sC] = original[i+l][j+m]; 
                    sC++;
                }
            }
            selectionSort(square, N*N); // pass the square to selection sort
            median = square[(N*N-1)/2]; // 40th element of the square is the place of the median value 
            modedFiles[i+4][j+4] = median; //middle element of square is replaced by the median     
        }
    }

  //Selection sort algorithm form Home work
}
int selectionSort(int *numbers, int N) 
{
    for (int i=0; i < N-1; i++)
    {
        int minIndex = i;
        for (int j= i+1; j < N; j++)
        {
            
            if (numbers[minIndex] > numbers[j])
                minIndex = j;
        }
        if (minIndex != i)
        swapValues(&numbers[minIndex], &numbers[i]);
    }
    return 0;
}

  //Swap algorithm form Home work
int swapValues(int *aPtr, int *bPtr)
{    
    int x;
    x = *aPtr;
    *aPtr = *bPtr;
    *bPtr = x;

    return 0;
}
