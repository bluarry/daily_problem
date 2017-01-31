#include "Vector.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result;
    unsigned long steps=0;
    double target;
    double dstep;
    cout << "输入目标距离 (q to exit): ";
    while(cin >> target)
    {
        cout << "输入每步的步长 : ";
        if(! (cin>>dstep))
        break;

        while (result.magval() < target) {
           direction=rand()%360;
           step.set(dstep,direction,'p');
           result=result+step;
           steps++;
        }
        cout << "经过 " << steps << "步的移动,"
                "对象移动到位置: ";
        cout << result <<endl;
        result.polar_mode();
        cout << " 或 \n" << result <<endl;

        cout << "平均移动的距离为 :" << result.angval()/steps << endl;
        steps=0;
        result.set(0,0);
        cout << "输入目标距离 (q to exit): ";


    }

    cout << "Bye! " << endl;




    return 0;
}

