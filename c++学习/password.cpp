#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;


int main()
{
  ofstream fout("out.txt");
  char old[10]="amvibgwh";
  int old_dig[10],new_dig[10];
  for(int i=0;i<8;i++)
    new_dig[i]=old_dig[i]=old[i]-'a';
    int cha='A'-'a';
  for(int qq=1;qq<=8;qq++){
    for(int k=0;k<8;k++)new_dig[k]=old_dig[k];
    for(int j=0;j<qq;j++)
      new_dig[j]+=cha;

    do{
      for(int x=0;x<8;x++)
      fout << (char)(new_dig[x]+'a');
      fout <<endl;
    }while(next_permutation(&new_dig[0],&new_dig[7]));
}
  return 0;
}
