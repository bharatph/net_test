//server.cpp
#include<iostream>
#include "Node.h"

#define ENABLE_LOG

int main(int argc, char *argv[]){
	Node n;
	n.start_server(7300);
	n.connect_server("localhost", 7300);
	return 0;
}
