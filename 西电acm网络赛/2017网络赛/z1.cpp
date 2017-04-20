#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int num[1000+2];
	int n,mmax=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> num[i];
		if(i>=1){
			int tt=num[i]-num[i-1];
			if(tt < 0) tt =-tt;
			mmax=max(mmax,tt);
		}
	}
	cout << mmax <<endl;
	return 0;
}
