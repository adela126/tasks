#include <cmath>
#include "complex.h"

bool complex::operator != (const complex& com) const{
    if(this->re != com.re || this->im != com.im)
       return 1;
    else
        return 0;
}

bool complex::operator==(const complex& com) const{
    if(this->re == com.re && this->im == com.im)
        return 1;
    else
        return 0;
}

bool complex::operator < (const complex& com) const{
    if(this->re < com.re && this->im < com.im)
        return 1;
    else
        return 0;
}

bool complex::operator > (const complex& com) const{
    if(this->re > com.re && this->im > com.im)
        return 1;
    else
        return 0;
}

double abs_com(const complex& com){
    double d = sqrt(com.re * com.re + com.im * com.im);
    return d;
}

complex con(complex& com){
    com.im = -com.im;
    return com;
}

complex& complex::operator - (){
    re = -re;
    im = -im;
    return *this;
}

complex complex::operator + ()const{
    complex r = *this;
    return r;
}

complex complex::operator+(const complex& com) const{
    complex r = *this;
    return r += com;
}

complex complex::operator+(double com) const{
    complex r = *this;
    return r += com;
}

complex operator + (double a, const complex& com){
    complex r;
    r.re = com.re + a;
    r.im = com.im;
    return r;
}

complex complex::operator-(const complex& com) const {
    complex r = *this;
    return r -= com;
}

complex complex::operator-(double com) const{
    complex r = *this;
    return r -= com;
}

complex operator - (double a, const complex& com){
    complex r;
    r.re = a - com.re;
    r.im = - com.im;
    return r;
}

complex complex::operator*(const complex &com) const{
    complex r = *this;
    return r *= com;
}

complex complex::operator*(double com) const{
    complex r = *this;
    return r *= com;
}

complex operator * (double a, const complex& com){
    complex r;
    r.re = a * com.re;
    r.im = a * com.im;
    return r;
}

complex complex::operator/(const complex &com) const{
    complex r = *this;
    return r /= com;
}

complex complex::operator/(double com) const{
    complex r = *this;
    return r /= com;
}

complex operator / (double a, const complex& com){
    double i, j, k;
    complex c;
    k = com.re*com.re + com.im*com.im;
    i = (a * com.re)/k;
    j = (-a*com.im)/k;
    c.re = i;
    c.im = j;
    return c;
}

/*
complex& complex::operator =(complex com){
    this->re = com.re;
    this->im = com.im;
    return *this;
}
*/
std::ostream& operator << (std::ostream& out, const complex& com){
    if(com.im < 0)
        out << com.re << " + i( " << com.im << ")\n";
    else
        out << com.re << " + i" << com.im << "\n";
    return out;
}

std::istream& operator >> (std::istream& in, complex& com){
    in >> com.re;
    in >> com.im;
    return in;
}

complex& complex::operator += (const complex& a){
    re += a.re;
    im += a.im;
    return *this;
}

complex& complex::operator += (double a){
    re += a;
    return *this;
}

complex& complex::operator -= (const complex& a){
    re -= a.re;
    im -= a.im;
    return *this;
}

complex& complex::operator -= (double a){
    re -= a;
    return *this;
}

complex& complex::operator *= (const complex& com){
    double i, j;
    i = re * com.re - im * com.im;
    j = re * com.im + com.re * im;
    re = i;
    im = j;
    return *this;
}

complex& complex::operator *= (double a){
    re *= a;
    im *= a;
    return *this;
}

/*complex& complex::operator /= (const complex& com){
    double i, j, k;
    k = re * re - com.im * com.im;
    i = (re * com.re + im * com.im) / k;
    j = (com.re * im - re * com.im) / k;
    re = i;
    im = j;
    return *this;
}*/

complex& complex::operator /= (const complex& com){
    double i, j, k;
    k = com.re * com.re + com.im * com.im;
    i = (re * com.re + im * com.im) / k;
    j = (re * com.im - com.re * im) / k;
    re = i;
    im = -j;
    return *this;
}

complex& complex::operator /= (double a){
    re /= a;
    im /= a;
    return *this;
}
