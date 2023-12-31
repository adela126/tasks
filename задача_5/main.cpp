#include <iostream>
#include <graphics.h>
#include "figure.h"
#include <exception>

using namespace std;

void edit(fgr* t){
try{
    t->show();
    bool w1 = true;
    while(w1){
        cout << "����� �������� ������ ��������?" << endl;
        cout << "1 ������� ����� " << t->Getpoint().x << " " << t->Getpoint().y << endl;
        for (size_t i = 0; i < t->kol(); ++i){
            cout << i+2 << " " << t->getname(i) << " : " << t->getparameter(i) << endl;
        }
        cout << t -> kol() + 2 << " " << "������ ������" << endl;
        cout << t -> kol() + 3 << " " << "�������� ������" << endl;
        cout << "0 - �������" << endl;
        size_t n;
        cin >> n;
        if (n == 0) {w1 = false; }
        else if (n == 1){
            cout << "������� ���������� x � y: ";
            point pos;
            cin >> pos.x >> pos.y;
            t->setpoint(pos);
            t->show();
        }
        else if (n == t -> kol() + 2){
            t->hide();
        }
        else if (n == t -> kol() + 3){
            t->show();
        }
        else{
            cout << "������� " << t->getname(n-2) << endl;
            int V;
            cin >> V;
            t->setparameter(n-2, V);
            t->show();
        }
    }
    }
catch (const exception& e)
{
    cerr << e.what() << endl;
}

}

ostream &operator<<(ostream &os, const vector<fgr*> &v)
{
    size_t j = 0;
    for (auto &i: v) {
        os << ++j << ". " << *i << endl;
    }
    return os;
}

int main()
{
    system("color 5F");
    setlocale (LC_CTYPE, "Russian");
    int gd = CUSTOM, gm = CUSTOM_MODE(1200, 700);
    initgraph(&gd, &gm, "RGB");

    setbkcolor(FON);

    cleardevice();
try{
    vector<fgr*> v;
    bool t = true;
    while (t)
    {
        cout << "����������� ������ " << endl;
        cout << v;
        cout << "�������� ������y:\n1. ����\n2. ������\n3. �������\n4. �������������\n5. ��������� ��������� ������������ ������\n0 - �����\n";
        int n;
        cin >> n;
        switch(n)
        {
        case 1:
            {
            circle_ *c = new circle_;
            edit(c);
            v.push_back(c);
            }
            break;

        case 2:
            {
            ellipse_ *e = new ellipse_;
            edit(e);
            v.push_back(e);
            }
            break;
        case 3:
            {
            square_ *s = new square_;
            edit(s);
            v.push_back(s);
            }
            break;

        case 4:
            {
            rectangle_ *r = new rectangle_();
            edit(r);
            v.push_back(r);
            }
            break;
        case 5:
            {
                cout << "����� ������ �� ������ ���������?" << endl;
                int q;
                cin >> q;
                edit(v[q-1]);
            }

        case 0:
            t = false;
            break;

        default:
            cout << "�� ������ ��������" << endl;

        }
    }

    for (auto &i: v)
        delete i;
}
catch (const exception& e)
{
    cerr << e.what() << endl;
}
    readkey();
    closegraph();
}
