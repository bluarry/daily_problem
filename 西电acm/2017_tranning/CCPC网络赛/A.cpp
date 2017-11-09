#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn=1e6+5;
const int MOD=1e9+7;
char s1[maxn],s2[maxn];
int nex[maxn];
void getnext(char w[],int nex[])
{
    nex[0]=-1;
    int len=strlen(w);
    for(int i=1,j=0;i<len;i++)
    {
        j=nex[i];
        while(j!=-1 && w[i]!=w[j])j=nex[j];
        nex[i+1]=j+1;
    }
}
int kmp(char s[],char t[]){
    // getnext(t,nex);
    int ans=0;
    int lens=strlen(s);
    int lent=strlen(t);
    int j=0;
    for(int i=0;i<lens;i++)
    {
        while(j!=-1 && t[j]!=s[i]){j=nex[j];}
        if(++j==lent){ans++;j=nex[j];} 
    }
    return ans;
}
int main()
{
	freopen("in.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",s1,s2);
		int len1=strlen(s1),len2=strlen(s2);
		int ans=0;
		 getnext(s2,nex);
		for(int i=0;i<=len2-1;i++){
			nex[i]=-1;
			int x=kmp(s1,s2+i);
			ans=(((len2-i)*x)%MOD+ans)%MOD;
		}
		printf("%d\n", ans);
	}
	return 0;
}
