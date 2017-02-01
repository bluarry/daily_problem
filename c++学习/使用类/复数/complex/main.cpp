#include <iostream>
using namespace std;
#include "complex0.h"

int main()
{
    complex a(3.0,4.0);
    complex c;
    cout << "输入一个复数 (q结束): \n";
    while(cin >> c)
    {
        cout << "c is " << c << endl;
       cout << "c 的共轭为 " << ~c << endl;
        cout << "a is " << a << endl;
        cout << "a + c is" << a + c <<endl;
        cout << "a - c is" << a - c <<endl;
        cout << "a * c is" << a * c <<endl;
        cout << "2 * c is" << 2 * c <<endl;
        cout << "输入一个复数 (q结束): \n";
    }

    cout << "Done !" << endl;
    return 0;
}

