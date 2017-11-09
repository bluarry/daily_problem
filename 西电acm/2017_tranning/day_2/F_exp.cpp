#include <cstdio>  
#include <algorithm>  
#include <cmath>  
#include <cstring>  
#include <iostream>  
#include <string>  
using namespace std;  
const int maxn = 3333;  
bool a[maxn], vis[maxn];  
int w[111];  
int main()  
{  
    freopen("in.txt","r",stdin);
    int T;  
    int n, q;  
    scanf("%d",&T);  
    while(T--)  
    {  
        scanf("%d", &n);  
        for(int i=1; i<=n; i++)  
            scanf("%d", &w[i]);  
        memset(a, 0, sizeof a);  
        memset(vis, 0, sizeof vis);  
        a[0] = 1;  
        for(int i=1; i<=n; i++)  
        {  
            memset(vis, 0, sizeof vis);  
            for(int j=0; j<=2000; j++)  
            {  
                if(a[j] == 1)  
                {  
                    if(j-w[i] >= 0)  
                        vis[j-w[i]] = 1;  
                    if(j+w[i] <= 2000)  
                        vis[j+w[i]] = 1;  
                }  
            }  
            for(int j=0; j<=2000; j++)  
            {  
                if(a[j] || vis[j])  
                {  
                    a[j] = 1;  
                }  
            }  
        }  
        scanf("%d", &q);  
        while(q--)  
        {  
            int x;  
            scanf("%d", &x);  
            if(a[x])  
                printf("YES\n");  
            else  
                printf("NO\n");  
        }  
    }  
    return 0;  
}  