#include "complex0.h"
#include <iostream>

/*
    complex();
    complex(double a=0,double b=0);

    complex operator+(const complex & b)const;
    complex operator~()const;
    complex operator-(const complex & b)const;
    complex operator*(const complex & b)const;
    complex operator *(double d)const;

    friend complex operator* (double d,const complex & b);
    friend std::ostream & operator << (const  std::ostream & os,const complex & a);
    friend std::istream & operator >> (const  std::ostream & os,const complex & a);
*/


complex::complex(double a,double b)
{
    x=a;
    y=b;
}
complex complex::operator~()const
{
    return complex(x,-y);
}
complex complex::operator+(const complex & b)const{
    return complex(x+b.x,y+b.y);
}
complex complex::operator-(const complex & b)const{
    return complex(x-b.x,y-b.y);
}
complex complex::operator*(const complex & b)const{
    return complex(x*b.x-y*b.y,x*b.y+y*b.x);
}
complex complex::operator *(double d)const
{
    return complex(x*d,y*d);
}
complex operator *(double d,const complex & b)
{
    return b*d;
}
std::ostream & operator << (std::ostream & os,const complex & a )
{
    os << "("<< a.x << "," << a.y << "i)";
    return os;
}
std::istream & operator >> (std::istream & os,complex & a )
{
    std::cout << "real :";
    if(os >> a.x)
    {
        std::cout << "imaginary:";
        os >>a.y;
    }
    return os;
}
