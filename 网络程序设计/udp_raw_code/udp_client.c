#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define ERR_EXIT(m) \ 
	do \ 
	{ \ 
		perror(m); \ 
		exit(EXIT_FAILURE); \ 
	} while(0)

void echo_cli(int sock)
{
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5000);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(sock, (struct sockaddr*)&servaddr, sizeof(servaddr));

	char sendbuf[1024] = {0};
	char recvbuf[1024] = {0};
	int ret;
	while(fgets(sendbuf, sizeof(sendbuf), stdin) != NULL)
	{
		//sendto(sock, sendbuf, strlen(sendbuf), 0, (struct sockaddr*) &servaddr, sizeof(servaddr));
		sendto(sock, sendbuf, strlen(sendbuf), 0, NULL, 0);
		//send(sock, sendbuf, strlen(sendbuf));
		ret = recvfrom(sock, recvbuf, sizeof(recvbuf), 0, NULL, NULL);
		if(ret < 0)
		{
			if(errno == EINTR)
				continue;
			ERR_EXIT("recvfrom");
		}
		fputs(recvbuf, stdout);
		memset(recvbuf, 0, sizeof(recvbuf));
		memset(sendbuf, 0, sizeof(sendbuf));
	}
	close(sock);
}

int main(int argc, char const *argv[])
{
	int sock;
	if((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
		ERR_EXIT("socket");

	echo_cli(sock);
	return 0;
} 
