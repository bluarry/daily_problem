#include <iostream>
#include <cstring>
using namespace std;
const int maxn=1e6+5;

int n,m,dx,dy;

int x[maxn],y[maxn];
int xk[maxn],cnt[maxn];
int main()
{
	cin >> n >> m >> dx >> dy;
	//首先预处理(0,0)这一组的所有(x,y)
	x[0]=y[0]=0;
	for(int i=1;i<n;i++)
	{
		x[i]=(x[i-1]+dx)%n;
		y[i]=(y[i-1]+dy)%n;
		xk[x[i]]=i;	//反过来映射，避免之后遍历寻找;
	}
	//将所有的点映射回(0,y0)点，统计个数
	for(int i=0;i<m;i++){
		int xx,yy;
		cin >> xx >> yy;
		int k=xk[xx];
		int y0=(yy-y[k]+n)%n;
		cnt[y0]++;
	}
	//遍历寻找(0,y0)，找出最大的输出即可
	int mx=cnt[0], pos=0;
    for(int i=1;i<n;i++)
        if(mx < cnt[i])
            mx=cnt[i], pos=i;
	cout <<  0 << " " << pos << endl;
	return 0;
}