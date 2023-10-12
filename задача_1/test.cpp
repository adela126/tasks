#include "test.h"
#include <iostream>
#include <assert.h>

using namespace std;

void test_cm(){
    complex comp1(23, 15);
    complex comp2(45, -7);
    EXCEPT_EQ(comp1+comp2,  complex(68, 8));
    EXCEPT_EQ(comp1-comp2,  complex(-22, 22));
    EXCEPT_EQ(comp1*comp2,  complex(1140, 514));
    complex v(7, -4);
    complex v1(3, 2);
    //EXCEPT_EQ(v/v1, complex(1, -2));
    EXCEPT_APPR(v/v1, complex(1, -2), 0.1);

    double d =-5.2;
    EXCEPT_EQ(comp1+d,  complex(17.8, 15));
    EXCEPT_EQ(comp1-d,  complex(28.2, 15));
    double d1 = 3.6;
    EXCEPT_EQ(comp1*d1,  complex(82.8, 54));
    complex w(78, 93);
    double d2 = 3;
    EXCEPT_EQ(w/d2, complex(26, 31));

    double g = 8.1;
    EXCEPT_EQ(g+comp1,  complex(31.1, 15));
    EXCEPT_EQ(g-comp1,  complex(-14.9, -15));
    double g1 = 3.6;
    EXCEPT_EQ(g1*comp1,  complex(82.8, 54));
    double g2 = 120;
    complex t(2, 4);
    EXCEPT_EQ(g2/t, complex(12, -24));
    cout << "end";
}
