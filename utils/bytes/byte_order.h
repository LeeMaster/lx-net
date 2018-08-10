#ifndef __BYTE_ORDER_H__
#define __BYTE_ORDER_H__ 

#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>

struct sockaddr_in *
build_sock_addr(struct sockaddr_in * addr, int port,const char * domain);

uint32_t get_domain_ip(const char * domain);


#endif
