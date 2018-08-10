#include "byte_order.h"

struct sockaddr_in * 
build_sock_addr(struct sockaddr_in * addr, int port,const char * domain)
{
    memset(addr , 0,sizeof(struct sockaddr_in));
    addr -> sin_family = AF_INET;
    addr -> sin_port = htons(port);
    addr -> sin_addr.s_addr = get_domain_ip(domain);

    return addr; 
}

uint32_t 
get_domain_ip(const char * domain)
{
    struct hostent *  host = gethostbyname(domain);
    if(host == NULL)
    {
        
        exit(-1);
    }
    return inet_addr(host ->h_addr_list[0]);
}


