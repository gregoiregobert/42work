#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENT 128
#define BUFFER_SIZE 120000

typedef struct s_clients {
	int id;
	char msg[1024];
} t_clients;

fd_set	activeSockets, readySockets;
int		next_id = 0, maxSockets = 0;
char	writeBuf[BUFFER_SIZE], readBuf[BUFFER_SIZE];
t_clients clients[MAX_CLIENT];

void	ft_error() {
	perror("Fatal error");
	exit(1);
}

void	sendAll(int not) {
	for (int i = 0; i <= maxSockets; i++)
		if (FD_ISSET(i, &activeSockets) && i != not)
			send(i, writeBuf, strlen(writeBuf), 0);
}

int main(int argc, char **argv) 
{
	if (argc != 2)
	{
		fprintf(stderr, "Wrong number of arguments\n");
		exit(1);
	}

	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket < 0)
		ft_error();

	struct sockaddr_in serverAddress = {0};
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	serverAddress.sin_port = htons(atoi(argv[1]));

	if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
		ft_error();

	if (listen(serverSocket, MAX_CLIENT) < 0)
		ft_error();
		
	FD_ZERO(&activeSockets);
	FD_SET(serverSocket, &activeSockets);
	maxSockets = serverSocket;

	while(1)
	{
		readySockets = activeSockets;

		if (select(maxSockets + 1, &readySockets, NULL, NULL, NULL) < 0)
			ft_error();

		for (int socketId = 0; socketId <= maxSockets; socketId++)
		{
			if (FD_ISSET(socketId, &activeSockets))
			{
				if (socketId == serverSocket)
				{
					int clientSocket = accept(serverSocket, NULL, NULL);
					if (clientSocket < 0)
						ft_error();
					FD_SET(clientSocket, &activeSockets);
					maxSockets = (clientSocket > maxSockets) ? clientSocket : maxSockets;

					sprintf(writeBuf, "server: client %d just arrived\n", next_id);
					sendAll(clientSocket);
					printf("laaaa\n");

					clients[clientSocket].id = next_id++;
				}
				else
				{
					int bytesRead = recv(socketId, readBuf, sizeof(readBuf), 0);
					if (bytesRead <= 0)
					{
						sprintf(writeBuf, "server: client %d just left\n", clients[socketId].id);
						sendAll(socketId);
						FD_CLR(socketId, &activeSockets);
						close(socketId);
					}
					else
					{
						for(int i = 0, j = strlen(clients[socketId].msg); i < bytesRead; i++, j++)
						{
							clients[socketId].msg[j] = readBuf[i];
							if (readBuf[i] == '\n')
							{
								clients[socketId].msg[j] = '\0';
								sprintf(writeBuf, "client %d: %s\n", clients[socketId].id, clients[socketId].msg);
								sendAll(socketId);
								bzero(&clients[socketId].msg, sizeof(clients[socketId].msg));
							}
						}
					}
				}
			}
		}
	}
}