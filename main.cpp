// main.cpp
#include "Date.h"
#include <iostream>

using namespace std;

int main() {
    Date d1(JANUARY, 15, 2023); // TEXT mode
    d1.print(); // Output: JANUARY 15, 2023

    cout << endl;

    Date d2(12, 25, 2023); // MMDDYY mode
    d2.print(); // Output: 12/25/23

    cout << endl;

    Date d3(60, 2023); // DDDYYYY mode (day 60 = March 1)
    d3.print(); // Output: 60-3-2023

    return 0;
}