#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_clients {
    int     id;
    char    msg[1024];
} t_clients;

t_clients   clients[1024];
fd_set      readfds, active;
int         fdMax = 0, idNext = 0;
char        readBuf[120000], writeBuf[120000];

void    ftError() {
	perror("Fatal error");
    exit(1);
}

void    sendAll(int not) {
    for(int i = 0; i <= fdMax; i++)
        if(FD_ISSET(i, &active) && i != not)
            send(i, writeBuf, strlen(writeBuf), 0);
}

int main(int ac, char **av) {
    if (ac != 2)
    {
		fprintf(stderr, "Wrong number of arguments");
		exit(1);
	}

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        ftError();

    struct sockaddr_in  servaddr = {0};
    servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	servaddr.sin_port = htons(atoi(av[1]));

    if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) < 0)
        ftError();

    if (listen(sockfd, 128) < 0)
        ftError();

    FD_ZERO(&active);
    FD_SET(sockfd, &active);
    fdMax = sockfd;

    while(1)
	{
        readfds = active;
        if (select(fdMax + 1, &readfds, NULL, NULL, NULL) < 0)
            ftError();

        for(int fdI = 0; fdI <= fdMax; fdI++) {
            if (FD_ISSET(fdI, &readfds) && fdI == sockfd)
			{
                int connfd = accept(sockfd, NULL, NULL);
                if (connfd < 0)
                    ftError();
                fdMax = connfd > fdMax ? connfd : fdMax;
                clients[connfd].id = idNext++;
                FD_SET(connfd, &active);
                sprintf(writeBuf, "server: client %d just arrived\n", clients[connfd].id);
                sendAll(connfd);
            }
            if (FD_ISSET(fdI, &readfds) && fdI != sockfd)
			{
                int res = recv(fdI, readBuf, sizeof(readBuf), 0);
                if (res <= 0) {
                    sprintf(writeBuf, "server: client %d just left\n", clients[fdI].id);
                    sendAll(fdI);
                    FD_CLR(fdI, &active);
                    close(fdI);
                }
                else
				{
                    for (int i = 0, j = strlen(clients[fdI].msg); i < res; i++, j++) {
                        clients[fdI].msg[j] = readBuf[i];
                        if (clients[fdI].msg[j] == '\n') {
                            clients[fdI].msg[j] = '\0';
                            sprintf(writeBuf, "client %d: %s\n", clients[fdI].id, clients[fdI].msg);
                            sendAll(fdI);
                            bzero(&clients[fdI].msg, strlen(clients[fdI].msg));
                            j = -1;
                        }
                    }
                }
            }
        }
    }
}