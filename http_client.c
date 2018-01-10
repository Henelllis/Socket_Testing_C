#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>


#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv){

	char *address;
	address = argv[1];

	
	//create socket
	int client_socket;
	client_socket = socket(AF_INET, SOCK_STREAM, 0);
	
	// specify an address for the socket
	struct sockaddr_in remote_address;
	remote_address.sin_family = AF_INET;
	remote_address.sin_port = htons(80);
	inet_aton(address, &remote_address.sin_addr.s_addr);
	//remote_address.sin_addr.s_addr = INADDR_ANY;

	int connection_status = connect(client_socket, (struct sockaddr *) &remote_address, sizeof(remote_address));

	char request[] = "GET / HTTP/1.1\r\n\r\n";
	char response[4096];

	send(client_socket, request, sizeof(request), 0);

	recv(client_socket, &response, sizeof(response), 0);

	//Print out the data from the server
	printf(" SERVER REPONSE :: %s\n", response);

	//close the socket

	close(client_socket);

	return 0;

}
