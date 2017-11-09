#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MOD=1000;
int Mar[21][21],Tt[21][21],ans[21][21];
int N,M;

//t =a * b
void M_multi(int a[][21],int b[][21],int t[][21]){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            t[i][j]=0;
    for(int i=0;i<N;i++)
        for(int k=0;k<N;k++)
            for(int j=0;j<N;j++)
            {
                t[i][j]=(t[i][j]+ a[i][k]*b[k][j])%MOD;
            }
}
void setv(int a[][21],int b[][21]){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            a[i][j]=b[i][j];
}
//Tt ^ n
void Martix_pow(int n){
    int tmp[21][21];
    while(n){
        if(n&1){
            M_multi(ans,Tt,tmp);
            setv(ans,tmp);
          //  ans=ans*Mar;
        }
        n>>=1;
        M_multi(Tt,Tt,tmp);
        setv(Tt,tmp);
        //Tt=Tt*Tt;

    }
}
void pp(int a[][21]){
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
           j!=N-1?cout << a[i][j] << " ":cout << a[i][j] << endl;
}

int main()
{
  //  freopen("in.txt","r",stdin);
    while(cin >> N >> M)
    {
        if(N==0&&M==0) break;

        int s,t;
        memset(Mar,0,sizeof(Mar));
        memset(Tt,0,sizeof(Tt));
        for(int i=0;i<M;i++)
        {
            cin >> s >> t;
            Mar[s][t]=1;
        }
        int T;
        //初始化
        //预处理
        cin >> T;
        while(T--)
        {
            int ss,tt,kk;
            cin >> ss >> tt >> kk;

            memset(ans,0,sizeof(ans));
            for(int j=0;j<N;j++)
                for(int i=0;i<N;i++)
                    ans[i][i]=1;
            setv(Tt,Mar);
            //pp(ans);
            Martix_pow(kk);
            cout << ans[ss][tt] << endl;
        }
    }
    return 0;
}