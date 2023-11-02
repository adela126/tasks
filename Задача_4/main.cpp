#include <iostream>
#include <locale>
#include "figure.h"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");
    circle r(10);
    cout << r << endl;
    cout << r.S() << endl;
    cout << r.P() << endl;

    ellipse e (10, 5);
    cout << e << endl;
    cout << e.S() << endl;
    cout << e.P() << endl;

    square s (7);
    cout << s << endl;
    cout << s.S() << endl;
    cout << s.P() << endl;

    rectangle p (7, 3);
    cout << p << endl;
    cout << p.S() << endl;
    cout << p.P() << endl;
    return 0;
}
