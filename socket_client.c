#include "socket_client.h"

int socket_init(socket_t* client, char* ip_address, u16 port, protocol_t protocol)
{
	client = (socket_t*) malloc(sizeof(socket_t));
	if (client == NULL) {
		return SOCKET_INIT;
	}

	strncpy(client->ip_address, ip_address, 16);
	client->port = port;

	client->socket = socket(AF_INET, (int) protocol, 0);
	if(client->socket == -1)
		return SOCKET_CREATE;

	client->address.sin_family = AF_INET;
	client->address.sin_port = htons(client->port);
	client->address.sin_addr.s_addr = inet_addr(client->ip_address);
	int status = connect(client->socket, (struct sockaddr*) &client->address, sizeof(client->address));
	if (status == -1) {
		perror("connect");
		return SOCKET_CONNECT;
	}

	return SOCKET_OK;
}
