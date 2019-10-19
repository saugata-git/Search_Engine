#pragma once

#include <bits/stdc++.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#define SA struct sockaddr


void search(int numOfPages, LinkedList *listPtr,char* port){
	
	int notfound = 1;
        struct sockaddr_in servaddr,cliaddr;
        int sockfd=socket(AF_INET,SOCK_STREAM,0);
        bzero(&servaddr,sizeof(servaddr));

        servaddr.sin_family=AF_INET;
        servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
        servaddr.sin_port=htons(atoi(port));

        bind(sockfd,(SA*)&servaddr,sizeof(servaddr));
        listen(sockfd,5);
        socklen_t  clilen=sizeof(cliaddr);
        int connfd=accept(sockfd,(SA*)&cliaddr,&clilen);


      
        char search_text[10000];
        read(connfd,search_text,sizeof(search_text)); 
        string word=search_text;
	cout << endl << endl;

        string response="";
 
	for (int i = 0; i < numOfPages; i++)
	{
		if (listPtr->getPageAt(i)->wordSearch(word))
		{
			notfound = 0;
                        string str1= listPtr->getPageAt(i)->getPageTitle()+"\n";
                        string str2= listPtr->getPageAt(i)->getPageLink()+"\n\n";
                        
                        response+=str1+str2;
		}
	}

        write(connfd,&notfound,sizeof(int));

        if(!notfound){
              int size=response.length()+1;
              char response_txt[size];
              strcpy(response_txt,response.c_str());
              write(connfd,&size,sizeof(int));
              write(connfd,response_txt,sizeof(response_txt));
              cout<<"Response send";
         }
         else{
             cout<<"Unable to send the request";
         }
	
}
