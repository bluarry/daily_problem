#include <iostream>
#include <cstring>
using namespace std;

int n;
bool arefriend[10][10];
int countpairings(int taken[10])
{
	int firstFree=-1;
	for(int i=0;i<n;i++)
	{
		if(!taken[i])
		{
			firstFree=i;
			break;
		}
	}

	if(-1==firstFree) return 1;
	int ret=0;

	for(int pairwith=firstFree+1;pairwith<n;pairwith++)
	{
			if(!taken[pairwith] && arefriend[firstFree][pairwith])
			{
				taken[pairwith]=taken[firstFree]=1;
				ret+=countpairings(taken);
				taken[pairwith]=taken[firstFree]=0;
			}

	}

	return ret;
}



int main()
{
	int C;
	cin >> C;
	while(C--){
		int m;
		cin >> n >> m;
		memset(arefriend,false,sizeof(arefriend));
		for(int i=0;i<m;i++)
		{
			int x,y;
			cin >> x >> y;
			arefriend[x][y]=arefriend[y][x]=true;
		}
		int taken[10]={0};
		int sum=countpairings(taken);
		cout << sum <<endl;
	}
	return 0;
}
/*
3
2 1
0 1
4 6
0 1 1 2 2 3 3 0 0 2 1 3
6 10
0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5
*/
