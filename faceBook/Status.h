#ifndef __STATUS_H
#define __STATUS_H
#include "date.h"

enum class KindOfStatus 
{
	Video,
	Picture,
	Text
};

class Status
{
private:
	Date date;
public:
	KindOfStatus type;
	virtual void show();
	Status(char* name, KindOfStatus statusType);
	//Status(const Status& other);
	~Status();
};



#endif