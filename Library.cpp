#include <iostream>
#include "Library.h"

using namespace std;

Library::Library() {};

Library::~Library() {};

void Library::Additem_Admin(Item* item)
{
	items.push_back(item);
	cout << "����鼮�ɹ�" << endl;
}

void Library::Deleteitem_Admin(Item* item)
{
	for (int i = 0;i < items.size();++i)
	{
		if (item->Get_name() == items[i]->Get_name() && item->Get_id() == items[i]->Get_id())
		{
			items.erase(items.begin() + i);
			cout << "ɾ���ɹ�" << endl;
			return;
		}
		
	}
	cout << "��Ŀ���鼮����˶��鼮��Ϣ" << endl;
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
	cout << "����û��ɹ�" << endl;
}

void Library::Deleteuser_Admin(User& user)
{
	for (int i = 0;i < users.size();++i)
	{
		if (user.Get_name() == users[i].Get_name() && user.Get_userid() == users[i].Get_userid())
		{
			cout << "ɾ���û��ɹ�" << endl;
			users.erase(users.begin() + i);
			return;
		}

	}
	cout << "���û���Ϣ����˶��û���Ϣ" << endl;
	return;
}

void Library::Displayuser_Admin()
{
	for (int i = 0;i < users.size();++i)
	{
		cout << i<<"."<<"����:"<<users[i].Get_name() << " �û�ID:" << users[i].Get_userid() << endl;
	}
}

void Library::Adduser(User& user)
{
	users.push_back(user);
	cout << "ע��ɹ�" << endl;
}

void Library::Deleteuser(User& user)
{
	for (int i = 0;i < users.size();++i)
	{
		if (user.Get_name() == users[i].Get_name() && user.Get_userid() == users[i].Get_userid())
		{
			cout << "ע���ɹ�" << endl;
			users.erase(users.begin() + i);
			return;
		}

	}
	cout << "���û���Ϣ����˶��û���Ϣ" << endl;
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