#ifndef COMPLEX0_H
#define COMPLEX0_H

#include <iostream>
class complex
{
private:
    double x,y;
public:
    complex(double a=0,double b=0);

    complex operator+(const complex & b)const;
    complex operator~()const;
    complex operator-(const complex & b)const;
    complex operator*(const complex & b)const;
    complex operator *(double d)const;

    friend complex operator* (double d,const complex & b);
    friend std::ostream & operator << (std::ostream & os,const complex & a);
    friend std::istream & operator >> (std::istream & os,complex & a);
};

#endif // COMPLEX0_H
