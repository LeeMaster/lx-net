#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern int h_errno;

int main(void)
{   
    char * domain = "www.baidu.com";
    char dest[16];
    struct hostent * host = gethostbyname(domain);

    printf("%s\n",host -> h_name);
    printf("%s\n",inet_ntop(AF_INET,host ->h_addr_list[0],&dest[0],16));
    return 0;
}
