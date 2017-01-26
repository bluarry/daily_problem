#ifndef BANK_MY_H
#define BANK_MY_H

#include <string>

class bank_my{
private:
    std::string name;
    long long num;
    long long money;
public:
    bank_my();
    bank_my(std::string s,long long n,long long m);
    void show();  //显示储户的姓名,账号,存款;
    bool save(long long moneyy);//存款
    bool get(long long moneyy); //取款
};

#endif // BANK_MY_H
