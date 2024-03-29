#include <iostream>
#include "Pair.h"
#include "Pair.cpp"
using namespace std;

int main()
{
    Pair p1(5, 10);
    Pair p2(1, 2);
    // Outputs 5 and 10
    cout << p1.get1() << " " << p1.get2() << endl;
    // Outputs 1 and 2
    cout << p2.get1() << " " << p2.get2() << endl;
    Pair p3 = p2 + p1;
    // Outputs 6 and 12
    cout << p3.get1() << " " << p3.get2() << endl;
    p3 = 2 + p3;
    // Outputs 8 and 14
    cout << p3.get1() << " " << p3.get2() << endl;

    /*ANSWER: p3 = 2 + p3; does not work because the object p3 takes in 2 as a pair of numbers
    not an integer. There are two methods of 'pair', therefore, '2' passes through the first 
    parameter (non integer).
    */
}
