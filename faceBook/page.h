
#ifndef __Page_H
#define __Page_H

#include "BasicUser.h"
#include "Member.h"
//#include "date.h"

class Page : public BasicUser
{
private:
	//Member** allMembers; using BasicUser frineds
	//int size;
	//int maxSize;

public:
	//Page(char* name, KindOfBasicUser type);
	Page(char* name);
	//Page(const Page& other);
	//virtual ~Page();
	void showMembers();
	void showPage();
	void showFans();
	//virtual void addFriend(BasicUser* user); //??
};

#endif