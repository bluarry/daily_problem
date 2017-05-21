#include <iostream>
#include <cstring>
using namespace std;
const int Max=10;
int n,m;
bool mapp[Max][Max];
int tem[Max][Max];
int solve(){
	memset(tem,0,sizeof(tem));
	int cnt=0,ans=0;

	for(int i=-3;i<=3;i++)
	{
		cnt=0;
		for(int j=0;j<7;j++)
			if(i!=0)
				cnt+=mapp[i+3][j];
			else
			{
				if(mapp[i+3][0]&&mapp[i+3][1]&&mapp[i+3][2] || mapp[i+3][4]&&mapp[i+3][5]&& mapp[i+3][6])
					cnt+=3;
				else {
					cnt+=0;
				}
				break;
			}
		ans+= cnt/3;

		cnt=0;
		for(int j=0;j<7;j++)
			if(i!=0)
				cnt+=mapp[j][i+3];
			else
			{
				if(mapp[0][i+3]&&mapp[1][i+3]&&mapp[2][i+3] || mapp[4][i+3]&&mapp[5][i+3]&&mapp[6][i+3])
					cnt+=3;
				else {
					cnt+=0;
				}
				break;
			}
		ans+= cnt/3;
	}

	return ans;


}
int main()
{
	while(cin >> n >> m)
	{
		memset(mapp,0,sizeof(mapp));
		for(int i=0;i<n;i++)
		{
			int a,b;
			cin >> a >> b;
			mapp[a+3][b+3]=true;
		}
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin >> a >> b;
		}
		int res=solve();
		cout << res<<endl;
	}




	return 0;
}
