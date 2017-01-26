#include <iostream>
using namespace std;

template <class T>
void Swap(T &a,T &b){
    T tem=b;
    b=a;
    a=tem;
}

int main()
{

    int a,b;
    cin >> a >> b;
    
    cout << a<<" " << b << endl;
    Swap(a,b);
    cout << a <<" "<< b << endl;
    
    double c,d;
   cin >> c >> d; 
    cout << c<<" " << d << endl;
    Swap(c,d);
    cout << c <<" "<< d << endl;

    return 0;
}
