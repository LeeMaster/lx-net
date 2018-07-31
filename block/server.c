#include "server.h"

const int port = 8080;

void _handle_request(int client_fd,struct sockaddr_in * sockaddr)
{
    char buffer[MAX_LEN];
    printf("0x%x\n",ntohl(sockaddr ->sin_addr.s_addr)); 
    while(read(client_fd,buffer,MAX_LEN))
    {
        printf("%s",buffer);
    }
}

void _handle_response(int socket_fd,char * buffer)
{
    write(socket_fd,buffer,sizeof(buffer));
}


int main(void)
{
    int socket_fd , client_fd;
    struct sockaddr_in sockaddr;
    struct sockaddr_in client_addr;
    socklen_t client_len;
    char * response = "Receive Response \n";
    int err_log ;    

    socket_fd = socket(AF_INET,SOCK_STREAM,0);
    if(socket_fd == -1)
    {
            perror("Socket fd faild");
            exit(1);
    }

    memset(&sockaddr ,0 ,sizeof(sockaddr));
    
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(port);
    sockaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    err_log = bind(socket_fd,(struct sockaddr*)&sockaddr,sizeof(struct sockaddr_in));
    if(err_log == -1)
    {
        perror("Bind faild\n");
        exit(1);
    }

    err_log = listen(socket_fd,1024);
    if(err_log == -1)
    {
        perror("Listen faild");
        exit(1);
    }
    client_len = sizeof(struct sockaddr_in);
    for(;;)
    {
            memset(&client_addr,0,sizeof(client_addr));
            client_fd = accept(socket_fd,(struct sockaddr *)&client_addr,&client_len);
      
            _handle_request(client_fd,&client_addr);
            _handle_response(client_fd,response);
      
            close(client_fd);
    }

    close(socket_fd);

    return 0;
}
