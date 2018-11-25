
#ifndef __MEMBER_H
#define __MEMBER_H

#include "BasicUser.h"
#include "page.h"
#include "HandelMemoryAllocation.h"


class Member : public BasicUser
{
private:
	Date bDay;
	BasicUser** pages; //רשימת דפים אהודים על ידו
	int sizePages; 
	int maxSize;

public:
	Member(char* name, Date bDay); //הקונסטרקטור יבדוק בעצמו מה התאריך ויעדכן אותו
	//Member(const Member& other);
	~Member();
	void showPages();
	void showMembers();
	void addPage(BasicUser* page);
};

#endif