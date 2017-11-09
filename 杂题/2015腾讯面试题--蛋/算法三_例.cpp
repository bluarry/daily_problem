#include <iostream> 
#include <math.h> 
#define maxlogn 20 

#define maxnum 1000000000 
 
long n,eggnum,now,old,g[maxlogn+1]; 
 
void init() 
{ 
 long i; 
 for (i=1; i<=eggnum; i++) 
  g[i]=1; 
} 
  
void work() 
{ 
 long i,j; 
 for (i=2; i<=n; i++) 
  { 
   for (j=eggnum; j>=2; j--) 
    { 
     g[j]=g[j-1]+g[j]+1; 
     if ((j==eggnum)&&(g[j]>=n)) 
      { 
       std::cout<<i<<std::endl; 
       return; 
      } 
    } 
   g[1]=i; 
   if ((eggnum==1)&&(g[1]>=n)) 
    { 
     std::cout<<i<<std::endl; 
     return; 
    } 
  } 
} 
 
int main() 
{ 
 long temp; 
 while ( std::cin>>eggnum ) 
  { 
    std::cin>>n; 
       temp=long (floor(log(n+0.0)/log(2.0))+1.0); 
   if (eggnum>=temp) 
    std::cout<<temp<<std::endl; 
    else { 
          init(); 
          if(g[eggnum]>=n) 
           std::cout<<1<<std::endl; 
           else if (eggnum==1) 
                 std::cout<<n<<std::endl; 
                 else work(); 
         } 
  } 
 return 0; 
} 
