#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Item.h"
#include "Book.h"
#include "EBook.h"
using namespace std;

User::User(const string& name, const string& userid, const string& password):
	Role(name,userid,password), BorrowRecord() { }

User::~User(){}

void User::Borrow(Item* item)
{
	BorrowRecord.push_back(item);
}

void User::Return(Item* item)
{
	int temp_count = BorrowRecord.size();
	for (int i = 0;i < BorrowRecord.size(); ++i)
	{
		if (item->Get_id() == BorrowRecord[i]->Get_id() && item->Get_name() == BorrowRecord[i]->Get_name())
		{
			BorrowRecord.erase(BorrowRecord.begin() + i);
			cout << "还书成功" << endl;
			break;
		}
	}
	if (temp_count == BorrowRecord.size())
	{
		cout << "没有该借阅记录，请核对借阅信息"<<endl;
	}
}

string User::Get_name() 
{
	return Role::Get_name();
}

string User::Get_userid()
{
	return Role::Get_userid();
}

string User::Get_password()
{
	return Role::Get_password();
}

int User::Get_Count()
{
	return BorrowRecord.size();
}

void User::Display()
{
	for (int i = 0;i < BorrowRecord.size();++i)
	{
		BorrowRecord[i]->Display();
	}
}

bool User::operator==(User& user)
{
	return (Get_name() == user.Get_name() && Get_userid() == user.Get_userid() && Get_password() == user.Get_password());
}

void User::Display_borrowrecord()
{
	for (int i = 0;i < BorrowRecord.size();++i)
	{
		cout << BorrowRecord[i]->Get_name() <<","
			<< BorrowRecord[i]->Get_id() << ","
			<< BorrowRecord[i]->Get_author() <<","
			<< BorrowRecord[i]->Get_flag() << endl;
	}
}

vector<Item*> User::GetBorrowRecords()
{
	return BorrowRecord;
}