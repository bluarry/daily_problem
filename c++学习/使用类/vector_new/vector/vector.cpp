#include <cmath>
#include "Vector.h"
using std::sin;
using std::cos;
using std::atan2;
using std::cout;
/*
    Vector();
    Vector(double n1,double n2,char form='r');
    void set(double n1,double n2,char form='r');
    double xval()const{return x;}
    double yval()const{return y;}
    double magval()const{return mag;}
    double angval()const{return ang;}
    void polar_mode();
    void rect_mode();

*/

namespace  VECTOR {
    const double Rad_to_Deg=57.2957795130823;   //一弧度的等价度数
    //private
    void Vector::set_mag()
    {
        mag=sqrt(x*x+y*y);
    }
    void Vector::set_ang()
    {
        if(x==0.0 && y== 0.0)
        ang=0.0;
        else
            ang=atan2(y,x);
    }
    void Vector::set_x()
    {
        x=mag*cos(ang);
    }
    void Vector::set_y()
    {
        y=mag*sin(ang);
    }


    Vector::Vector()
    {
        x=y=mag=ang=0;
        mode='r';
    }

    Vector::Vector(double n1, double n2, char form)
    {
        mode =form;
        if(mode =='r')
        {

            x=n1;
            y=n2;
            set_mag();
            set_ang();
        }
        else if(mode == 'p')
        {
            mag=n1;
            ang=n2;
            set_x();
            set_y();
        }
        else
        {
            cout << "参数错误! \n 设置为0";
            x=y=ang=mag=0;
            mode='r';
        }
    }
    //public
    void Vector::set(double n1, double n2, char form)
    {
        mode =form;
        if(mode =='r')
        {

            x=n1;
            y=n2;
            set_mag();
            set_ang();
        }
        else if(mode == 'p')
        {
            mag=n1;
            ang=n2;
            set_x();
            set_y();
        }
        else
        {
            cout << "参数错误! \n 设置为0";
            x=y=ang=mag=0;
            mode='r';
        }
    }
    void Vector::polar_mode()
    {
        mode ='p';
    }
    void Vector::rect_mode()
    {
        mode='r';
    }
/*
    Vector operator+ (const Vector & b)const;
    Vector operator- (const Vector & b)const;
    Vector operator- ()const;
    Vector operator* (double n)const;

    friend Vector operator* (double n,Vector & a);
    friend std::ostream & operator <<(std::ostream &os,Vector & v);

*/





    Vector Vector::operator +(const Vector & b)const
    {
        return Vector(x+b.x,y+b.y);
    }

    Vector Vector::operator -(const Vector & b)const
    {
        return Vector(x-b.x,y-b.y);
    }
    Vector Vector::operator -()const
    {
        return Vector(-x,-y);
    }
    Vector Vector::operator *(double n)const{
        return Vector(n*x,n*y);
    }

    //friend

    Vector operator *(double n,Vector & a)
    {
        return a*n;
    }

    std::ostream & operator << (std::ostream & os , const Vector & v)
    {
        if(v.mode == 'r')
        {
            os << "(x,y)=("<<v.x << ","<<v.y<<"," << v.ang*Rad_to_Deg<<")";
        }
        else if(v.mode == 'p')
        {
            os<< "(m,a)=(" << v.mag<< "," << v.ang*Rad_to_Deg << ")";
        }
        else
            os<<"该向量错误!";
        return os;
    }



}


