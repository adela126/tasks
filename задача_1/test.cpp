#include "test.h"
#include <iostream>
#include <assert.h>

using namespace std;

void test_cm(){
    complex comp1(1, 4);
    complex comp2(1, 4);
    EXCEPT_EQ(comp1+comp2,  complex(2, 8));
    EXCEPT_EQ(comp1*comp2,  complex(-15, 8));
    EXCEPT_EQ(comp1/comp2,  complex(1, 0));

    double d =-5.2;
    EXCEPT_EQ(comp1+d,  complex(-4.2, 4));
    EXCEPT_EQ(comp1*d,  complex(-5.2, -20.8));
    EXCEPT_EQ(comp1/d,  complex(-0.192308, -0.769231));
    cout << comp1/d << endl;
    cout << "end";
}
