#include <iostream>
using namespace std;

template <class T>
void Swap(T &a,T &b){
    T tem=b;
    b=a;
    a=tem;
}

template <class T>
void Swap(T a[],T b[],int c)
{
    for(int i=0;i<c;i++)
    {
        T tem=b[i];
        b[i]=a[i];
        a[i]=tem;
    }
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
    
    int e[100],f[100];
    for(int i=0;i<100 ;i++)
    {
        e[i]=i+1;
        f[i]=100-i+1;
    }
     
    for(int i=0;i<100;i++)
    cout << e[i]<< " ";
    cout << endl;
    
    for(int i=0;i<100;i++)
    cout << f[i]<< " ";
    cout << endl;
    
    Swap(e,f,100);
    
    for(int i=0;i<100;i++)
    cout << e[i]<< " ";
    cout << endl;
    
    for(int i=0;i<100;i++)
    cout << f[i]<< " ";
    cout << endl;


    return 0;
}
