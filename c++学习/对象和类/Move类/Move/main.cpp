#include <iostream>
#include <move.h>
using namespace std;

int main()
{
    Move a;
    a.showmove();
    a=a.add(*(new Move(100,122)));
    a.showmove();
    a.reset();
    a.showmove();





    return 0;
}

