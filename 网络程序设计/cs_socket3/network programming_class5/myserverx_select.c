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


#define BACKLOG 5

void echo_serv(int conn)
{

	char recvbuf[1024];
	while(1){
		memset(recvbuf, 0, sizeof(recvbuf));
		int ret = read(conn, recvbuf, 1024);

		if(ret == -1) {
			printf("read error");
			break;
		}

		if(ret == 0)
		{
			printf("client close\n");
			break;
		}

		fputs(recvbuf, stdout);
		write(conn, recvbuf, strlen(recvbuf));
	}
}

int main(int argc, char** argv){

	if(argc != 2){
		fprintf(stderr, "Usage: %s [portnumber]\n", argv[0]);
		exit(1);
	}
	int PORT = atoi(argv[1]);


	int listenfd;
	if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("listen error\n");
	}

	struct sockaddr_in srvaddr;
    bzero(&srvaddr,sizeof(srvaddr));
  	srvaddr.sin_family = AF_INET;
  	srvaddr.sin_port = htons(PORT);
  	srvaddr.sin_addr.s_addr = htonl(INADDR_ANY);

  	int on = 1;
  	if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
  	{
  		printf("set sock error");
  	}

	if(bind(listenfd, (struct sockaddr *) &srvaddr, sizeof(srvaddr)) < 0)
	{
		printf("bind error\n");
		close(listenfd);
		exit(1);
	}

	if(listen(listenfd, BACKLOG) < 0)
	{
		printf("listen error\n");
	}

	struct sockaddr_in peeraddr;
	socklen_t peerlen;
	int conn;

	// 注意：多路复用不需要多进程（线程）

	int i;
	int client[FD_SETSIZE];
	for(i = 0; i < FD_SETSIZE; i++){
		client[i] = -1;
	}
	///
	int nready;
	int maxfd = listenfd;

	fd_set rset;
	fd_set aset;

	FD_ZERO(&rset);
	FD_ZERO(&aset);

	FD_SET(listenfd, &aset);

	while(1)
	{
		rset = aset;
		nready = select(maxfd + 1, &rset, NULL, NULL, NULL);
		if (nready == -1)
		{
			if(errno == EINTR){
				continue;
			}
			printf("select error\n");
		}

		if (nready == 0)
		{
			continue;
		}

		if(FD_ISSET(listenfd, &rset)) {
			peerlen = sizeof(peeraddr);
			if((conn = accept(listenfd, (struct sockaddr*) &peeraddr, &peerlen)) < 0)
			{
				printf("accept error");
			}

			for(i = 0; i <FD_SETSIZE; i++)
			{
				if(client[i] < 0)
				{
					client[i] = conn;
					if( i > maxfd)
						maxfd = i;
					break;
				}
			}

			if(i == FD_SETSIZE)
			{
				fprintf(stderr, "too many clients\n");
				exit(EXIT_FAILURE);
			}

			printf("received from client by accept: %s, %d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));

			FD_SET(conn, &aset);
			if(conn > maxfd)
				maxfd = conn;

			if(--nready <= 0)
				continue;
		}

		for(i = 0; i < maxfd; i++)
		{
			conn = client[i];
			if(conn == -1)
			{
				continue;
			}
			if(FD_ISSET(conn, &rset))
			{
				char recvbuf[1024];

				memset(recvbuf, 0, sizeof(recvbuf));
				int ret = read(conn, recvbuf, 1024);

				if(ret == -1) {
					printf("read error");
					break;
				}

				if(ret == 0)
				{
					printf("client close\n");
					FD_CLR(conn, &aset);
					client[i] = -1;
					break;
				}

				fputs(recvbuf, stdout);
				write(conn, recvbuf, strlen(recvbuf));

				if(-- nready <=0 )
				{
					break;
				}
			}
		}
	}
}
