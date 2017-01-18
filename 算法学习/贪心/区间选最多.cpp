#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1000;
int S[maxn],T[maxn];
int N;
int main()
{
	freopen("./in","r",stdin);
    cin >> N;
    for(int i=0;i<N;i++)
    	cin >> S[i] >> T[i];
    pair<int ,int > test[maxn];
    for(int i=0;i<N;i++)
    {
    	test[i].first=T[i];
    	test[i].second=S[i];
    }


    sort(test,test+N);


    int sum=0,last=0;
    for(int i=0;i<N;i++)
    {
    	if(last<test[i].second)
    	{
    		sum++;
    		last=test[i].first;
    	}
    }
    cout << sum << endl;


    return 0;
}
