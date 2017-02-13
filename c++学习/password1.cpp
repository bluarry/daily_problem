#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
ll maxn=36028797090000001;


char pa[27]="abcdefghijklmnopqrstuvwxyz";

char name[]={'p','a','s','s','\0'};


char num[39]={'0'};
int len=0;
void increase()
{
  num[0]=num[0]+1;

  int i=0;
  while(num[i]>'9')
  {
    num[i]='0';
    num[i+1]=num[i+1]+1;
    i++;
  }
  len=max(i,len);
}

char * cat(char name[],char num[])
{
  char* name_r=(char *)malloc(sizeof(char)*1000);
  int j=0;
    for(;j<4;j++)
    {
      name_r[j]=name[j];
    }
    for(int i=len;i>=0;i--)
    {
      name_r[j++]=num[i];
    }
    name_r[j]='\0';
    return name_r;
}
void makedict(int select[])
{
  char *name_r=cat(name,num);

  puts(name_r);

  ofstream fout(name_r);
  int ch[8];
  for(int i=0;i<8;i++)
  {
      ch[i]=pa[select[i]]-'a';
  }
  do
  {
    for(int i=0;i<8;i++)
      fout << (char)(ch[i]+'a');
  }while(fout <<endl,next_permutation(&ch[0],&ch[7]));

  increase();
}
int main()
{

  int select[8];

  fill(num,num+39,'0');
  for(ll i=5620;i<maxn;i++)//5620
  {
    memset(select,0,sizeof(select));
    int cnt=0;
    for(int j=0;j<26;j++)
    {
      if(cnt >8) break;
      if((1<<j)&i) select[cnt++]=j;
    }
    if(cnt==8)
    {
      cout << i <<endl;

      makedict(select);
    }

  }
  return 0;
}
