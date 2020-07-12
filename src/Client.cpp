
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include<ctype.h>
#include <signal.h>
#include<arpa/inet.h>
#define SA struct sockaddr


using namespace std;


int main(int argc,char**argv){

   struct sockaddr_in servaddr,cliaddr;
   int sockfd=socket(AF_INET,SOCK_STREAM,0);
   bzero(&servaddr,sizeof(servaddr));

   servaddr.sin_family=AF_INET;
   servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
   servaddr.sin_port=htons(atoi(argv[1]));

   inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
   connect(sockfd,(SA*)&servaddr,sizeof(servaddr));
   
   cout << "Hi, What are you wanna Quest for?  " ;
   char search_text[1000];
   scanf("%s",search_text);
   write(sockfd,search_text,sizeof(search_text));

   
   int notfound;
   read(sockfd,&notfound,sizeof(int));
   if(!notfound){
       int size;
       read(sockfd,&size,sizeof(int));
       char response[size];
       read(sockfd,response,sizeof(response)); 
       printf("\n%s",response);
   }
   else{
		cout << "Sorry Your search didn't match any documents." << endl;
   }

   close(sockfd);

}
