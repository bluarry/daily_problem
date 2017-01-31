#ifndef TIME01_H
#define TIME01_H
/**
 * 此类旨在测试运算符重载
 */

#include <iostream>
using namespace  std;
class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h,int m=0);
    void Addmin(int m);
    void AddHr(int h);
    void Reset(int h=0,int m=0);
    Time Sum(const Time & t)const;
    Time operator+ (const Time & t)const;
    Time operator- (const Time & t)const;
    Time operator* (double n)const;
    void Show()const;
    //friend void operator<< (ostream &os,const Time & t);
    friend ostream & operator<< (ostream &os,const Time & t);
};

#endif // TIME01_H
