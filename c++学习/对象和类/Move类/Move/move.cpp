#include "move.h"
#include <iostream>
/*
    Move(double a=0,double b=0);
    void showmove()const;//显示当前坐标
    Move add(const Move &m)const;
    reset(double a=0,double b=0);
*/
Move::Move(double a,double b)
{
    this->x=a;
    this->y=b;
}
void Move::showmove()const
{
    using std::cout;
    using std::endl;
    cout << this->x << " "<< this->y << endl;
}
Move Move::add(const Move & m)const
{
  return *(new Move(this->x+m.x,this->y+m.y));
}
void Move::reset(double a, double b)
{
    this->x=a;
    this->y=b;
}
