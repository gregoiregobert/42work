#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

typedef struct s_client {
	int		id;
	char	msg[1024];
} t_client;

t_client	clients[128];
fd_set		activeSockets, readySockets;
int			idNext = 0, fdMax = 0;
char		bufferWrite[120000], bufferRead[120000];

void	ft_error() {
	perror("Fatal Error");
	exit(1);
}

void	sendAll(int not) {
	for (int i = 0; i <= fdMax; i++)
		if (FD_ISSET(i, &active) && i != not)
			send(i, bufferWrite, strlen(bufferWrite), 0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Wrong number of arguments");
		exit(1);
	}

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		ft_error();

	struct sockaddr_in serverAddress = {0};
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	serverAddress.sin_port = htons(atoi(argv[1]));

	if (bind(sockfd, (const struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
		ft_error();

	if (listen(sockfd, 128) < 0)
		ft_error();
	
	FD_ZERO(&activeSocket);
	FD_SET(sockfd, &activeSocket);
	fdMax = sockfd;

	while(1)
	{
		readfds = activeSocket;
		if (select(fdMax + 1, &readfds, NULL, NULL, NULL) < 0)
			ft_error();

		for (int fdI = 0; fdI <= fdMax; fdI++) {
			if (FD_ISSET(fdI, &readfds) && fdI == sockfd)
			{
				int clientSocket = accept(sockfd, NULL, NULL);
				if (clientSocket < 0)
					ft_error();
				fdMax = (clientSocket > fdMax) ? clientSocket : fdMax;
				clients[clientSocket].id = idNext;
				FD_SET(clientSocket, &activeSocket);
				sprintf(bufferWrite, "server: client %d just arrived\n", idNext++);
				sendAll(clientSocket);
			}
			if (FD_ISSET(fdI, &readfds) && fdI != sockfd)
			{
				int bytesRead = recv(fdI, bufferRead, sizeof(bufferRead), 0);
				if (bytesRead <= 0)
				{
					sprintf(bufferWrite, "server: client %d just left\n", clients[fdI].id);
					sendAll(fdI);
					FD_CLR(fdI, &activeSocket);
					close(fdI);
				}
				else 
				{
					for (int i = 0, j = strlen(clients[fdI].msg); i < bytesRead; i++, j++)
					{
						clients[fdI].msg[j] = bufferRead[i];
						if (bufferRead[i] == '\n')
						{		
							clients[fdI].msg[j] = '\0';
							sprintf(bufferWrite, "client %d: %s\n", clients[fdI].id, clients[fdI].msg);
							sendAll(fdI);
							bzero(clients[fdI].msg, sizeof(clients[fdI].msg));
							j = -1;
						}
					}
				}
			}
		}
	}
}