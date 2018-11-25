#include "BasicUser.h"
#include "page.h"
#include "Member.h"
#include "HandelMemoryAllocation.h"


#include <iostream>
using namespace std;

Member:: Member(char* name, Date bDay) : BasicUser(name, KindOfBasicUser::Friend)
{
	this->pages = nullptr;
	this->maxSize = 0; //the size of the fist allocate
	this->sizePages = 0; //the index in array
	this->bDay = bDay;
}

void Member:: addPage(BasicUser* page) {
	
	if (this->pages == nullptr || this->maxSize == this->sizePages)
	{
		//this function expend the array
		this->pages = (BasicUser**)HandelMemAlloc::expendPointerArray((void**&)this->pages, this->maxSize);
	}

	this->pages[this->sizePages] = (BasicUser*) page;
	this->sizePages++;
}


void Member::showMembers()
{
	this->showFriends();
}

void Member:: showPages()
{
	/*
	if (this->pages != nullptr)
	{
		cout << "The pages are:\n";
		int i = 0;
		for (; i < sizeof(this->pages); i++)
		{
			cout << i + 1 << ") ";
			this->pages[i]->showPage; // use function of page class
		}
	}
	else {
		cout << "The friend doesn't like any page\n";
	}
	*/
}



Member :: ~Member() 
{
	
	/*if (this->pages != nullptr)
	{
		int i = 0;
		for (; i < this->sizePages; i++)
		{
			delete this->pages[i];
		}
	}*/
	

}