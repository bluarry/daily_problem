#include "time01.h"


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
Time Time::operator +(const Time &t) const
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

Time Time::operator- (const Time & t)const
{
    Time diff;
    int tot1,tot2;
    tot1 = t.minutes + 60*t.hours;
    tot2 = minutes + 60*hours;
    if(tot2-tot1 > 0)
    diff.hours=(tot2-tot1) /60;
    else
    diff.hours=(tot2-tot1+12) /60;
    if(tot2-tot1 > 0)
    diff.minutes=(tot2-tot1) %60;
    else
        diff.minutes=(tot2-tot1+60) %60;

    return diff;
}
Time Time::operator* (double n)const
{
    Time Res;
    long Totaltime=hours*n*60+minutes*n;
    Res.hours=Totaltime/60;
    Res.minutes=Totaltime%60;
    return Res;
}
ostream & operator<< (ostream &os,const Time & t)
{
    os << t.hours << "hours ," << t.minutes << "minutes";
    return os;
}
