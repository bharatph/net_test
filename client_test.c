#include <stdio.h>
#include "network_utils.h"

int main(int argc, char *argv[]){
	int sockfd = start_server(5555);
	while(1){
		char *str = (char *)malloc(256);
		scanf("%s", str);
		int bytes_written = 0;
		if((bytes_written = write(sockfd, str, strlen(str))) <= 0){
			continue;
		}
	}
	return 0;
}
