#include <iostream>
#include <string>
#include "person.h"
using namespace std;



int main()
{
   Person one;
   Person two("123456789");
   Person three("逗","逼");
   one.show();
   one.FormalShow();
    two.show();
    two.FormalShow();
    three.show();
    three.FormalShow();




    return 0;
}

