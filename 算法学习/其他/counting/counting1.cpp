#include "stdio.h"
int main(){
    int n;
    int i;
  int a[10] = {0};
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        int k=i;
        while(k)
        {
            a[k%10]++;
            k = k/10;            
        }
    }
    
    for (i = 0; i < 10; i++)
        printf("%d\n", a[i]);
    return 0;
}
