#include "time_my.h"
#include <iostream>
/*
    Time();
    Time(int h,int m=0);
    void Addmin(int m);
    void AddHr(int h);
    void Reset(int h=0,int m=0);
    Time Sum(const Time & t)const;
*/
Time::Time()
{
    hours=minutes=0;
}
Time::Time(int h,int m)
{
    hours=h;
    minutes=m;
}
void Time::Addmin(int m)
{
     minutes+=m;
     hours += minutes/60;
     minutes%=60;
}
void Time::AddHr(int h)
{
    hours+=h;
}
void Time::Reset(int h, int m)
{
    hours=h;
    minutes=m;
}
Time Time::Sum(const Time &t) const
{
    Time sum;
    sum.minutes=minutes + t.minutes;
    sum.hours=hours+t.hours+ sum.minutes /60;
    sum.minutes%=60;
    return sum;
}
void Time::Show() const
{
    std::cout << hours << " hours , " << minutes << " minutes , ";
}
