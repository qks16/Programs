#include <iostream>

using namespace std;

void printFunction(int iArr[], int iSize)
{
    int iItemPrice = 0;

    for(int i = 0; i < iSize; i++)
    {
        cout << "Enter price for item " << i + 1 << "/" << iSize << ": ";
        cin >> iItemPrice;

        iArr[i] = iItemPrice;
    }
}

int findMax(int iArr[], int iSize)
{
    int iMax = 0;

    for(int i = 0; i < iSize; i++)
    {
        if(iArr[i] > iMax)
        {
            iMax = iArr[i];
        }
    }

    return iMax;
}

int main()
{
    const int iSize = 5;    
    int iPriceArr[iSize];

    printFunction(iPriceArr, iSize);

    cout << "The most expensive price is: " << findMax(iPriceArr, iSize) << endl;
}