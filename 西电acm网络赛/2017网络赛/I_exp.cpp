#include <bits/stdc++.h>
 using namespace std;
 #if __cplusplus < 201103L
 #include <tr1/unordered_map>
 using std::tr1::unordered_map;
 #endif

 int BSGS(int a, int b, int M)
{
 assert(__gcd(a, M) == 1);
 if (M==1)
 return 0;
 b %= M; a %= M;
 if (b==1)
 return 0;
 int step = sqrt(M) + 1;
 long long x = 1, p = 1;
 unordered_map<int, int> mp;
 for (int i = 0; i < step; i++) {
 mp[p*b%M] = i;
 p = p*a%M;
 }
 for (long long i = step; i <= 1ll * step * step; i+=step) {
 unordered_map<int,int>::iterator it = mp.find(x=x*p%M);
 if (it != mp.end())
 return i-it->second;
 }
 return 1;
 }

 int pow_mod(int a, int b, int M)
 {
 if (!b)
 return 1%M;
 long long t = pow_mod(a, b>>1, M);
 t = t*t%M;
 if (b&1)
 t = t*a%M;
 return t;
 }

 int main()
 {
 int ya, yb, xa, xb;

 while (scanf("%d%d", &ya, &yb) == 2) {
 xa = BSGS(3, ya, INT_MAX);
 xb = BSGS(3, yb, INT_MAX);
 if (xa != 1 && xb != 1) {
 int k = pow_mod(yb, xa, INT_MAX);
 printf("%d\n", k);
 } else
 puts("No Solution");
 }
 return 0;
 }
