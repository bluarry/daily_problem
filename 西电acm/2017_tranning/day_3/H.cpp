#include <iostream>
using namespace std;

const int maxn=1e7+5;

string str;

int main()
{
	int T;
	cin >> T;
	while(T--){
		cin >> str;
		if(str.length()<=1 || str[0]!='M'){cout << "No"<<endl; continue;}

		int sum=0,flag=1;;
		int len=str.length();
		for(int i=1;i<len;i++){
			if(str[i]=='I') sum++;
			else if(str[i]=='U') sum+=3;
			else flag=0;
		}
		if(!flag){cout << "No"<<endl; continue;}

		bool ans=false;
		for(int i=1;i<maxn;i*=2)	// 如果I的个数是偶数个肯定可以得到，若为奇数个，那么一定消去了两个U也就是6的倍数个I
			if(i>=sum)
				if((i-sum)%6==0)
				{
					ans=true;
					break;
				}
		if(ans) cout << "Yes"<<endl;
		else cout << "No"<<endl;
	}
	return 0;
}
