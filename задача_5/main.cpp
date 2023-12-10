#include <iostream>
#include <graphics.h>
#include "figure.h"
using namespace std;

int main()
{
    int gd = CUSTOM, gm = CUSTOM_MODE(1200, 700);
    initgraph(&gd, &gm, "RGB");

    setbkcolor(FON);

    cleardevice();

    vector<fgr*> v;

    circle_ *c = new circle_;
    v.push_back(c);

    c.show();

    for (auto &i: v)
        delete i;




    readkey();
    closegraph();
}
