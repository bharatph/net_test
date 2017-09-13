#include <stdio.h>
#include <signal.h>

#include "network_utils.h"

int sockfd = -1;

void exit_handler(int sig){
	close(sockfd);
	exit(0);
}

int main(int argc, char *argv[]){
	sockfd = connect_server("localhost", 5555);
	signal(SIGINT, exit_handler);
	while(1){
		char *str = (char *)malloc(256);
		read(1, str, 1);
		int bwrite = write(sockfd, str, 1);
		if(bwrite == 0){
			log_inf("CLIENT", "FIN Received back, breaking connection...");	
			exit(0);
		}
		else if(bwrite < 0){
			log_inf("CLIENT", "write error, exiting...");
			exit(-1);
		}
	}
	log_inf("CLIENT", "good exit");
	return 0;
}
