#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
#include "Page.h"
#include "Read.h"
#include "Rank.h"
#include "Search.h"


using namespace std;
int main()
{
	LinkedList* listPtr = new LinkedList();
	const int numOfPages = 10;
	read(numOfPages, listPtr);
	ranking(numOfPages, listPtr);
	listPtr->Sort();
	bool con = 0;
	char x;
	do {
		search(numOfPages, listPtr);
		cout << "do you want to continue? (y/n):";
		enter:cin >> x;
		if (x == 'y' || x == 'Y') 
		{
			con = 1;
			system("CLS");
		}
		else if (x == 'n' || x == 'N')
			con = 0;
		else
		{
			cout << "please enter a valid character:";
			goto enter;
		}
	} while (con);
	system("pause");
}
