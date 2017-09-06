//dum_server.c
#include <stdio.h>
#include "network_utils.h"
#include "config.h"

int main(int argc, char *argv[]){
	int sockfd = start_server(DEFAULT_PORT);
	return 0;
}
