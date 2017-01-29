#ifndef TIME_my_H
#define TIME_my_H


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
    void Show()const;
};

#endif // TIME_H
