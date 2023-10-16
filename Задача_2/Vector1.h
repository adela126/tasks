#ifndef VECTOR1_H_INCLUDED
#define VECTOR1_H_INCLUDED

#include <iostream>
#include <ostream>
#include <cmath>

template <class T, size_t N> class vector_
{
public:
    vector_() {for (size_t i=0; i<N; ++i){x[i] = 0; }}
    vector_( T *t ) { for (size_t i=0; i<N; ++i){x[i] = t[i]; } }

    const T& operator [] (size_t i) const {return x[i]; }
    T& operator [] (size_t i) {return x[i]; }

    vector_& operator += (const vector_& v);
    vector_ operator + (const vector_& v) const;
    T operator * (const vector_& v) const;
    vector_& operator *= (T k);
    vector_ operator * (T k) const;
    vector_& operator /= (T k);
    vector_ operator / (T k) const;

    bool operator == (const vector_& v) const;
    bool operator != (const vector_& v) const;
    bool operator > (const vector_& v) const;
    bool operator < (const vector_& v) const;

    vector_ operator +() const;
    vector_ operator -() const;

    template <class U, size_t M> friend double abs_v(const vector_<U, M>& v);

    double cos_v (const vector_ & v) const;
    double P (const vector_& v) const;

    template <class U, size_t M> friend std::ostream& operator << (std::ostream& stream, const vector_<U, M>& v);
    template <class U, size_t M> friend std::istream& operator >> (std::istream& stream, vector_<U, M>& v);

private:
    T x[N];
};

template <class T, size_t N> vector_<T, N>& vector_<T, N>::operator += (const vector_<T, N>& v)
{
    for (size_t i = 0; i < N; ++i)
        x[i] += v[i];
    return *this;
}

template <class T, size_t N> vector_<T, N> vector_<T, N>::operator + (const vector_<T, N>& v) const
{
    vector_ r = *this; r += v; return r;
}

template <class T, size_t N> T vector_<T, N>::operator * (const vector_<T, N>& v) const{
    T r = 0;
    vector_ x = *this;
    for (size_t i = 0; i < N; ++i){
        r += v[i] * x[i];
    }
    return r;
}

template <class T, size_t N> vector_<T, N>& vector_<T, N>::operator *= (T k){
    vector_ x = *this;
    for (size_t i=0; i<N; ++i){
        x[i] *= k;
    }
    return *this;
}

template <class T, size_t N> vector_<T, N> vector_<T, N>::operator * (T k) const{
    vector_ x = *this;
    x *= k;
    return *this;
}

template <class T, size_t N> vector_<T, N>& vector_<T, N>::operator /= (T k){
    vector_ x = *this;
    for (size_t i=0; i<N; ++i){
        x[i] /= k;
    }
    return *this;
}

template <class T, size_t N> vector_<T, N> vector_<T, N>::operator / (T k) const{
    vector_ x = *this;
    x /= k;
    return *this;
}

template <class T, size_t N> bool vector_<T, N>::operator == (const vector_<T, N>& v) const{
    bool t = true;
    vector_ x = *this;
    for (size_t i = 0; i<N; i++){
        if (x[i] != v[i]){
            t = false;
            return t;
        }
    }
    return t;
}

template <class T, size_t N> bool vector_<T, N>::operator != (const vector_<T, N>& v) const{
    bool t = true;
    vector_ x = *this;
    for (size_t i = 0; i<N; i++){
        if (x[i] == v[i]){
            t = false;
            return t;
        }
    }
    return t;
}

template <class T, size_t N> bool vector_<T, N>::operator > (const vector_<T, N>& v) const{
    bool t = true;
    vector_ x = *this;
    for (size_t i = 0; i<N; i++){
        if (x[i] < v[i]){
            t = false;
            return t;
        }
    }
    return t;
}

template <class T, size_t N> bool vector_<T, N>::operator < (const vector_<T, N>& v) const{
    bool t = true;
    vector_ x = *this;
    for (size_t i = 0; i<N; i++){
        if (x[i] > v[i]){
            t = false;
            return t;
        }
    }
    return t;
}

template <class T, size_t N> vector_<T, N> vector_<T, N>::operator + () const{
    vector_ v = *this;
    return v;
}

template <class T, size_t N> vector_<T, N> vector_<T, N>::operator - () const{
    vector_ v = *this;
    for (size_t i=0; i<N; ++i){
        v[i] = -v[i];
    }
    return v;
}

template <class T, size_t N> double abs_v(const vector_<T, N>& v){
    double r = 0;
    for (size_t i = 0; i<N; ++i){
        r += v[i]*v[i];
    }
    return sqrt(r);
}

template <class T, size_t N> double vector_<T, N>::cos_v (const vector_<T, N>& v) const{
    vector_ t = *this;
    double r = 0;
    r = (v * t)/(abs_v(v) * abs_v(t));
    return r;
}

template <class T, size_t N> double vector_<T, N>::P (const vector_<T, N>& v) const{
    vector_ t = *this;
    double r = 0;
    r = abs_v((t-v));
    return r;
}

template <class T, size_t N> std::ostream& operator << (std::ostream& stream, const vector_<T, N>& v)
{
    stream << "(";
    for (size_t i = 0; i < N - 1; ++i)
        stream << v[i] << ", ";
    stream << v[N - 1] << ")";
    return stream;
}
template <class T, size_t N> std::istream& operator >> (std::istream& stream, vector_<T, N>& v)
{
    for (size_t i = 0; i < N; ++i)
        stream >> v[i];
    return stream;
}

#endif // VECTOR1_H_INCLUDED
