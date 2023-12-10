#include <iostream>
#include <graphics.h>
#include "figure.h"
using namespace std;

int main()
{
    system("color 5F");
    setlocale (LC_CTYPE, "Russian");
    int gd = CUSTOM, gm = CUSTOM_MODE(1200, 700);
    initgraph(&gd, &gm, "RGB");

    setbkcolor(FON);

    cleardevice();

    vector<fgr*> v;
    bool t = true;
    while (t)
    {
        cout << "�������� ������y:\n1. ����\n2. ������\n3. �������\n4. �������������\n0 - �����\n";
        int n;
        cin >> n;
        switch(n)
        {
        case 1:
            {
            circle_ *c = new circle_;
            cout << "������� ���������� x � y: ";
            point pos;
            cin >> pos.x >> pos.y;
            c->setpoint(pos);
            c->show();
            v.push_back(c);
            }
            break;

        case 2:
            {
            ellipse_ *e = new ellipse_;
            cout << "������� ���������� x � y: ";
            point pos;
            cin >> pos.x >> pos.y;
            e->setpoint(pos);
            e->show();
            v.push_back(e);
            }
            break;
        case 3:
            {
            square_ *s = new square_;
            cout << "������� ���������� x � y: ";
            point pos;
            cin >> pos.x >> pos.y;
            s->setpoint(pos);
            s->show();
            v.push_back(s);
            }
            break;

        case 4:
            {
            rectangle_ *r = new rectangle_();
            cout << "������� ���������� x � y: ";
            point pos;
            cin >> pos.x >> pos.y;
            r->setpoint(pos);
            r->show();
            v.push_back(r);
            }
            break;

        case 0:
            t = false;
            break;

        default:
            cout << "�� ������ ��������" << endl;

        }
    }

    for (auto &i: v)
        delete i;




    readkey();
    closegraph();
}
