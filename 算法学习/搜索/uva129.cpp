#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n,L;
int S[82];
int tot=0;


int dfs(int cur)
{
    if(tot++ ==n)
    {
        for(int i=0;i<cur;i++){
            if(i>0 && !(i % 4) && (i%64))cout << " ";
            else if(i>0 && !(i%64))cout <<endl;
            cout << (char)('A'+S[i]);
        }
        cout << endl;
        cout << cur<<endl;
        return 0;
    }


    for(int i=0;i<L;i++)
    {
        S[cur]=i;
        int ok=1;

        for(int j=1; 2*j <= cur+1;j++)
        {
            int equal=1;
            for(int k=0;k<j;k++)
                if(S[cur-k] != S[cur-k-j]){equal=0;break;}
            if(equal) {ok=0;break;}
        }

        if(ok) if(!dfs(cur+1)) return 0;
    }
    return 1;
}



int main()
{
    while(cin >> n >> L,n)
    {
        tot=0;
        memset(S,0,sizeof(S));
        dfs(0);






    }



    return 0;
}
