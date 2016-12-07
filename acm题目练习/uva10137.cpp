#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n), n){
        double money[1000+5]={0},sum=0;
        double ave=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf",&money[i]);
            sum +=money[i];
        }
        ave=round(sum/n*100)/100;
        double sum1=0,sum2=0;
        for(int i=0;i<n;i++)
        {
            if(money[i]-ave > 0) sum1+=(money[i]-ave);
            else sum2+=(ave-money[i]);
        }
        ave=min(sum1,sum2);
        printf("$%.2lf\n",ave);
    }
    return 0;
}
/*in
21
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.03
6
12.00
11.99
11.95
5.55
5.54
5.53
6
12.00
11.99
11.96
5.55
5.54
5.53
6
12.00
11.99
11.97
5.55
5.54
5.53
6
12.00
11.99
11.98
5.55
5.54
5.53
6
12.00
11.99
11.99
5.55
5.54
5.53
6
12.00
11.99
11.99
5.56
5.54
5.53
2
12.00
12.00
1
99.99
0
*/
