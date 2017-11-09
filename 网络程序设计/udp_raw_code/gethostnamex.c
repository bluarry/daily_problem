#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <strings.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <netdb.h>

int main()
{ 
	char host[100] ={0};
	if(gethostname(host, sizeof(host)) < 0)
	{
		printf("get host name error\n");
	} 

	struct hostent *hp;

	int i = 0;
	while( hp->h_addr_list[i] != NULL)
	{
		printf( "%s\n", inet_ntoa(*(struct in_addr*)hp->h_addr_list[i]) );
		i++;
	}

	return 0;
}