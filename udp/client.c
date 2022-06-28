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
    
int main() { 
    int sockfd; 
    char *msg = "Hello"; 
    int* a = (int*)malloc(sizeof(int));
    *a = 65;
    struct bth* transportHeader = (struct bth*)malloc(sizeof(struct bth));
    
    // uint8_t b = *a;
    // uint16_t c = *a;
    // c = c<<6;
    // printf("0x%02x, 0x%04x\n",b,c);
    struct sockaddr_in servaddr; 
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0){
        exit(1);
    }
    
    memset(&servaddr, 0, sizeof(servaddr)); 
         
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
        
    // sendto(sockfd, (uint8_t *)a, sizeof(*a/sizeof(uint8_t)), 0, (const struct sockaddr *) &servaddr, sizeof(servaddr)); 

    close(sockfd); 
    return 0; 
}