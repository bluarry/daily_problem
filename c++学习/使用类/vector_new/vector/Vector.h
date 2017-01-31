#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

namespace VECTOR{
class Vector
{
private:
    double x,y,mag,ang;
    char mode;
    void set_mag();
    void set_ang();
    void set_x();
    void set_y();
public:
    Vector();
    Vector(double n1,double n2,char form='r');
    void set(double n1,double n2,char form='r');
    double xval()const{return x;}
    double yval()const{return y;}
    double magval()const{return mag;}
    double angval()const{return ang;}
    void polar_mode();
    void rect_mode();

    Vector operator+ (const Vector & b)const;
    Vector operator- (const Vector & b)const;
    Vector operator- ()const;
    Vector operator* (double n)const;

    friend Vector operator* (double n,Vector & a);
    friend std::ostream & operator <<(std::ostream &os,const Vector & v);
};
}
#endif // VECTOR_H
