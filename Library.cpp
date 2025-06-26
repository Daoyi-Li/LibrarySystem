#include <iostream>
#include "Library.h"

using namespace std;

Library::Library() {};

Library::~Library() {};

void Library::Additem_Admin(Item* item)
{
	items.push_back(item);
	cout << "添加书籍成功" << endl;
}

void Library::Deleteitem_Admin(Item* item)
{
	for (int i = 0;i < items.size();++i)
	{
		if (item->Get_name() == items[i]->Get_name() && item->Get_id() == items[i]->Get_id())
		{
			items.erase(items.begin() + i);
			cout << "删除成功" << endl;
			return;
		}
		
	}
	cout << "无目标书籍，请核对书籍信息" << endl;
	return;

}

void Library::Display_item()
{
	for (int i = 0;i < items.size();++i)
	{
		items[i]->Display();
	}
}

void Library::Adduser_Admin(User& user)
{
	users.push_back(user);
	cout << "添加用户成功" << endl;
}

void Library::Deleteuser_Admin(User& user)
{
	for (int i = 0;i < users.size();++i)
	{
		if (user.Get_name() == users[i].Get_name() && user.Get_userid() == users[i].Get_userid())
		{
			cout << "删除用户成功" << endl;
			users.erase(users.begin() + i);
			return;
		}

	}
	cout << "无用户信息，请核对用户信息" << endl;
	return;
}

void Library::Displayuser_Admin()
{
	for (int i = 0;i < users.size();++i)
	{
		cout << i<<"."<<"姓名:"<<users[i].Get_name() << " 用户ID:" << users[i].Get_userid() << endl;
	}
}

void Library::Adduser(User& user)
{
	users.push_back(user);
	cout << "注册成功" << endl;
}

void Library::Deleteuser(User& user)
{
	for (int i = 0;i < users.size();++i)
	{
		if (user.Get_name() == users[i].Get_name() && user.Get_userid() == users[i].Get_userid())
		{
			cout << "注销成功" << endl;
			users.erase(users.begin() + i);
			return;
		}

	}
	cout << "无用户信息，请核对用户信息" << endl;
	return;
}

bool Library::Isuser(User& user)
{
	for (int i = 0;i < users.size();++i)
	{
		if (user.Get_name() == users[i].Get_name() && user.Get_userid() == users[i].Get_userid() && user.Get_password () == users[i].Get_password())
		{
			return 1;
		}
	}
	return 0;
}

User& Library::Finduser(User& user)
{
	for (int i = 0;i < users.size();++i)
	{
		if (user.Get_name() == users[i].Get_name() && user.Get_userid() == users[i].Get_userid())
		{
			
	        return users[i];
		}

	}
}

Item* Library::Finditem(string& name,string& id)
{
	for (int i = 0;i < items.size();++i)
	{
		if (name == items[i]->Get_name() && id == items[i]->Get_id())
		{

			return items[i];
		}

	}
	return nullptr;
}