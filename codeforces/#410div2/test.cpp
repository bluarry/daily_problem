#include<iostream>  
using namespace std;  
const int MAXN = 1111111,MAXM = 11111;  
int T[MAXN],P[MAXM],Next[MAXM];  
void MakeNext(int M){  
    Next[0] = -1;  
    int i = 0, j = -1;  
    while(i<M){  
        if(j==-1||P[i]==P[j]){  
            i++,j++;  
            if(P[i]!=P[j])Next[i] = j;  
            else Next[i] = Next[j];  
        }  
        else j = Next[j];  
    }  
}  
int KMP(int N,int M){  
    int i=0,j=0;  
    while(i<N&&j<M){  
        if(T[i]==P[j]||j==-1)i++,j++;  
        else j = Next[j];  
    }  
    if(j==M)return i-M+1;  
    else return -1;  
}  
int main(){  
    int N,M,C;  
    scanf("%d",&C);  
    while(C--){  
        scanf("%d%d",&N,&M);  
        for(int i=0;i<N;i++)scanf("%d",&T[i]);  
        for(int i=0;i<M;i++)scanf("%d",&P[i]);  
        if(M>N)printf("-1\n");  
        else{  
            MakeNext(M);  
            printf("%d\n",KMP(N,M));  
        }  
    }  
    return 0;  
}  
