// Jeremiah Medeiros <A05358640>

// Lab 7 Prelab Assignment

// Move the indicated code into functions.

#include <iostream>
using namespace std;

void WelcomeMessage()
{
    cout << "Welcome to my fabulous rectangle area calculator!" << endl
         << "This program will take the length and width of a rectangle, and" << endl
         << "return the area of that rectangle!"
         << endl << endl;
}

double dCalculation()
{
    double area;

    int length;
    int width;

    cout << "please enter a length : ";
    cin >> length;
    cout << "please enter a width: ";
    cin >> width;
    area = static_cast<double>(length*width);
    return area;
}


int main()
{
    double area;

    int length;
    int width;

    // TODO - write a void function to print out to console this welcome message
    WelcomeMessage();


    // TODO - write a function that will prompt the length and width
    // of a rectangle. Then calculate and return the
    // rectangle area (returns a double). Remember to assign the retuned value
    // to the variable 'area'.
    area = dCalculation();
    

    // this should remain inside your main function
    cout << "Rectangle area is : " << area;

    return 0;

    }