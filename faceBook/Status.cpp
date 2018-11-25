#include "Status.h"
#include <iostream>
using namespace std;

Status::Status(char* name, KindOfStatus type)
{
	this->date = Date();
	this->type = type;
	//	type = KindOfStatus::Video;

}

void Status::show() {
	switch (this->type)
	{
	case (KindOfStatus::Picture):
	{
		//cout << "showing the picture\n" << this->date.;
		break;
	}
	case (KindOfStatus::Text):
	{
		cout << "showing the text\n";
		break;
	}
	case (KindOfStatus::Video):
	{
		cout << "showing the video\n";
		break;
	}
		// TODO:: cout for each type(picture, video, text)
		/* Example
		case KindOfStatus::Picture
			cout""
		break;
		*/
	}
}

Status :: ~Status() 
{
}
/*
Video::Video(char* name) : Status(name, KindOfStatus::Video) //ãåâîä ìùìçä ìcotr àá
{
	type = KindOfStatus::Video;

}

Picture::Picture(char* name) : Status(name, KindOfStatus::Picture)
{
	type = KindOfStatus::Picture;

}

Text::Text(char* name) : Status(name, KindOfStatus::Text)
{
	type = KindOfStatus::Text;

}
*/
