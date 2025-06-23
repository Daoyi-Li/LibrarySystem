#include <iostream>
#include "Book.h"
#include <string>
using namespace std;

Book::Book(const string & name, const string& id, const string& author,bool flag):
	Item(name,id), author(author), flag(flag){ }

Book::~Book(){}

void Book::Display()
{
	cout << "标题: 《" << Get_name()<<"》" << endl << "ISBN: " << Get_id() << endl << "作者：" << author << endl;
	if (flag == 1)
	{
		cout << "电子书籍状态: 是"<<endl;

	}
	else
	{
		cout << "电子书籍状态: 否" << endl;
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