#include <iostream>
#include "queue.h"
#include "stack.h"

using namespace std;

int main()
{
    queue_<int> q;
    cout << q.push(4).push(5).push(6).push(7) << endl;

    queue_<int> v({4, 7, 8, 5});

    v = q;
    cout << v << endl;

    queue_<int> f(q);
    cout << f << endl;
    return 0;
}
