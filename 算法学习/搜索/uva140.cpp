#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF=9999999;
char str[100];
int g[30][30],has[30],num=0,ans;

void dfs(int cur,int seq[])
{
    if(cur == num)
    {



    }

    for(int i=0;i<26;i++)
    if(has[i])
    {
        int ok=1;
        for(int j=0;j<cur;j++)  //这是一个剪枝,减掉当前搜到的




    }




}




int main()
{
    while(~scanf("%s",str ) && str[0]!='#')
    {
        int i=0;
        memset(g,0,sizeof(g));
        memset(has,0,sizeof(has));
        while(str[i]!='\0')
        {
            if(str[i] == ':')
            {
                int s=str[i-1]-'A';
                has[s]=1;
                i++;
                while (str[i]!=';' && str[i]!='\0') {
                    g[s][str[i]-'A']=1;
                    g[str[i]-'A'][s]=1;
                    has[str[i]-'A']=1;
                    i++;
        }
        num=0;
        for(int i=0;i<26;i++)if(has[i]) num++;

        ans=INF;
        int tem[10];
        dfs(0,tem);





    }
    return 0;
}
