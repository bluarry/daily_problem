#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
const int N = 1003;
int a[N];

int main(){
    int n;
    while(cin>>n){
        for(int i =0  ;i < n;++i){
            cin>>a[i];
        }
        int anss = -1;
		for(int i = 0 ; i< n;++i){
            int low = a[i];
			for(int j =  i ; j < n ; ++j){
                if(low > a[j])
                    low = a[j];
                int temp = (j - i + 1) * low;
                if(temp > anss)
                    anss = temp;
            }
        }
        cout<<anss<<endl;
    }
return 0;
}

