#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int map[105][105];

int main()
{
  int n,m;
  int count=1;
  while(cin >> n >> m && n && m)
  {
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
      {
          char c;
         cin >> c;
          if(c=='.') map[i][j]=0;
          else
          map[i][j]=-1;
      }


      count == 1 ? cout << "Field #"<< count<< ":" << endl: cout << "\nField #"<< count<< ":"<< endl;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
      {
            if(map[i][j]==-1)
            {
                if( map[i-1][j] !=-1 && i-1 >=0) map[i-1][j]++; //上
                 if(  map[i+1][j]!=-1  && i+1 < n) map[i+1][j]++;//下
                 if( map[i][j-1]!=-1 && j-1 >=0) map[i][j-1]++;//左
                if( map[i][j+1]!=-1 && j+1 < m) map[i][j+1]++;//右
                if( map[i-1][j-1] !=-1 && i-1 >=0  && j-1 >=0 ) map[i-1][j-1]++;//左上
                 if( map[i-1][j+1]!=-1 && i-1 >=0 && j+1 < m ) map[i-1][j+1]++;//右上
                if( map[i+1][j-1]!=-1 && i+1 < n   && j-1 >=0) map[i+1][j-1]++;//左下
                 if( map[i+1][j+1]!=-1 && i+1 < n && j+1 < m ) map[i+1][j+1]++;//右下
            }
      }
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
     {
         if(map[i][j]!=-1)
         j==m-1 ? cout << map[i][j] << endl: cout << map[i][j];
         else
         j==m-1 ? cout << '*'<< endl: cout << '*';
     }
        count++;
  }




  return 0;
}
