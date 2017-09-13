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
		memset(str, '\0', 256);
		int len = 0;
		char c = '\0';
		while( (c=getchar()) != '\n'){
			str[len++] = c;
		}
		if (writeln(sockfd, str, len) < 0){
			log_err("CLIENT", "FATAL write error");
			close(sockfd);
			exit(-1);
		}
	}
	log_inf("CLIENT", "good exit");
	return 0;
}
