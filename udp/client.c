#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
    
#define PORT    4420 
    
int main() { 
    int sockfd; 
    char *msg = "Hello"; 
    struct sockaddr_in servaddr; 
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0){
        exit(1);
    }
    
    memset(&servaddr, 0, sizeof(servaddr)); 
         
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
        
    sendto(sockfd, (const char *)msg, strlen(msg), MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr)); 
    
    close(sockfd); 
    return 0; 
}