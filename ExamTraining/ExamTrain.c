#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct sclients {
	int id;
	char msg[120000];
} t_clients;

t_clients clients[128];
fd_set readfds, writefds, active;
int nextId = 0, fdMax = 0;
char writeBuf[120000], readBuf[120000];

void	ft_error()
{
	perror("Fatal error");
	exit(1);
}

void	sendAll(int not)
{
	for (int i = 0; i <= fdMax; i++)
		if (FD_ISSET(i, &writefds) && i != not)
			send(i, writeBuf, strlen(writeBuf), 0);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "Wrong number of arguments\n");
		exit(1);
	}

	int serverSock = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSock < 0)
		ft_error();

	struct sockaddr_in serverAddr = {0};
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	serverAddr.sin_port = htons(atoi(av[1]));;

	if (bind(serverSock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
		ft_error();

	if (listen(serverSock, 128) < 0)
		ft_error();

	FD_ZERO(&active);
	FD_SET(serverSock, &active);
	fdMax = serverSock;

	while(1)
	{
		readfds = writefds = active;
		if (select(fdMax + 1, &readfds, &writefds, NULL, NULL) < 0)
			ft_error();

		for (int fdI = 0; fdI <= fdMax; fdI++)
		{
			if (FD_ISSET(fdI, &readfds))
			{
				if (fdI == serverSock)
				{
					int clientSock = accept(serverSock, NULL, NULL);
					if (clientSock < 0)			
						ft_error();
					fdMax = (clientSock > fdMax) ? clientSock : fdMax;
					clients[clientSock].id = nextId++;
					sprintf(writeBuf, "server: client %d just arrived\n", clients[clientSock].id);
					sendAll(clientSock);
					FD_SET(clientSock, &active);
				}
				else
				{
					int res = recv(fdI, readBuf, sizeof(readBuf), 0);
					if (res <= 0)
					{
						sprintf(writeBuf, "server: client %d just left\n", clients[fdI].id);
						sendAll(fdI);
						FD_CLR(fdI, &active);
						close(fdI);
					}
					else
					{
						for (int i = 0, j = strlen(clients[fdI].msg); i < res; i++, j++)
						{
							clients[fdI].msg[j] = readBuf[i];
							if (clients[fdI].msg[j] == '\n')
							{
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
	return 0;
}