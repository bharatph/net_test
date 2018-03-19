//dum_server.c
#include <stdio.h>
#include "network_utils.h"
#include "config.h"

int main(int argc, char *argv[]){
	int sockfd = start_server(DEFAULT_PORT);
	if(sockfd < -1)return -1;
	while(1){
		char *buf = readln(sockfd);
		if(buf == NULL){
			printf("Client Disconnected\n");
			return -1;
		}
		writeln(sockfd, "Reading data done", 15);
		printf("%s\n", buf); 
	}
	return 0;
}
