#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int  main()
{
  int a[3][3];
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
      a[i][j]=i+j;


  int b[3][3];
  memcpy(b,a,sizeof(a));

  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    j==2?cout << b[i][j]<<endl:cout << b[i][j]<<" ";


  return 0;
}
