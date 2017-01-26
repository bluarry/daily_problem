/*************************************************************************
	> File Name: 模板的显示具体化.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年01月24日 星期二 10时05分24秒
 ************************************************************************/

#include<iostream>
using namespace std;
struct job{
    double salary;
    int floor;
};

template <typename T>
void Swap(T &a,T&b)
{
    T tem=b;
    b=a;
    a=tem;
}

template <> void Swap<job> (job &a,job &b)
{
    double c;
    c=a.salary;
    a.salary=b.salary;
    b.salary=c;
}


template <> void Swap<int> (int &a,int &b)
{
    a=a-b;
    b=a+2*b;
}

int main()
{
    job a={123456.123456,123};
    job b={654321.654321,321};
    Swap(a,b);
    int c ,d;
    cin >> c >> d;
    Swap(c,d);
    cout << c<<" " << d <<endl;



    return 0;
}
