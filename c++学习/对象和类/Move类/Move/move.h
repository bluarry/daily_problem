#ifndef MOVE_H
#define MOVE_H


class Move
{
private:
    double x,y;
public:
    Move(double a=0,double b=0);
    void showmove()const;//显示当前坐标
    Move add(const Move &m) const;
    void reset(double a=0,double b=0);
};

#endif // MOVE_H
