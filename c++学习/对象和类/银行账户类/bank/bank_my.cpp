#include "bank_my.h"
#include <iostream>
bank_my::bank_my()
{
    name="";
    num=0;
    money=0;
}
 bank_my::bank_my(std::string s,long long n,long long m)
 {
    name=s;
    num=n;
    money=m;
 }

/*
    void show(bank A);  //显示储户的姓名,账号,存款;
    bool save(long long moneyy);//存款
    bool get(long long moneyy); //取款
*/

void bank_my::show()
{
    using std::cout;
    using std::endl;
    cout << endl;
    cout << "储存人 : " << this->name << endl;
    cout << "卡号 :" << this->num << endl;
    cout << "余额 :" << this->money << endl;
}
bool bank_my::save(long long moneyy)
{
    if(moneyy<0)
        return false;

    this->money+=moneyy;
    return true;
}
bool bank_my::get(long long moneyy)
{
    if(moneyy < 0) return false;
    if(this->money - moneyy < 0) return false;

    this->money -= moneyy;

    return true;
}
