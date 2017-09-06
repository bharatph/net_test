//dum_server.c
#include <stdio.h>
#include "network_utils.h"
#include "config.h"

int main(int argc, char *argv[]){
	int sockfd = start_server(DEFAULT_PORT);
	while(1){
		char *buf = (char *)malloc(1);
		int bytes_read = 0;
		if( (bytes_read = read(sockfd, buf, 1)) <= 0 ){
			continue;
		}
		printf("%s", buf);
	}
	return 0;
}
