#include <stdio.h>
#include "network_utils.h"

int main(int argc, char *argv[]){
	int sockfd = connect_server("localhost", 5555);
	while(1){
		char *str = (char *)malloc(256);
		while(1){
			scanf("%s", str);
			write(sockfd, str, strlen(str));
			write(sockfd, "\n\r", 1);
		}
	}
	return 0;
}
