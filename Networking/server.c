#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int server_sockfd, client_sockfd;
	int server_len, client_len;

	struct sockaddr_un server_address;
	struct sockaddr_un client_address;

	unlink("server_socket");
	//TODO 1: Get the fd for the socket
	// For Local Sockets, family would be AF_UNIX, type SOCK_STREAM and protocol family 0
	//TODO 2: Initialize the sockaddr data structure
	//Initialize the fields sun_family and sun_path of server_address
	server_len = sizeof(server_address);

	//TODO 3: Bind the socket
	//TODO 4: Create the queue for listening 

	while (1)
	{
		char ch;
		printf("server waiting\n");
		client_len = sizeof(client_address);
		//TODO 5: Accept the connection
		//TODO 6: Read the variable from the client, increment and send it back to the client
	}
	return 0;
}
