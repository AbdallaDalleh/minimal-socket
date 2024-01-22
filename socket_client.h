#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <poll.h>
#include <time.h>

#define MAX_ADDRESS_SIZE	15

#define SOCKET_OK		0
#define SOCKET_INIT		1
#define SOCKET_CREATE	2
#define SOCKET_CONNECT	3

typedef uint16_t u16;

typedef struct socket_client {
	char ip_address[MAX_ADDRESS_SIZE];
	u16 port;
	int fd;
	struct sockaddr_in address;
} socket_t;

typedef enum protocol_t {
	TCP = SOCK_STREAM,
	UDP = SOCK_DGRAM,
	RAW = SOCK_RAW
};

int socket_init(socket_t* client, char* ip_address, u16 port, protocol_t protocol);
int socket_write(socket_t* client, char* buffer, size_t count);
int socket_read(socket_t* client, char* buffer, size_t count);
int socket_close(socket_t* client);

