#ifndef __BLOCK_SERVER_H__
#define __BLOCK_SERVER_H__ 
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>

#define MAX_LEN 1024

void _handle_request(int client_fd,struct sockaddr_in * sockaddr);

void _handle_response(int socket_fd,char * buffer);

#endif

