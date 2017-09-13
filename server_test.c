//dum_server.c
#include <stdio.h>
#include "network_utils.h"
#include "config.h"

int main(int argc, char *argv[]){
	int sockfd = start_server(DEFAULT_PORT);
	if(sockfd < -1)return -1;
	while(1){
		char *buf = (char *)malloc(256);
		int ptr = 0;
		memset(buf, '\0', 256);
		for(ptr=0; buf[ptr] != '\n' || buf[ptr] != '\0' || buf[ptr] != '\r'; ptr++){
			int bread = read(sockfd, buf+ptr, 1);
			log_inf("SERVER", "buf[%d] :%c", ptr,  buf[ptr]);
		}
		log_inf("SERVER", "%s", buf);
	}
	return 0;
}
