#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 128
#define BUFFER_SIZE 20000

typedef struct s_client {
	int id;
	char msg[BUFFER_SIZE];
} t_client;

void	ft_error()
{
	perror("Fatal Error");
	exit(1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Wrong number of arguments");
		exit(1);
	}

	t_client clients[MAX_CLIENTS];
	int clientSockets[MAX_CLIENTS];
	int next_id = 0;

	fd_set readySockets, activeSockets;
	char buffer[BUFFER_SIZE];

	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket < 0)
		ft_error();

	struct	sockaddr_in serverAddress = {0};
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	serverAddress.sin_port = htons(atoi(argv[1]));

	if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
		ft_error();

	if (listen(serverSocket, MAX_CLIENTS) < 0)
		ft_error();

	FD_ZERO(&activeSockets);
	FD_SET(serverSocket, &activeSockets);
	int maxSocket = serverSocket;

	while (1)
	{
		readySockets = activeSockets;
		if (select(maxSocket + 1, &readySockets, NULL, NULL, NULL) < 0)
			ft_error();

		for (int socketId = 0; socketId <= maxSocket; socketId++)
		{
			if (FD_ISSET(socketId, &readySockets))
			{
				if (socketId == serverSocket)
				{
					int clientSocket = accept(serverSocket, NULL, NULL);
					if (clientSocket < 0)
						ft_error();
					FD_SET(socketId, &readySockets);
					maxSocket = (socketId > maxSocket) ? socketId : maxSocket;

					sprintf(buffer, "server: client %d just arrived\n", next_id);
					for (int i = 0; i < maxSocket; i++)
						if (clientSockets[i] != socketId)
							send(clientSockets[i], buffer, strlen(buffer), 0);
					
					clients[socketId].id = next_id;
					clientSockets[next_id++] = clientSocket;
					 
				}
				else
				{
					int bytesRead = recv(socketId, buffer, sizeof(buffer) - 1, 0);

					if (bytesRead <= 0)
					{
						bzero(&buffer, strlen(buffer));
						sprintf(buffer, "server: client %d just left", clients[socketId].id);
						for (int i = 0; i < maxSocket; i++)
							if (clientSockets[i] != socketId)
								send(clientSockets[i], buffer, strlen(buffer), 0);
						close(socketId);
						FD_CLR(socketId, &activeSockets);
					}
					else 
					{
						buffer[bytesRead] = '\0';
						int j = -1;

						for (int i = 0; i < strlen(buffer); i++)
						{
							buffer[++j] = clients[socketId].msg[i];
							if (buffer[j] == '\n')
							{
								clients[socketId].msg[i] = '\0';
								for (int i = 0; i < maxSocket; i++)
									if (clientSockets[i] != socketId)
										send(clientSockets[i], clients[socketId].msg, strlen(clients[socketId].msg), 0);
								bzero(&clients[socketId].msg, strlen(clients[socketId].msg));
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