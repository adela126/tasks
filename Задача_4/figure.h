#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED

#include <ostream>
#include <cmath>
#define M_PI 3.14159265

class fgr{
public:
    virtual double S() const = 0;
    virtual double P() const = 0;

    friend std::ostream& operator << (std::ostream& stream, const fgr& f){
        f.print(stream);
        return stream;
    }
protected:
    virtual void print (std::ostream&) const = 0;
};

class circle: public fgr{
public:
    circle (double R1 = 1): R(R1) {}

    double S () const{
        return (M_PI)*R*R;
    }

    double P () const{
        return 2*(M_PI)*R;
    }

    circle& operator = (const fgr& f){
        if (this == &f) return *this;
        const circle& c = dynamic_cast <const circle&> (f);
        *this = c;
        return *this;
    }

private:
    double R;
    void print (std::ostream& stream) const{
        stream << "Окружность радиуса " << R;
    }
};

class ellipse: public fgr{
public:
    ellipse (double a1 = 1, double b1 = 1): a(a1), b(b1) {}

    double S () const{
        return (M_PI)*a*b;
    }

    double P () const{
        return (M_PI)*sqrt(2 * (a*a + b*b));
    }

    ellipse& operator = (const fgr& f){
        if (this == &f) return *this;
        const ellipse& c = dynamic_cast <const ellipse&> (f);
        *this = c;
        return *this;
    }

private:
    double a, b;
    void print (std::ostream& stream) const{
        stream << "Эллипс с большой полуосью " << a << " и маолой полуосью " << b;
    }
};

class square: public fgr{
public:
    square (double a1 = 1): a(a1) {}

    double S () const{
        return a*a;
    }

    double P () const{
        return 4*a;
    }

    square& operator = (const fgr& f){
        if (this == &f) return *this;
        const square& c = dynamic_cast <const square&> (f);
        *this = c;
        return *this;
    }

private:
    double a;
    void print (std::ostream& stream) const{
        stream << "Квадрат со стороной " << a;
    }
};

class rectangle: public fgr{
public:
    rectangle (double a1 = 1, double b1 = 1): a(a1), b(b1) {}

    double S () const{
        return a * b;
    }

    double P () const{
        return 2 * (a + b);
    }

    rectangle& operator = (const fgr& f){
        if (this == &f) return *this;
        const rectangle& c = dynamic_cast <const rectangle&> (f);
        *this = c;
        return *this;
    }

private:
    double a, b;
    void print (std::ostream& stream) const{
        stream << "Прямоугольник со сторонами " << a << " и " << b;
    }
};

#endif // FIGURE_H_INCLUDED
