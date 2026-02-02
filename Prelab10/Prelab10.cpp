// Lab 10 Pre-Lab Assignment

// Write a function that multiplies each element in the array "myArray"
// by the variable "multiplyMe".

#include <iostream>

using namespace std;

// TODO - Write your function prototype here
void multiplyArr(int numArr[], int iSize, int imultiplyValue);

int main()
{
    const int SIZE = 10;
    int myArray [SIZE] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int multiplyMe = 5;

    // TODO - Add your function call here
    multiplyArr(myArray, SIZE, multiplyMe);


    // print the array
    for(int i=0; i < SIZE; i++)
    {
        cout << myArray[i] << " ";
    }
    cout << endl;

    return 0;

}

// TODO - Write your function definition here
void multiplyArr(int numArr[], int iSize, int imultiplyValue)
{
    for(int i = 0; i < iSize; i++)
    {
        numArr[i] = numArr[i] * imultiplyValue;
    }
}
