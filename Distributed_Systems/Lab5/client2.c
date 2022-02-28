#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr
void func(int sockfd)
{
FILE *fp;
fp = popen("./cpu.sh", "r");
char buff[1024];
if (fp)
{
while (1)
{
char *line;
line = fgets(buff, sizeof(buff), fp);
if (!line)
{
break;
}
printf("\n%s", line);
}
pclose(fp);
}
write(sockfd, buff, sizeof(buff));
}
int main()
{
int sockfd, connfd;
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
servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
servaddr.sin_port = htons(PORT);
if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) != 0)
{
printf("\nServer connection failed...\n");
exit(0);
}
else
printf("\nConnected to the server..\n");
func(sockfd);
close(sockfd);
}