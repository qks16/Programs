#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int iRandomA() {
    return rand() % 100;
}

double dRandomB() {
    return 0.25 + ((double)rand() / RAND_MAX) * 0.25;
}

double dRandomC() {
    double u = (double)rand() / RAND_MAX;

    if (u < 0.5)
        return 1.0;
    else if (u < 0.7)
        return 2.0;
    else
        return 3.0 + (double)rand() / RAND_MAX;
}

int main(int argc, char* argv[]) {
    srand(time(0));

    int i = 0;

    //output random number from all 3 functions and repeat for the number of times specified by the user through the command line argument or default to 1
    int n = 1;
    if (argc > 1) {
        n = atoi(argv[1]);
    }
    for (i = 0; i < n; i++) {
        cout << "Random A: " << iRandomA() << endl;
        cout << "Random B: " << dRandomB() << endl;
        cout << "Random C: " << dRandomC() << endl; 
        cout << endl;
    }

    return 0;
}