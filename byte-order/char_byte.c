#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdio.h>

int main(void)
{
    printf("0x%x\n",htonl(0xaabbccdd));
    printf("0x%x\n",htons(0xaabb));
    printf("0x%x\n",ntohl(0xaabbccdd));
    printf("0x%x\n",ntohs(0xaabb));
    
    return 0;
}
