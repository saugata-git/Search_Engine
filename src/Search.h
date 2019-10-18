#pragma once

void search(int numOfPages, LinkedList *listPtr)
{
	string word;
	bool notfound = 1;
	cout << "Hi, What are you looking for?  ";
	cin >> word;
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