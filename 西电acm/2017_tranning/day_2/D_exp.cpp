#include<stdio.h>
#include<string.h>
#include<algorithm>

#define N 100000 + 10

using namespace std;

typedef struct
{
   int num ,id;
}NODE;

NODE node[N];

__int64 num[N];
int hashh[N];
int lowbit(int x)
{
   return x & -x;
}

void update(int x ,__int64 a ,int n)
{
   for(int i = x ;i <= n ;i += lowbit(i))
   num[i] += a;
}

__int64 find(int x)
{
   __int64 sum = 0;
   for(int i = x ;i > 0 ;i -= lowbit(i))
   sum += num[i];
   return sum;
}

bool camp(NODE a ,NODE b)
{
   return a.num < b.num;
}

int main ()
{
   freopen("in.txt","r",stdin);
   int n ,i ,a;
   __int64 m ,sum;
   while(~scanf("%d %I64d" ,&n ,&m))
   {
      for(i = 1 ;i <= n ;i ++)
      {
         scanf("%d" ,&node[i].num);
         node[i].id = i;
      }
      sort(node + 1 ,node + n + 1 ,camp);
      int t = 0;
      node[0].num = -1;
      for(i = 1 ;i <= n; i ++)
      {
         if(node[i].num != node[i-1].num)
         t ++;
         hashh[node[i].id] = t;
      }
      memset(num ,0 ,sizeof(num));
      for(sum = 0 ,i = 1 ;i <= n ;i ++)
      {
         sum += (i - 1) - find(hashh[i]);
         update(hashh[i] ,1 ,t);
      }
      if(sum < m) printf("0\n");
      else printf("%I64d\n" ,sum - m);
   }
   return 0;
}
