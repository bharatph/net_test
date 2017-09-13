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
		int quit=0;
		for(ptr=0;quit!=1;ptr++){
			int bread = read(sockfd, buf+ptr, 1);
			if(bread > 0){
				//log_inf("SERVER", "Content read[%d]: %c", ptr, buf[ptr]);
				if(buf[ptr] == '\n'){
					buf[ptr] = '\0';
					quit = 1;
				}
			}
			else if(bread == 0){//EOF hit, client disconnected
				log_inf("SERVER", "EOF hit");
				quit=1;
			}
			else if(bread < 0){ //read error
				log_inf("SERVER", "read error exiting...");
				exit(-1);
			}
		}
		//sleep(1);
		if(buf[0] == '\0'){ //FIXME use non-char checking, such as size??
			return -1;
		}
		log_inf("SERVER", "%s", buf);
	}
	return 0;
}
