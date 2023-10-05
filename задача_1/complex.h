#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <iostream>
#include <ostream>

class complex{
private:
    double re, im;
public:
    complex() { re = 0; im = 0; }
    complex(double r, double i) { re = r; im = i; }
    complex(const complex &ob){ re = ob.re; im = ob.im; }

    friend std::ostream& operator << (std::ostream& out, const complex&);
    friend std::istream& operator >> (std::istream& in, complex&);

    //complex& operator = (complex com);
    complex operator + (const complex& com) const;
    complex operator + (double com) const;
    complex operator - (const complex& com) const;
    complex operator - (double com) const;
    complex operator * (const complex&) const;
    complex operator * (double) const;
    complex operator / (const complex&) const;
    complex operator / (double) const;

    bool operator != (const complex& com) const;
    bool operator == (const complex& com) const;

    complex& operator += (const complex& a);
    complex& operator += (double a);
    complex& operator -= (const complex& a);
    complex& operator -= (double a);
    complex& operator *= (const complex& a);
    complex& operator *= (double a);
    complex& operator /= (const complex& a);
    complex& operator /= (double a);
};



#endif // COMPLEX_H_INCLUDED
