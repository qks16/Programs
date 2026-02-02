//Jeremiah Medeiros <A05358640>

//1/26/2024

// Pre-Lab 1 Assignment 

//Copy and Paste this code into your IDE and complete the requested items.
#include <iostream>

using namespace std;

int main()

{
    // 1.
    // There are a several errors with the below code
    // Fix the syntax and logical errors.

    // The Program should take two integers from the user and assign them to x and y.
    // The program should then print e to the power of 5 and u % 42

    int e;
    int u;

    cout << "Enter the value for e" << endl;
    cin >> e;

    cout << "Enter the value for u " << endl;
    cin >> u;

    e = e * e * e * e * e;

    u = u % 42;

    cout << "e to the power of 5 = " << e << endl;

    cout << "u  %  42 = " << u << endl;


    // 2.
    // Write code that takes the number of pounds the user
    // can lift (use cin), divides that number by 2.20462, and then
    // prints it to the screen. This will convert pounds to kg.
    // (200 pounds is equal to 90.7186 kilograms)

    int iPounds;
    
    cout << "Many pounds can you lift?" << endl;
    cin >> iPounds;

    float fKg = iPounds/2.20462;

    cout << iPounds << "lbs to kg is " << fKg << "kg" << endl;
    // write your code here

 

return 0;
}