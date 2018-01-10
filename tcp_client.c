#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>


#include <netinet/in.h>

int main(void){
	
	//create socket
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);
	
	// specify an address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9001);
	server_address.sin_addr.s_addr = INADDR_ANY;

	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

	if(connection_status == -1){
		printf("There was an error with the connection\n");
	}
	//receive data from the server
	char server_resonse[256];

	recv(network_socket, &server_resonse, sizeof(server_resonse), 0);

	//Print out the data from the server
	printf(" SERVER REPONSE :: %s\n", server_resonse);

	//close the socket

	close(network_socket);

	printf("Test\n");
	return 0;

}
