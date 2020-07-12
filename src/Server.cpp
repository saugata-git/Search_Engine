
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include "LinkedList.h"
#include "Page.h"
#include "Read.h"
#include "Rank.h"
#include "Search.h"

using namespace std;
int main(int argc,char**argv){
      

	LinkedList* listPtr = new LinkedList();
	const int numOfPages = 10;
	read(numOfPages, listPtr);
	ranking(numOfPages, listPtr);
	listPtr->Sort();
        search(numOfPages, listPtr,argv[1]);
}
