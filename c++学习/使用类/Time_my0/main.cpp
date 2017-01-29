#include <iostream>
#include "time01.h"
using namespace std;

int main()
{
    using std::cout;
       using std::endl;
       Time planning;
       Time coding(2,40);
       Time fixing(5,55);

       cout << "planing time = ";
       planning.Show();
       cout << endl;

       cout << "coding time = ";
       coding.Show();
       cout << endl;

       cout << "fixing time = ";
       fixing.Show();
       cout << endl;

       Time total;
       total=coding.Sum(fixing);
       cout << "coding.Sum(fixing) = ";
       total.Show();
       cout << endl;

       Time total0;
       total0=coding+fixing;
       cout << "coding+fixing = ";
       total0.Show();
       cout << endl;

       Time diff;
       diff=coding-fixing;
       cout << "coding-fixing = ";
       diff.Show();
       cout << endl;

       Time adujst=total * 1.5;
       cout << "(coding+fixing)*1.5 = ";
        adujst.Show();
        cout << endl;







    return 0;
}

