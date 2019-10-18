#pragma once
#include "Page.h"
#include <assert.h>  
class LinkedList
{
private:
	int itemCount;

public:

	page *headPtr;
	LinkedList();
	~LinkedList();
	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition);
	page* getPageAt(int position) const;
	bool remove(int position);
	void clear();
	void Sort();

};

LinkedList::LinkedList() : headPtr(nullptr), itemCount(0)
{
}

LinkedList::~LinkedList()
{
	clear();
}

void LinkedList::clear()
{
	while (!isEmpty())
		remove(0);
}

bool LinkedList::remove(int position)
{
	bool ableToRemove = (position >= 0) && (position < itemCount);
	if (ableToRemove)
	{
		page* curPtr = nullptr;
		if (position == 0)
		{
			curPtr = headPtr;
			headPtr = headPtr->getNext();
		}
		else
		{
			page* prevPtr = getPageAt(position - 1);
			curPtr = prevPtr->getNext();
			prevPtr->setNext(curPtr->getNext());
		}

		curPtr->setNext(nullptr);
		delete curPtr;
		curPtr = nullptr;
		itemCount--;
	}

	return ableToRemove;
}

page* LinkedList::getPageAt(int position) const
{
	assert((position >= 0) && (position < itemCount));
	page* curPtr = headPtr;
	for (int i = 0; i < position; i++)
		curPtr = curPtr->getNext();

	return curPtr;
}

bool LinkedList::insert(int newPosition)
{
	bool ableToInsert = (newPosition >= 0) && (newPosition <= itemCount);
	if (ableToInsert)
	{
		page* newPagePtr = new page();
		if (newPosition == 0)
		{
			headPtr = newPagePtr;
			newPagePtr->setNext(NULL);

		}
		else
		{
			page* prevPtr = getPageAt(newPosition - 1);
			newPagePtr->setNext(prevPtr->getNext());
			prevPtr->setNext(newPagePtr);
		}

		itemCount++;
	}
	return ableToInsert;
}

bool LinkedList::isEmpty() const
{
	return itemCount == 0;
}

int LinkedList::getLength() const
{
	return itemCount;
}

void LinkedList::Sort()
{
	bool swapped;
	page* ptr;
	do {
		swapped = 0;
		for (int i = 0; i < (getLength() - 1); i++) 
		{
			if (getPageAt(i)->getRank() < getPageAt(i + 1)->getRank())
			{
				if (i == 0)
				{
					ptr = headPtr;
					headPtr = ptr->getNext();
					ptr->setNext(headPtr->getNext());
					headPtr->setNext(ptr);
				}
				else
				{
					ptr = getPageAt(i - 1)->getNext();
					getPageAt(i - 1)->setNext(ptr->getNext());
					ptr->setNext(getPageAt(i)->getNext());
					getPageAt(i)->setNext(ptr);
				}
				swapped = 1;
			}
		}
	} while (swapped);
}