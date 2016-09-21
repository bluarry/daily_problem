#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m;
char s1[10000],s2[10000];
void lcs (){
	int mp[n+3][m+3];
	memset(mp,0,sizeof(mp));
	for(int i=1;i<=n;i++) //s1
		for(int j=1;j<=m;j++)//s2
			if(s1[i]==s2[j])mp[i][j]=mp[i-1][j-1]+1;
			else mp[i][j]=max(mp[i-1][j],mp[i][j-1]);
		
/*
		for(int i=0;i<=n;i++) //s1
			for(int j=0;j<=m;j++)//s2
				j==m?cout << mp[i][j] <<endl : cout << mp[i][j] <<" " ;
*/
		cout << mp[n][m] <<endl;	
	
	
}
int main()
{
	
	cin >> n >> m;
	cin >> (s1+1);
	cin >> (s2+1);
	lcs();
	return 0;
}

/*
4 5
mytestdata
msetdate


*/
