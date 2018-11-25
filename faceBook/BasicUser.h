#ifndef __BASICUSER_H
#define __BASICUSER_H
#include "Status.h"


#define MAX_NAME 50


enum class KindOfBasicUser
{
	Friend,
	Page
};

class BasicUser
{
private:
	char* name;
	Status** allStatus;
	BasicUser** friends;
	//Status** allStatus;
	int sizeOfStatus;
	int sizeOfFriend;
	int maxIndexOfStatus;
	int maxIndexOfFriend;
public:
	KindOfBasicUser type;
	BasicUser(char* name, KindOfBasicUser type);
	//BasicUser(char* name);
	char* getName();
	//void** expendPointerArray(void** arr);

	//BasicUser(const BasicUser& other);
	virtual ~BasicUser(); 
	virtual void showStatus() const;
	virtual void showBasicUser();
	void showFriends();
	//virtual void addFriend(BasicUser* basicUser);//Virtual because page can't add page
	void addFriend(BasicUser* basicUser);
	void addStatus(Status status);
	BasicUser** getFrinedsArray();
	int getSizeFriends();

};
#endif