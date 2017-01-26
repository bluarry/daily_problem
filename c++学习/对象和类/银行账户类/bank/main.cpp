#include <iostream>
#include "bank_my.h"

using namespace std;

int main()
{
    bank_my she("美女",123456789,1e6);
    she.show();
       long long tar=1;
    while(tar)
    {
    cout << "输入要存的钱 :";
    cin >> tar;
    if(she.save(tar))
    {
        cout << "存钱成功 ! ";
        she.show();
    }
    else
    {
            cout << "输入有误 !";
            she.show();
    }


     cout << "输入要取的钱 :";

     cin >> tar;
    if(she.get(tar))
    {
        cout << "你取出 " <<tar <<"元\n你的账户情况为: \n";
        she.show();
    }
    else
    {
        cout << "余额不足 或 输入为负!! \n";
        she.show();
    }
    }

    return 0;
}

