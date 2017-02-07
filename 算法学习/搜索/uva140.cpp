#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF=9999999;
char str[100];
int g[30][30],has[30],num=0,ans;
int answer[10];
void dfs(int cur,int seq[])
{
    if(cur == num)
    {
        //首先求出当前的序列的最大宽度,然后和ans比较,若比ans则更新即可;
        int nn=0;
            for(int i=0;i<num;i++)
                for(int j=i+1;j<num;j++)    //避免重复
                if(g[seq[i]][seq[j]]) nn = max(nn,j-i);
        if(ans > nn)
        {
            ans=nn;
            for(int i=0;i<num;i++)
            answer[i]=seq[i];
        }
        return ;
    }
    for(int i=0;i<26;i++)   //枚举当前cur位填哪一个字母
    if(has[i])              //出现过
    {
        int ok=1;
        for(int j=0;j<cur;j++)  //这是一个剪枝,减掉当前搜到的宽度大于当前答案的宽度的分支
            if(g[i][seq[j]])
                if(cur-j > ans ) {ok=0;break;}
                                //此处还应有一个剪枝 待添加!
                                //如果搜到当前节点的时候理想情况是m,但是m > ans,则需要减掉
                    /*  待添加 */
        if(ok)
        {
            seq[cur]=i;
            has[i]=0;
            dfs(i+1,seq);
            has[i]=1;
        }
    }
    return ;
}
int main()
{
    while(~scanf("%s",str ) && str[0]!='#')
    {
        int i=0;
        memset(g,0,sizeof(g));
        memset(has,0,sizeof(has));
        while(str[i]!='\0')         //将字符串拆开得到有用信息,并统计节点的个数
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
                }//while
            }//if
        }//while
        num=0;
        for(int i=0;i<26;i++)if(has[i]) num++;

        ans=INF;
        int tem[10];
        dfs(0,tem);
        for(int i=0;i<num;i++) printf("%c ",answer[i]+'A');
        printf("-> %d\n", ans);
    }
    return 0;
}
