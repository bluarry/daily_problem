#include <iostream>
using namespace std;
char chr[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void printc(int n){
	for(int i=0;i<n;i++)
		{
			for(int j=25-i;j>0;j--)
				cout << " ";
			int k;
			for(k=0;k<(i+1);k++)
				cout << chr[k];
			k-=2;
			for(;k>=0;k--) cout << chr[k];
			cout <<endl;
		}
}

int main()
{
	int n;
	while(cin >> n){
		printc(n);
	}
	return 0;
}