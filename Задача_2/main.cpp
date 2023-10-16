#include <iostream>
#include "Vector1.h"

using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4};
    vector_<int, 4> v(a);
    cout << v;
    /*vector_<int, 3> v, v1;
    cin >> v >> v1;
    cout << v * v1;*/
}
