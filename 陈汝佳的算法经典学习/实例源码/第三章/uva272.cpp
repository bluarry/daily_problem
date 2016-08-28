//http://acm.hust.edu.cn/vjudge/problem/19396
#include <stdio.h>
int main()
{
	int c,q=1;
	while( (c=getchar()) != EOF ){
		if(c=='"'){
			printf("%s",q?"``":"''");
			q=!q;
		}
		else
			printf("%c",c );
	}

	return 0;
}