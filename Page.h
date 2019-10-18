#pragma once
#include <vector>
using namespace std;

class page
{
private:
	int ID;
	string pageLink;
	string title;
	vector<string> *words = new vector<string>;
	vector<string> *hyperLinks = new vector<string>;
	double rank;
	vector<int> *ranking = new vector<int>;
	page* next;

public:
	void setPageID(int ID);
	int getPageID();
	void setPageLink(string pageLink);
	string getPageLink();
	void setTitle(string title);
	string getPageTitle();
	void setWords(string word);
	void setHyper(string hyper);
	vector<string> *getHyper();
	bool wordSearch(string word);
	int hyperSearch(string hyper);
	void setRank(double rank);
	double getRank();
	void setRanking(int id);
	vector<int>* getRanking();
	page* getNext() const;
	void setNext(page* nextNodePtr);

};

void page::setPageID(int ID)
{
	this->ID = ID;
}

int page::getPageID()
{
	return ID;
}

void page::setPageLink(string pageLink)
{
	this->pageLink = pageLink;
}
string page::getPageLink()
{
	return pageLink;
}

void page::setTitle(string title)
{
	this->title = title;
}

string page::getPageTitle()
{
	return title;
}

void page::setWords(string word)
{
	words->push_back(word);
}

void page::setHyper(string hyper)
{
	hyperLinks->push_back(hyper);
}

vector<string> *page::getHyper()
{
	return hyperLinks;
}

bool page::wordSearch(string word)
{
	for (int i = 0; i < words->size(); i++)
		if (word == words->at(i))
			return 1;
	return 0;
}

int page::hyperSearch(string hyper)
{
	int count = 0;
	for (int i = 0; i<hyperLinks->size(); i++)
		if (hyper == hyperLinks->at(i))
			count++;

	return count;
}

void page::setRank(double rank)
{
	this->rank = rank;
}

double page::getRank()
{
	return rank;
}

void page::setRanking(int id)
{
	this->ranking->push_back(id);
}

vector<int>* page::getRanking()
{
	return ranking;
}

void page::setNext(page* nextNodePtr)
{
	next = nextNodePtr;
}

page* page::getNext() const
{
	return next;
}
