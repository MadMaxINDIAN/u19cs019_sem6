#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr
void func(int connfd)
{
char buff[MAX];
int n;
bzero(buff, MAX);
read(connfd, buff, sizeof(buff));
printf("\nFrom client: %s", buff);
}
int main()
{
int sockfd, connfd, len;
struct sockaddr_in servaddr, cli;
sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (sockfd == -1)
{
printf("\nSocket creation failed...\n");
exit(0);
}
else
printf("\nSocket successfully created..\n");
bzero(&servaddr, sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(PORT);
if ((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0)
{
printf("\nSocket bind failed...\n");
exit(0);
}
else
printf("\nSocket successfully binded..\n");
if ((listen(sockfd, 5)) != 0)
{
printf("\nListen failed...\n");
exit(0);}
else
printf("\nServer listening..\n");
len = sizeof(cli);
connfd = accept(sockfd, (SA *)&cli, (socklen_t*)&len);
if (connfd < 0)
{
printf("\nServer didn't accept the client...\n");
exit(0);
}
else
printf("\nServer accepted the client...\n");
func(connfd);
close(sockfd);
}