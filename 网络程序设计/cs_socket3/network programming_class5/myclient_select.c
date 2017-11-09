#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <strings.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>


void echo_cli(int sock)
{

	fd_set rset;
	FD_ZERO(&rset);

	// jiancedao shijian geshu
	int nready;

	int fd_stdin = fileno(stdin);
	int maxfd;

	if(fd_stdin > sock)
	{
		maxfd = fd_stdin;
	} else
	{
		maxfd = sock;
	}

	char sendbuf[1024]= {0};
	char recvbuf[1024]= {0};

	while(1){

		FD_SET(fd_stdin, &rset);
		FD_SET(sock, &rset);

		nready = select(maxfd + 1, &rset, NULL, NULL, NULL);
		if(nready == -1)
		{
			printf("select error");
		}
		if(nready == 0)
		{
			continue;
		}

		if(FD_ISSET(sock, &rset)){
			int ret = read(sock, recvbuf, sizeof(recvbuf));

			if(ret == 0 )
			{
				printf("server close\n");
				break;
			}

			fputs(recvbuf, stdout);
			memset(recvbuf, 0, sizeof(recvbuf));
		}
		if(FD_ISSET(fd_stdin, &rset)){
			if(fgets(sendbuf, sizeof(sendbuf), stdin) == NULL)
				break;
			write(sock,sendbuf,strlen(sendbuf));
		}


	}

	close(sock);
}

int main(int argc, char** argv){

	if(argc != 2){
		fprintf(stderr, "Usage: %s [portnumber]\n", argv[0]);
		exit(1);
	}
	int PORT = atoi(argv[1]);

	int sock;
	sock = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(connect(sock, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0)
	{
		printf("connect error\n");
		close(sock);
		exit(1);
	}

	echo_cli(sock);

}
