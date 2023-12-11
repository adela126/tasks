#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED

#include <vector>
#include <string>
#include <exception>

#define FON rgb(204, 204,  255)

typedef struct{
    int x, y;
} point;

class fgr{
public:
    fgr(size_t n, std::string strn, bool st = false):str(strn), len(n), status(st) {}
    virtual ~fgr(){}

    void show () {paint(color); status = true; }
    void hide () {paint(FON); status = false; }

    const point& Getpoint () const {return p; }

    void setpoint (const point& p_) {
        if (status == true){
            hide();
            p = p_;
            show();
        }
        else{
            p = p_;
        }
    }

    size_t kol(){
        return len;
    }

    int getparameter(size_t i){
        if (i >= len){
            throw std::runtime_error("Выход за границу вектор\n");
        }
        return v[i];
    }

    void setparameter(size_t i, int value){
        if (i >= len) throw std::runtime_error("Изменение несуществующего параметра");
        if (status)
        {
            paint(FON);
            v[i] = value;
            paint(color);
        }
        else v[i] = value;
    }

    std::string getname(size_t i){
        if (i >= len){
            throw std::runtime_error("Выход за границу вектор\n");
        }
        return s[i];
    }
    friend std::ostream &operator<<(std::ostream &os, const fgr &f)
    {
        os << f.str << " ";
        os << "Позиция: " << f.p.x << " " << f.p.y << " ";
        for (size_t i = 0; i < f.len; ++i){
            os << f.s[i] << " " << f.v[i] << " ";
        }
        if (f.status == 1){
            os << "фигура отображена " << std::endl;
        }
        else os << "фигура скрыта " << std::endl;
        return os;
    }

protected:
    point p;
    std::vector<int> v;
    std::vector<std::string> s;
    std::string str;
    size_t len;
    bool status;
    const int color = rgb(190, 19, 225);
    virtual void paint(int c) = 0;
};

class circle_: public fgr{
public:
    circle_ (point p_ = {300, 300}, int r = 30, bool st = false): fgr(1, "Круг", st)
    {
        setpoint(p_);
        v.push_back(r);
        s.push_back("radius");
    }
private:
    void paint (int c)override {
        setcolor(c);
        circle(p.x, p.y, v[0]);
    }
};

class square_: public fgr{
public:
    square_ (point p_ = {300, 200}, int a = 30, bool st = false): fgr(1, "Квадрат", st)
    {
        setpoint(p_);
        v.push_back(a);
        s.push_back("side");
    }
private:
    void paint (int c)override {
        setcolor(c);
        rectangle(p.x - v[0]/2, p.y + v[0]/2, p.x + v[0]/2, p.y - v[0]/2);
    }
};

class ellipse_: public fgr{
public:
    ellipse_ (point p_ = {300, 100}, int a = 60, int b = 30, bool st = false): fgr(2, "Эллипс", st)
    {
        setpoint(p_);
        v.push_back(a);
        v.push_back(b);
        s.push_back("large semi-axis");
        s.push_back("small semi-axis");
    }
private:
    void paint (int c)override {
        setcolor(c);
        ellipse(p.x, p.y, 0, 360, v[0], v[1]);
    }
};

class rectangle_: public fgr{
public:
    rectangle_ (point p_ = {200, 300}, int a = 60, int b = 30, bool st = false): fgr(2, "Прямоугольник", st)
    {
        setpoint(p_);
        v.push_back(a);
        v.push_back(b);
        s.push_back("width");
        s.push_back("height");
    }
private:
    void paint (int c)override {
        setcolor(c);
        rectangle(p.x - v[0]/2, p.y + v[1]/2, p.x + v[0]/2, p.y - v[1]/2);
    }
};

#endif // FIGURE_H_INCLUDED
