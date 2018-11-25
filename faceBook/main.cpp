#include <iostream>
#include "BasicUser.h"
#include "date.h"
#include "Member.h"
#include "page.h"
#include "Status.h"
#include "HandelMemoryAllocation.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

void createNewMember(Member** &members, int& membersSize, int& allocMembSize);
void createNewPage(Page** &pages, int& pagesSize, int& allocPageSize);
bool isUserExist(char name[], BasicUser** currentArray, int arrayrsSize);
void makeFriendship(Member** members, int membersSize);
void* getUser(char name[], BasicUser** currentArray, int arrayrsSize);
void addMemberToPage(Member** members, int membersSize, Page** pages, int pagesSize);


//void** expendPointerArray(void** &arr, int& arrSize);



int main()
{
	//arrays of all pages and all members on faceBook

	Member** members = nullptr;
	int membersSize = 0;
	int allocMembSize = 0;
	Page** pages= nullptr;
	int pagesSize = 0;
	int allocPageSize = 0;

	int command;

	cout << "press a number between 1-9 for ..." << endl;
	cin >> command;
	while (command != 9)
	{
		switch (command)
		{
		case 1:
		{
			createNewMember(members, membersSize, allocMembSize);
			break;
		}
		case 2://����� ��� ���� ����
		{
			createNewPage(pages, pagesSize, allocPageSize);
			break;
		}
		case 5://����� ����� ��� ��� �����
		{
			//������� ������ �� ��� ������ ������ ����� ����
			//�����- �� �� ��� ����� �����, �� ��, ����� ���� ������
			 makeFriendship(members, membersSize);//���� �� �� ����� �� ������
			 break;

		}

		case 6://����� ���� ���
		{	   //������� ������ �� ���� ����� ����� ��, ���� �� ��� ���� ����� ����� �� ������
			addMemberToPage(members, membersSize, pages, pagesSize);//���� �� ��� �������
			break;
		}
		/*case 3://����� ����� �������
		{
		int smallCommand, memberORpage;
		char* name;//��� ������ ���� �� ��� ������� ������ ������- ����� ���

		cout << "press 1 for a member, 2 for a page\n";
		cin >> memberORpage;
		cout << "Please enter the name you look for\n";
		//���� ����� �� ��� �������, ��� �� ��� ��� �� ���� ���� ����� ������ �������� �������
		if (memberORpage == 1)
		searchFriend(name);//Member* searchFriend(char* name);���������
		cout << "what would you like to uploud?\nPress 1 for picture, 2 for video, 3 for text\n";
		cin >> smallCommand;
		switch (smallCommand)
		{
		case 1:
		{
		StatusPicture();
		}//���� �� ������ ������ �����, ������ ���� �������� ��� �� ���� ������� ����� ������
		case 2:
		{
		StatusVideo();
		}
		case 3:
		{
		//�� �� ���
		//�� ���� �� �� ����� ������� �����
		StatusText();//�� ���� �� ���� ����� ���� ��������, �� ����� ������ ������� �� ������
		}
		}


		AddStatus();//�������� ��� ���� �� ���� �� ������ �� ��� ���� ������- ����� ����� �� ���� ������ ����� ������� ������
		}
		case 4://���� �� �������� �� ��� �� ��
		{
		// ������ ��� ������ ��� �� ����? ��� ���, ��� ������� ������ �������� �������
		//������ �� �� �������� �� ����� �� ��� �����
		showAllStatus();//���� �� ��� �������?
		}
	
		case 7://���� �� ������� ������� ������
		{
		showAll();//����� �� ����� �������� �� �������
		//������� ������� �� �� ������ ������� ������
		//������� ������� �� �� ������� ������
		}
		case 8://���� �� ������ �� ��� ����� �� ������� �� �� �����
		{
		//����� ���� ����� ������� ������ �� ������ ��� ��� ���� ���� �� ��� ������� ��� ��� ��� ��� �� ������ �� ��� ����, ��� �� ������ ��� ��� �� ���� ����� ��� ������ �������
		//[������� ������ ��� ��� ����� ��� �� ����, ��� ����� ���� ������� �� �� ������ �� ������ ���
		cout << "friend or page?\n";
		//cin>>
		//��� ������ ������ ���� ���������� �����:
		//showAllFriends �� showAllFans]
		}*/
		case 9:
		{
			cout << "Goodbye\n";
			break;
			//����� �� �� ������� ��������� ������ ������ �� �� �������
		}
		/*case 10:
		{
			//���� 10 ����� �������
		}
		case 11://���� ����� ���� ����

		{
			createNewPage(pages, pagesSize, allocPageSize);
			break;
		}
		case 12://����� �� ����
		{
			createNewPage(pages, pagesSize, allocPageSize);
			break;
		}
		*/
		default:
		{
			cout << "wrong number..\n";
		}
		}
		cout << "press a number between 1-9 for ..." << endl;
		cin >> command;
	}
	

	return 0;
}


/*
-----------------------------------------------------------------------
private function
-----------------------------------------------------------------------
*/

/*
	this function get pointer to array of Members it size and the real size of the allocation.
	it's expand the array or allocat it with the expendArray function.
	checks if the name allready excist in the array.
	add the freind.

*/

void createNewMember(Member** &members, int& membersSize, int& allocMembSize)
{
	if (membersSize == 0 || allocMembSize == membersSize)
	{
		// we will send only the alo4ocMembSize !!
		//members = (Member**)expendPointerArray((void**&)members, allocMembSize); // ������� ������� ������
		members = (Member**)HandelMemAlloc::expendPointerArray((void**&)members, allocMembSize); // ������� ������� ������

	}
	//char* name = new char[SIZE];
	int day, month, year;
	char name[MAX_NAME + 1];
	cin.getline(name, MAX_NAME); // get the enter charecter ??

	cout << "Please enter the new frined name:" << endl;
	cin.getline(name, MAX_NAME) ; 
	if (!isUserExist(name, (BasicUser**)members, membersSize))
	{
		cout << "\nEnter date of birth in this format:\nEnte day: " << endl;
		cin >> day;
			while (day < 1 || day > 31)
			{
				cout << "wrong day, please enter a day between 1-31:  " << endl;
				cin >> day;
			}

		cout << "Ente month: " << endl;
		cin >> month;
		while (month < 1 || month > 12)
		{
			cout << "wrong month, please enter a month between 1-12:  " << endl;
			cin >> month;
		}
		cout << "Ente year: " << endl;
		cin >> year;
		while (year < 1900 || year > 2018)
		{
			cout << "wrong year, please enter a day between 1900-2018:  " << endl;
			cin >> year;
		}
		members[membersSize] = new Member(name, Date(day, month, year));
		membersSize++;

	}
	else
	{
		cout << "we allready have this name on faceBook...\n";
	}

}

void createNewPage(Page** &pages, int& pagesSize, int& allocPageSize)
{

	if (pagesSize == 0 || allocPageSize == pagesSize)
	{
		pages = (Page**)HandelMemAlloc::expendPointerArray((void**&)pages, allocPageSize);
	}

	char name[MAX_NAME + 1];
	cin.getline(name, MAX_NAME); // get the enter charecter ??

	cout << "Please enter the new page name:" << endl;
	cin.getline(name, MAX_NAME);
	if (!isUserExist(name, (BasicUser**)pages, pagesSize))
	{
		pages[pagesSize] = new Page(name);
		pagesSize++;
	}
	else
	{
		cout << "we allready have this page on faceBook...\n";
		return;
	}

}

void makeFriendship(Member** members , int membersSize)
{
	if (membersSize < 2)
	{
		cout << "We have only: " << membersSize << " friends on faceBook.\n";
	}
	else 
	{
		Member* member1;
		Member* member2;
		//int m1InArr, m2IArr;

		char friendName[MAX_NAME + 1];
		cin.getline(friendName, MAX_NAME); // get the enter charecter ??
		cout << "Please enter the 1st frined name: " << endl;
		cin.getline(friendName, MAX_NAME);
		member1 = (Member*)getUser(friendName, (BasicUser**)members, membersSize);
		while (member1 == nullptr)
		{
			cout << "He is not on faceBook, please enter 1st frined name:" << endl;
			cin.getline(friendName, MAX_NAME);
			member1 = (Member*)getUser(friendName, (BasicUser**)members, membersSize);
		}

		cout << "Please enter 2nd frined name: " << endl;
		cin.getline(friendName, MAX_NAME);
		member2 = (Member*)getUser(friendName, (BasicUser**)members, membersSize);
		
		while (member2 == nullptr || strcmp(member2->getName(),member1->getName()) == 0)
		{
			cout << "He is not on faceBook or it's the same name of the 1st frined, please enter 2nd frined name: " << endl;
			cin.getline(friendName, MAX_NAME);
			member2 = (Member*)getUser(friendName, (BasicUser**)members, membersSize);
		}

		bool isAllreadyFrined = isUserExist(member1->getName(), member2->getFrinedsArray(), member2->getSizeFriends());
		if (isAllreadyFrined)
		{
			cout << "sorry thay are allready frineds...\n";
		}
		else
		{
			member1->addFriend((BasicUser*)member2);
			member2->addFriend((BasicUser*)member1);
		}
	
	}

}

bool isUserExist(char name[], BasicUser** currentArray, int arrayrsSize)
{
	if (arrayrsSize != 0)
	{
		for (int i = 0; i < arrayrsSize; i++)
		{
			if (strcmp(currentArray[i]->getName(), name) == 0)
			{
			return true;
			}
			
		}
	}
	return false;
}

void addMemberToPage(Member** members, int membersSize, Page** pages, int pagesSize)
{

	if (membersSize < 1)
	{
		cout << "we have no friends on faceBook..\n";

	}
	else if (pagesSize < 1)
	{
		cout << "we have no pages on faceBook..\n";
	}
	else
	{
		Member* member;
		Page* page;

		char friendName[MAX_NAME + 1];
		cin.getline(friendName, MAX_NAME); // get the enter charecter ??
		cout << "Please enter the friend name: " << endl;
		cin.getline(friendName, MAX_NAME);
		member = (Member*)getUser(friendName, (BasicUser**)members, membersSize);
		while (member == nullptr)
		{
			cout << "He is not on faceBook, please enter friend name:" << endl;
			cin.getline(friendName, MAX_NAME);
			member = (Member*)getUser(friendName, (BasicUser**)members, membersSize);
		}

		cout << "Please enter page name: " << endl;
		cin.getline(friendName, MAX_NAME);
		page = (Page*)getUser(friendName, (BasicUser**)pages, pagesSize);

		while (page == nullptr )
		{
			cout << "it is not on faceBook , please enter page name: " << endl;
			cin.getline(friendName, MAX_NAME);
			page = (Page*)getUser(friendName, (BasicUser**)members, membersSize);
		}

		bool isAllreadyFrined = isUserExist(member->getName(), page->getFrinedsArray(), page->getSizeFriends());
		if (isAllreadyFrined)
		{
			cout << "Sorry, he is allready fans of this page...\n";
		}
		else
		{
			member->addPage(page);
			page->addFriend((BasicUser*)member);
		}

	}


}

void* getUser(char name[], BasicUser** currentArray, int arrayrsSize)
{
	if (arrayrsSize != 0)
	{
		for (int i = 0; i < arrayrsSize; i++)
		{
			if (strcmp(currentArray[i]->getName(), name) == 0)
			{
				return currentArray[i];
			}

		}
	}
	return nullptr;
}

 
//---------------------------------------------------------------------------

