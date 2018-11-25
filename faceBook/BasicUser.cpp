#include "BasicUser.h"
#include "HandelMemoryAllocation.h"
#include <iostream>
using namespace std;

BasicUser::BasicUser(char* name, KindOfBasicUser type)
{
	//אפשר לעשות עם stud
	int size;
	size = strlen(name);
	this->name = new char[size+1];
	strcpy(this->name, name);
	this->sizeOfFriend = 0;
	this->sizeOfStatus = 0;
	this->maxIndexOfFriend = 0;
	this->maxIndexOfStatus = 0;
	this->allStatus = nullptr;
	this->type = type;

}

char* BasicUser::getName()
{
	return this->name;
}

/*BasicUser::BasicUser(char* name)
{
	int size;
	size = strlen(name);
	this->name = new char[size];
	strcpy(this->name, name);
	this->allStatus = nullptr;
	this->type = type;

}*/


void BasicUser :: addFriend(BasicUser* user) {
	//
	if (this->friends == nullptr || this->maxIndexOfFriend == this->sizeOfFriend) 
	{
		//this function expend the array
		this->friends = (BasicUser**)HandelMemAlloc::expendPointerArray((void**&)this->friends, this->maxIndexOfFriend);
	}

		this->friends[this->sizeOfFriend] = user;
		this->sizeOfFriend++;

}

BasicUser** BasicUser:: getFrinedsArray()
{
	return this->friends;
}

int BasicUser::getSizeFriends()
{
	return this->sizeOfFriend;
}

void BasicUser:: addStatus(Status status) {
	//this->allStatus.add(status);
}

void BasicUser:: showBasicUser()
{
	cout << this->name << "\n";
}
void BasicUser:: showStatus() const
{
	if (this->allStatus != nullptr)
	{
		int i = 0;
		for (; i < sizeof(this->allStatus); i++)
		{
			this->allStatus[i]->show();
			cout << endl;
		}
	}
	else {

		cout << "No statuss to show\n";
	}
} 

void  BasicUser::showFriends()
{
	if (this->friends != nullptr)
	{
		int i = 0;
		cout << "The friends are:\n";
		for (; i < this->sizeOfFriend; i++)
		{
			cout << i + 1 << ") " << this->friends[i]->getName() << endl;

		}
	}
	else {

		cout << "No friends to show\n";
	}
}

/* //copy c'otr
BasicUser::BasicUser(const BasicUser& other)
{
	name = new char[strlen(other.name)];
	strcpy(name, other.name);
}*/

BasicUser::~BasicUser()
{
	if (this->allStatus != nullptr)
	{
		int i = 0;
		for(;i < sizeof(this->allStatus); i++)
		{
			delete this->allStatus[i];
		}
		delete []this->allStatus; 
		this->allStatus = nullptr;
	}

	if(this->friends != nullptr)
	{
		//friends are members and they are hold in the main so we dont have to realse them
		delete []this->friends; 
		this->friends = nullptr;
		cout << "deleted tis->friend\n";
	}
	
	delete[]this->name;
}

/*void** BasicUser:: expendPointerArray(void** arr)
{
	return nullptr;
}*/

/*void** expendPointerArray(void** arr, int* arrSize)
{
	if (*arr == nullptr)
	{

		*arr = new (void*)[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			arr[i] = nullptr;
		}
		return arr;
	}
	else
	{
		int currentSize = sizeof(*arr) / sizeof(arr[0]);
		int newSize = currentSize * 2;

		void** newArr = new(void**)[newSize];

		//*newArr = new (void*)[newSize];

		for (int i = 0; i < currentSize; i++)
		{
			newArr[i] = arr[i];
			delete[] arr[i];
		}
		for (int i = currentSize; i < newSize; i++)
		{
			newArr[i] = nullptr;
		}
		delete[]arr;
		return newArr;

	}
}*/