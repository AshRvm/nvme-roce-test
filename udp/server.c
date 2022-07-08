#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include "bth.h"
    
#define PORT    4420 
#define MAXLINE 1024 
    
int main() { 
    int sockfd; 
    // char buffer[MAXLINE]; 
    uint8_t buffer[MAXLINE];
    struct sockaddr_in servaddr, cliaddr; 

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0){
        exit(1);
    }    
        
    memset(&servaddr, 0, sizeof(servaddr)); 
    memset(&cliaddr, 0, sizeof(cliaddr)); 
        
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
        
    if(bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){ 
        exit(1);
    } 
        
    int len, n; 
    len = sizeof(cliaddr);
    n = recvfrom(sockfd, (uint8_t *)buffer, MAXLINE, 0, ( struct sockaddr *) &cliaddr, &len); 
    struct bth *rec_bth = (struct bth *)buffer;
    uint8_t a1 = rec_bth->opcode;
    uint8_t a2 = rec_bth->flags;
    uint16_t a3 = ntohs(rec_bth-> pkey);
    uint32_t a4 = ntohl(rec_bth-> qpn);
    uint32_t a5 = ntohl(rec_bth->apsn);
    printf("opcode=0x%02x flags=0x%02x pkey=0x%04x qpn=0x%08x apsn=0x%08x\n", a1, a2, a3, a4, a5);

    // buffer[n] = '\0'; 
    // printf("Message: %s.\n", buffer);  
        
    return 0; 
}