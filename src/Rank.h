#pragma once

void ranking(int numOfPages, LinkedList *listPtr) {
	for (int i = 0; i < numOfPages; i++)
	{
		for (int n = 0; n < numOfPages; n++)
		{
			int x = listPtr->getPageAt(n)->hyperSearch(listPtr->getPageAt(i)->getPageLink());
			for (int a = 0; a < x; a++)
			{
				listPtr->getPageAt(i)->setRanking(listPtr->getPageAt(n)->getPageID());
			}
		}
	}

	for (int i = 0; i < numOfPages; i++) {
		listPtr->getPageAt(i)->setRank(1.0 / numOfPages);
	}

	double curRank;
	double *arrPtr = new double[numOfPages];
	for (int z = 0; z < 3; z++)
	{
		for (int i = 0; i < numOfPages; i++)
		{
			curRank = 0.0;
			vector<int>* ptr = new vector<int>;
			for (int a = 0; a < listPtr->getPageAt(i)->getRanking()->size(); a++)
			{
				ptr->push_back(listPtr->getPageAt(i)->getRanking()->at(a));
			}
			int ptrSize = ptr->size();
			for (int n = 0; n < ptrSize; n++)
			{
				curRank += (listPtr->getPageAt(ptr->back())->getRank() / listPtr->getPageAt(ptr->back())->getHyper()->size());
				ptr->pop_back();
			}
			arrPtr[i] = curRank;
		}
		for (int i = 0; i < numOfPages; i++)
		{
			listPtr->getPageAt(i)->setRank(arrPtr[i]);
		}
	}
}