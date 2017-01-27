#include <iostream>
#include "stack.h"
using namespace std;
#define REP(a,b)    for(int i=a;i<b;i++)

int main()
{
    Stack s;

    Item a[10];
    REP(0,10){
        cin >> a[i].fulname>> a[i].payment;
          s.push(a[i]);
    }
    long long sum=0;

    while(!s.isempty()){
        Item q;
        s.pop(q);
       // cout <<q.fulname << " " <<q.payment << endl;
        sum+=q.payment;
    }
    cout << sum << endl;


    return 0;
}

/*
a 1
b 2
c 3
d 4
e 5
f 6
g 7
h 8
i 9
j 10
*/
