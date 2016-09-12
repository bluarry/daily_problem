#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
//#define LOCAL

int main()
{	
	#ifdef LOCAL
	freopen("D:\\1.in","r",stdin);
	#endif
	int A[31][31]={0},B[31][31]={0};
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin >> A[i][j];
		}
		//标记每一行中重复的元素
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m-2;j++)
			if(A[i][j] == A[i][j+1] && A[i][j] == A[i][j+2])
				B[i][j] = B[i][j+1]= B[i][j+2]=1;
		//标记每一列中重复的元素
		for(int j=1;j<=m;j++)
			for(int i=1;i<=n-2;i++)
				if(A[i][j]==A[i+1][j] && A[i][j]==A[i+2][j] )
						B[i][j]=B[i+1][j]=B[i+2][j]=1;

		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(B[i][j])
					A[i][j]=0;

		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				j==m ? cout << A[i][j]<< endl : cout << A[i][j] << " "; 
	return 0;
}
