#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

int main()
{
    stack_ s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << s.size_() << endl;

    queue_ q;

    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    cout << q.size_() << endl;
    return 0;
}
