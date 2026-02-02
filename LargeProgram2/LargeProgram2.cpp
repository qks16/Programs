/*********************************************************************
File name: LargeProgram2
Author: <Jeremiah Mederios>(<A05358640>)
Date: 3/29/2024

Purpose:
    Improvment to the Movie Theater Simulation program
Command Parameters:
    none
Input:
    szPath - name of the file the user wants the program to read for theater information
    iChoice - the number in the main menu the user wants to access
    szName -  name of the person buying the tickets for the buying tickets program
    cChoice - character that dictates if the person buying tickets wants to be become a member or not
    iNumTickets - number of member tickets the buyer wants to perchase
    iNumAdults - number of adult tickets the buyer wants to purchase
    iNumsenior - number of senior tickets the buyer wants to purchase
    iNumchild - number of child tickets the buyer wants to purchase
    szpassword - the admin password inputted by the user
    iAdminChoice - the number in the admin menu the user wants to access
Results:
    -
Notes:
    -
*********************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cctype>

#include <string>

using namespace std;


struct Theater
{
    string szName;              // Name of the theater
    int iScreens;               // Number of screen         
    int iParkingSpots;          // Number of spots for each screen

    double dAdultPrice;         // Ticket price for an adult
    double dSeniorPrice;        // Ticket price for an senior
    double dChildPrice;         // Ticket price for a child
    double dMembersPrice;       // Ticket price for a theater member
    double dMembershipPrice;    // Theater membership fee

    
};

int main()
{
    cout << fixed << setprecision(2);
    
    // Create variables
    string szBreakMessage = "*****************************\n"; //premade call for the line breaks in the outputs
    string szAdminPass = "cars"; //string for the admin password
    const double dSALES_TAX = .08; //value in the progam for the sales tax
    double dTotalSales = 0; //value for the total ticket sales
    
    string szMovie1 = "Gone in 80 Seconds"; // name for the first movie in the program
    string szMovie2 = "Guardians of the Ford Galaxy"; // name for the second movie in the program
    string szMovie3 = "Marvel: The Dodge Avenger";  // name for the third movie in the program
    
    string szPath; //the file the user wants the program to read for theater information

    //start of the movie theater simulation
    cout << "Starting movie theater simulation\n" << endl;

    ifstream fin;
    ofstream fout;

    //Part 1: Theater Information from a File
    fin.open(szPath);
    
    while(fin.fail())
    {
        cout << "please enter theater file path: ";
        getline(cin, szPath);

        if(szPath.find(".txt") != string::npos)
        {
            fin.open(szPath);
            
            if(fin.fail())
            {
                cout << szPath << " does not exist\n" << endl;
                continue;
            }
        }else if(szPath == "exit")
        {
            return 0;
        }else
        {
            cout << "Please enter a valid file path\n" << endl;
        }
    
    }

    Theater theater1;

    getline(fin, theater1.szName);
    fin >> theater1.iScreens;
    fin >> theater1.iParkingSpots;
    fin >> theater1.dAdultPrice;
    fin >> theater1.dSeniorPrice;
    fin >> theater1.dChildPrice;
    fin >> theater1.dMembersPrice;
    fin >> theater1.dMembershipPrice;
    fin.close();

    szPath = "null";

    int iChoice = 0; //the number in the main menu the user wants to access
    int iattemtpts = 0; //incorrect password attempts made by the user during the programs runtime

    
    //Part 2: Sentinel Controlled Loo
    do
    {

        cout << "\nmenu" << endl;
        cout << szBreakMessage;
        cout << "1. Display theater information" << endl;
        cout << "2. Display now showing" << endl;
        cout << "3. Run price simulation" << endl;
        cout << "4. Buy tickets" << endl;
        cout << "5. Admin menu" << endl;
        cout << "-1. Exit program" << endl;
        cout << szBreakMessage;

        cout << "\nEnter choice: ";
        cin >> iChoice;

        //Part 3: Creating User Menu Options
        switch(iChoice)
        {
            case 1:
            {
                //display Theater Information
                cout << "\nTheater Information" << endl;
                cout << szBreakMessage;
                cout << "Name: " << theater1.szName << endl;
                cout << "Screens: " << theater1.iScreens << endl;
                cout << "Total parking spots: " << theater1.iParkingSpots * theater1.iScreens << endl;
                cout << szBreakMessage;

                break;
            }
            case 2:
            {
                //display now showing section
                string szMovie1 = "Hatchback to the Future"; // name for the first movie in the program
                string szMovie2 = "2001 A Honda Odyssey"; // name for the second movie in the program
                string szMovie3 = "Guardians of the Ford Galaxy"; // name for the third movie in the program 
                cout << "\nNow Showing" << endl;
                cout << szBreakMessage;
                cout << szMovie1 << endl;
                cout << szMovie2 << endl;
                cout << szMovie2 << endl;
                cout << szBreakMessage;
                break;
            }
            case 3:
            {
                // Create the pricing categories
                const double ADULT_TICKET = theater1.dAdultPrice; //adult ticket price
                const double SENIOR_TICKET = theater1.dSeniorPrice; //senior ticket price
                const double CHILD_TICKET = theater1.dChildPrice; // child ticket price
                const double MEMBER_TICKET = theater1.dMembersPrice; // member ticket price
                const double MEMBERSHIP_FEE = theater1.dMembershipPrice; // memebership fee price
                
                // Run simulations
                //start price scenario 1
                cout << fixed << setprecision(2);
                cout << "\nCalculating Price Scenario 1" << endl;
                cout << szBreakMessage;
                // TODO: Do Pricing Simulation 1
                double dTotalCost1 = 0; //cost for purchasing the tickets at regular price before tax
                double dTotalCost2 = 0; //cost for purchasing the tickets at member price before tax

                double dTaxedTotalCost1 = 0; //cost for purchasing the tickets at regular price after tax
                double dTaxedTotalCost2 = 0; //cost for purchasing the tickets at member price after tax

                //calcuate total cost for purchasing the tickets at regular price before tax
                dTotalCost1 = (ADULT_TICKET * 1) + (CHILD_TICKET * 1);
                //calculate total cost for purchasing the tickets at member price before tax
                dTotalCost2 = (MEMBER_TICKET * 2) + MEMBERSHIP_FEE;

                //calcuate total cost for purchasing the tickets at regular price after tax
                dTaxedTotalCost1 = dTotalCost1 + (dTotalCost1 * dSALES_TAX);
                //calcuate total cost for purchasing the tickets at member price after tax
                dTaxedTotalCost2 = dTotalCost2 + (dTotalCost2 * dSALES_TAX);

                //display total cost for purchasing the tickets at regular price before and after tax for the given scenario
                cout << "1 adult, 1 child ticket before tax: $" << dTotalCost1 << endl; 
                cout << "1 adult, 1 child ticket after tax: $" << dTaxedTotalCost1 << endl;

                //display total cost for purchasing the tickets at member price before and after tax for the given scenario
                cout << "\n2 Member tickets before tax: $" << dTotalCost2 << endl;
                cout << "2 Member tickets after tax: $" << dTaxedTotalCost2 << endl;

                //display the absolute price difference between the total cost of each scenario after tax
                if (dTaxedTotalCost1 > dTaxedTotalCost2)
                    cout << "\nprice difference: $" << dTaxedTotalCost1 - dTaxedTotalCost2 << endl;
                else 
                    cout << "\nprice difference: $" << dTaxedTotalCost2 - dTaxedTotalCost1 << endl;
                cout << szBreakMessage;
                
                //start pricing scenario 2
                cout << "\nCalculating Price Scenario 2" << endl;
                cout << szBreakMessage;
                // TODO: Do Pricing Simulation 2
                //calcuate total cost for purchasing the tickets at regular price before tax
                dTotalCost1 = (ADULT_TICKET * 2);
                //calcuate total cost for purchasing the tickets at member price before tax
                dTotalCost2 = (MEMBER_TICKET * 2) + MEMBERSHIP_FEE;

                //calcuate total cost for purchasing the tickets at regular price after tax
                dTaxedTotalCost1 = dTotalCost1 + (dTotalCost1 * dSALES_TAX);
                //calcuate total cost for purchasing the tickets at member price after tax
                dTaxedTotalCost2 = dTotalCost2 + (dTotalCost2 * dSALES_TAX);

                //display total cost for purchasing the tickets at regular price before and after tax for the given scenario
                cout << "2 adult tickets before tax: $" << dTotalCost1 << endl; 
                cout << "2 adult tickets after tax: $" << dTaxedTotalCost1 << endl;

                //display total cost for purchasing the tickets at member price before and after tax for the given scenario
                cout << "\n2 Member tickets before tax: $" << dTotalCost2 << endl;
                cout << "2 Member tickets after tax: $" << dTaxedTotalCost2 << endl;

                //display the absolute price difference between the total cost of each scenario after tax
                if (dTaxedTotalCost1 > dTaxedTotalCost2)
                    cout << "\nprice difference: $" << dTaxedTotalCost1 - dTaxedTotalCost2 << endl;
                else 
                    cout << "\nprice difference: $" << dTaxedTotalCost2 - dTaxedTotalCost1 << endl;
                cout << szBreakMessage;

                //start price scenarion 3
                cout << "\nCalculating Price Scenario 3" << endl;
                cout << szBreakMessage;
                // TODO: Do Pricing Simulation 3
                //calcuate total cost for purchasing the tickets at regular price before tax
                dTotalCost1 = (ADULT_TICKET * 1) + (SENIOR_TICKET *1) + (CHILD_TICKET * 1);

                //calcuate total cost for purchasing the tickets at member price before tax
                dTotalCost2 = (MEMBER_TICKET * 3) + MEMBERSHIP_FEE;

                //calcuate total cost for purchasing the tickets at regular price after tax
                dTaxedTotalCost1 = dTotalCost1 + (dTotalCost1 * dSALES_TAX);
                //calcuate total cost for purchasing the tickets at member price after tax
                dTaxedTotalCost2 = dTotalCost2 + (dTotalCost2 * dSALES_TAX);

                //display total cost for purchasing the tickets at regular price before and after tax for the given scenario
                cout << "1 adult, 1 senior, 1 child ticket before tax: $" << dTotalCost1 << endl; 
                cout << "1 adult, 1 senior, 1 child ticket after tax: $" << dTaxedTotalCost1 << endl;

                //display total cost for purchasing the tickets at member price before and after tax for the given scenario
                cout << "\n3 Member tickets before tax: $" << dTotalCost2 << endl;
                cout << "3 Member tickets after tax: $" << dTaxedTotalCost2 << endl;

                //display the absolute price difference between the total cost of each scenario after tax
                if (dTaxedTotalCost1 > dTaxedTotalCost2)
                    cout << "\nprice difference: $" << dTaxedTotalCost1 - dTaxedTotalCost2 << endl;
                else 
                    cout << "\nprice difference: $" << dTaxedTotalCost2 - dTaxedTotalCost1 << endl;
                cout << szBreakMessage;
                break;
            }
            case 4:
            {
                string szName; //name of the person buying the tickets for the buying tickets program
                string szMemberName; // names already in the members.txt file
                char cChoice = 'N'; //character that dictates if the person buying tickets wants to be become a member or not

                const double ADULT_TICKET = theater1.dAdultPrice; //adult ticket price
                const double SENIOR_TICKET = theater1.dSeniorPrice; //senior ticket price
                const double CHILD_TICKET = theater1.dChildPrice; // child ticket price
                const double MEMBER_TICKET = theater1.dMembersPrice; // member ticket price
                const double MEMBERSHIP_FEE = theater1.dMembershipPrice; // memebership fee price

                cout << "\nBuying Tickets" << endl;
                cout << szBreakMessage;

                fin.open("members.txt");

                cout << "Enter your name: ";
                cin >> szName;
                    
                while(fin >> szMemberName)
                {    
                    if(szMemberName == szName)
                    {
                        int iNumTickets = 0; //numeber of member tickets the buyer wants to perchase
                        double dTotalPrice = 0;
                        cout << "welcome " << szName << endl;
                        cout << "# of member tickets: ";
                        cin >> iNumTickets;

                        dTotalPrice = (MEMBER_TICKET * iNumTickets) + (MEMBER_TICKET * iNumTickets) * dSALES_TAX;

                        cout << "\nTotal Price: " << dTotalPrice << endl;
                        cout << szBreakMessage;
                        cChoice = 'Y';
                    }
                } 
                    
                    //WORK TO Be Done HEREEE!!!
                if(cChoice != 'Y')
                {
                    cout << "Do you want to become a member(Y/N)?: ";
                    cin >> cChoice;
            
                    if(cChoice == 'Y' || cChoice == 'y')
                    {
                        int iNumTickets = 0; //numeber of member tickets the buyer wants to perchase
                        double dTotalPrice = 0;

                        fout.open("members.txt");
                        fout << szName << endl;
                        fout.close();

                        cout << "# of member tickets: ";
                        cin >> iNumTickets;

                        dTotalPrice = (MEMBER_TICKET * iNumTickets + MEMBERSHIP_FEE) + (MEMBER_TICKET * iNumTickets + MEMBERSHIP_FEE)* dSALES_TAX;

                        cout << "\nTotal Price: " << dTotalPrice << endl;
                        cout << szBreakMessage;
                    }else
                    {
                        int iNumAdults = 0; //number of adult tickets the buyer wants to purchase
                        int iNumSenior = 0; //number of senior tickets the buyer wants to purchase
                        int iNumChild = 0; //number of child tickets the buyer wants to purchase
                        double dTotalPrice = 0;
                        
                        cout << "# of adult tickets: ";
                        cin >> iNumAdults; 
                        cout << "# of senior tickets: ";
                        cin >> iNumSenior; 
                        
                        cout << "# of child tickets: ";
                        cin >> iNumChild; 

                        dTotalPrice = (ADULT_TICKET * iNumAdults + SENIOR_TICKET * iNumSenior + CHILD_TICKET * iNumChild) + (ADULT_TICKET * iNumAdults + SENIOR_TICKET * iNumSenior + CHILD_TICKET * iNumChild) * dSALES_TAX;

                        cout << "\nTotal Price: " << dTotalPrice << endl;
                        cout << szBreakMessage;
                    }
                }
                fin.close();
                
                break;
            }
            case 5:
            {
                string szPassword;
                int iAdminChoice = 0; //the number in the admin menu the user wants to access

                cout << "enter admin password: ";
                cin >> szPassword;

                if(szPassword == szAdminPass)
                {
                    cout << "admin access granted" << endl;

                    //Part 4: Creating Admin Menu
                    do
                    {
                        cout << "\nadmin menu" << endl;
                        cout << szBreakMessage;
                        cout << "1. Update theater information" << endl;
                        cout << "2. Display total sales" << endl;
                        cout << "3. Reset membership file" << endl;
                        cout << "4. Update admin password" << endl;
                        cout << "-1. Exit admin menu" << endl;
                        cout << szBreakMessage;

                        cout << "Enter choice: ";
                        cin >> iAdminChoice;

                        switch(iAdminChoice)
                        {
                            case 1:
                            {
    
                                while(fin.fail())
                                {
                                    cout << "please enter theater file path: ";
                                    getline(cin, szPath);

                                    if(szPath.find(".txt") != string::npos)
                                    {
                                        fin.close();
                                        fin.open(szPath);
                                        
                                        if(fin.fail())
                                        {
                                            cout << szPath << " does not exist\n" << endl;
                                            continue;
                                        }
                                    }else if(szPath == "exit")
                                    {
                                        return 0;
                                    }else
                                    {
                                        cout << "Please enter a valid file path\n" << endl;
                                    }
                                }

                                cout << "Enter theater name: ";
                                getline(cin, theater1.szName);
                                fout << theater1.szName << endl;
                                cout << "Enter number of theater screen: ";
                                cin >> theater1.iScreens;
                                fout << theater1.iScreens << endl;
                                cout << "Enter number of parking spots: ";
                                cin >> theater1.iParkingSpots;
                                fout << theater1.iParkingSpots << endl;
                                cout << "Enter adult ticket price: ";
                                cin >> theater1.dAdultPrice;
                                fout << theater1.dAdultPrice << endl;
                                cout << "Enter senior ticket price: ";
                                cin >> theater1.dSeniorPrice;
                                fout << theater1.dSeniorPrice << endl;
                                cout << "Enter child ticket price: ";
                                cin >> theater1.dChildPrice;
                                fout << theater1.dChildPrice << endl;
                                cout << "Enter member ticket price: ";
                                cin >> theater1.dMembersPrice;
                                fout << theater1.dMembersPrice << endl;
                                cout << "Enter membership fee price: ";
                                cin >> theater1.dMembershipPrice;
                                fout << theater1.dMembershipPrice << endl;

                                break;
                            }
                            case 2:
                            {
                                cout << "\nTotal ticket sales: " << dTotalSales << endl;
                                break;
                            }
                            case 3:
                            {
                                fout.close();
                                fout.open("members.txt");


                                break;
                            }
                            case 4:
                            {
                                cout << "\nEnter New Password: ";
                                cin >> szAdminPass;
                                break;
                            }
                            case -1:
                            {
                                break;
                            }
                            default:
                            {
                                break;
                            }
                        }
                    }while(iAdminChoice != -1);

                    iattemtpts = 0;
                }else
                {
                    iattemtpts++;

                    if(iattemtpts == 3)
                    {
                        cout << "Closing program due to excess password attempts.";
                        return 0;
                    }else
                    {
                        cout << "Incorrect password." << endl;
                    }
                    break;
                }
            }
            default:
            {
                break;
            }
        }
    }while(iChoice != -1);

    cout << "\nFinished simulation" << endl;

    return 0;
}