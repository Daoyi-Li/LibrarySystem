#include <iostream>
#include "Book.h"
#include <string>
using namespace std;

Book::Book(const string & name, const string& id, const string& author,bool flag):
	Item(name,id), author(author), flag(flag){ }

Book::~Book(){}

void Book::Display()
{
	cout << "����: ��" << Get_name()<<"��" << endl << "ISBN: " << Get_id() << endl << "���ߣ�" << author << endl;
	if (flag == 1)
	{
		cout << "�����鼮״̬: ��"<<endl;

	}
	else
	{
		cout << "�����鼮״̬: ��" << endl;
	}
}

string Book::Get_name()
{
	return Item::Get_name();
}
string Book::Get_id()
{
	return Item::Get_id();
}

string Book::Get_author()
{
	return author;
}

bool Book::Get_flag()
{
	return flag;
}

void Book::Set_flag(bool flag1)
{
	flag = flag1;
}