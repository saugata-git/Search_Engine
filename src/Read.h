/*
   Quest :: A-Hypertextual-Web-Search-Engine
   Author:: Saugata Debnath
*/
#pragma once
ifstream fin;
string reader;

void read(int numOfPages, LinkedList *listPtr) {
	for (int i = 0; i < numOfPages; i++)
	{
		listPtr->insert(i);
		fin.open("data/"+to_string(i) + "_info.txt");
		fin >> reader;
		listPtr->getPageAt(i)->setPageID(i);
		fin >> reader;
		listPtr->getPageAt(i)->setPageLink(reader);
		fin >> reader;
		listPtr->getPageAt(i)->setTitle(reader);
		fin.close();

		fin.open("data/"+ to_string(i) + "_words.txt");
		while (!fin.eof()) {
			fin >> reader;
			listPtr->getPageAt(i)->setWords(reader);
		}
		fin.close();

		fin.open("data/"+to_string(i) + "_hyper.txt");
		while (!fin.eof()) {
			fin >> reader;
			listPtr->getPageAt(i)->setHyper(reader);
		}
		fin.close();
	}
}
