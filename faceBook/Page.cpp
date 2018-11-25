
#include "page.h"
#include <iostream>
using namespace std;



Page::Page(char* name) : BasicUser(name, KindOfBasicUser ::Page)
{
	/*this->size = 0;
	this->maxSize = 0;
	//this->allMembers = nullptr;*/
}



void Page::showMembers()
{
	this->showStatus();
}

void Page:: showPage()
{
	this->showBasicUser();
}

void Page::showFans()
{
	this->showFriends();
	/*if (this->allMembers != nullptr) {
		cout << "The friends are:\n";
		for (int i = 0; i < sizeof(this->allMembers); i++) {
			cout << i + 1 << ") ";
			this->allMembers[i]->showBasicUser();
		}
	}*/
	
}

 /*Page:: ~Page()
{
	
}*/