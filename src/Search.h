/*
   Quest :: A-Hypertextual-Web-Search-Engine
   Author:: Saugata Debnath
*/
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
	
	bool notfound = 1;
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

	for (int i = 0; i < numOfPages; i++)
	{
		if (listPtr->getPageAt(i)->wordSearch(word))
		{
			notfound = 0;
			cout << listPtr->getPageAt(i)->getPageTitle() << endl;
			cout << listPtr->getPageAt(i)->getPageLink() << endl << endl << endl;
		}
	}
	if (notfound)
		cout << "Sorry Your search didn't match any documents." << endl;
}
