#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

struct Theater
{
    string szName;
    int iNumTheaterScreens;
    int iNumParkingspots;
};

/*PART 4: Documenting  the Code*/
int main()
{
    Theater Theater1;

    string szBreakMessage = "*****************************\n";
    cout << "Starting movie theater simulation\n" << endl;
    
    /*PART 1: Theater Processing through User input*/
    // TODO: Get user input and print theater information
    cout << "enter theater name: ";
    getline(cin, Theater1.szName);

    cout << "enter the number of screens: ";
    cin >> Theater1.iNumTheaterScreens;

    cout << "enter the parking spots per screen: ";
    cin >> Theater1.iNumParkingspots;

    cout << endl;
    cout << "Theater Information" << endl;
    cout << szBreakMessage;
    cout << "Name: " << Theater1.szName << endl;
    cout << "Screens: " << Theater1.iNumTheaterScreens << endl;
    cout << "Total parking spots: " << Theater1.iNumParkingspots << endl;
    cout << szBreakMessage;

    /*PART 2: Debugging Now Showing*/
    // TODO: Fix code errors below
    // stringszMovie1 = "Hatchback to the Future";
    // string szMovie2 == "2001 A Honda Odyssey";
    // string szMovie3 = 'Guardians of the Ford Galaxy'    
    // cout << "\nNow Showing" << endl;
    // cout << szBreakMessage;
    // cout << szMovie1 << endl;
    // cout << szMovie2;
    // cout << szMovie2 >> endl;
    // cout << szBreakMessage;

    string szMovie1 = "Hatchback to the Future";
    string szMovie2 = "2001 A Honda Odyssey";
    string szMovie3 = "Guardians of the Ford Galaxy";    
    cout << "\nNow Showing" << endl;
    cout << szBreakMessage;
    cout << szMovie1 << endl;
    cout << szMovie2 << endl;
    cout << szMovie2 << endl;
    cout << szBreakMessage;
    
    
    /*PART 3: Pricing Simulation*/
    
    // Create the pricing categories
    const double dAdultTicket = 10.99;
    const double dSeniorTicket = 8.99;
    const double dChildTicket = 6.99;
    const double dMemeberTicket = 5.99;
    const double dMembershipFee = 6.00;
    
    // Run simulations
    cout << fixed << setprecision(2);
    cout << "\nCalculating Price Scenario 1" << endl;
    cout << szBreakMessage;
    // TODO: Do Pricing Simulation 1
    double dTotal1;
    double dTotal2;

    double dTaxedTotal1;
    double dTaxedTotal2;

    dTotal1 = (dAdultTicket * 1) + (dChildTicket * 1);
    dTotal2 = (dMemeberTicket * 2) + dMembershipFee;

    dTaxedTotal1 = dTotal1 + (dTotal1 * 0.08);
    dTaxedTotal2 = dTotal2 + (dTotal2 * 0.08);

    cout << "1 adult, 1 child ticket before tax: $" << dTotal1 << endl; 
    cout << "1 adult, 1 child ticket after tax: $" << dTaxedTotal1 << endl;

    cout << "\n2 Member tickets before tax: $" << dTotal2 << endl;
    cout << "2 Member tickets after tax: $" << dTaxedTotal2 << endl;

    if (dTaxedTotal1 > dTaxedTotal2)
        cout << "\nprice difference: $" << dTaxedTotal1 - dTaxedTotal2 << endl;
    else 
        cout << "\nprice difference: $" << dTaxedTotal2 - dTaxedTotal1 << endl;
    cout << szBreakMessage;
    
    cout << "\nCalculating Price Scenario 2" << endl;
    cout << szBreakMessage;
    // TODO: Do Pricing Simulation 2
    cout << szBreakMessage;

    cout << "\nCalculating Price Scenario 3" << endl;
    cout << szBreakMessage;
    // TODO: Do Pricing Simulation 3
    cout << szBreakMessage;
    
    cout << "\nFinished simulation" << endl;
}