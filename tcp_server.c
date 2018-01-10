#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>


#include <netinet/in.h>

int main(void){

		char server_messsage[256] = "You have reached ther server!\n";

		//create the server socket
		int server_socket;
		server_socket = socket(AF_INET, SOCK_STREAM, 0);

		//define the server address
		struct sockaddr_in server_address;

		//9001 one for me
		server_address.sin_family = AF_INET;
		server_address.sin_port = htons(9001);
		server_address.sin_addr.s_addr = INADDR_ANY;

		//bind the socket to our specified IP and PORT
		bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

		//listen for connections
		listen(server_socket, 10);

		//client socket 
		int client_socket;
		client_socket = accept(server_socket, NULL, NULL);

		//send message to client server
		send(client_socket, server_messsage, sizeof(server_messsage), 0);

		//close
		close(server_socket);

}