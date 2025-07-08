#include <iostream>
#include "Library.h"
#include <algorithm>
using namespace std;

Library::Library() {};

Library::~Library() 
{
	for (Item* item : items) { 
		delete item;
	}
	items.clear();
};

void Library::Additem_Admin(Item* item)
{
	items.push_back(item);
	cout << "添加书籍成功" << endl;
	SaveBooksToFile();
}

void Library::Deleteitem_Admin(Item* item)
{
	for (int i = 0;i < items.size();++i)
	{
		if (item->Get_name() == items[i]->Get_name() && item->Get_id() == items[i]->Get_id())
		{
			items.erase(items.begin() + i);
			cout << "删除成功" << endl;
			SaveBooksToFile();
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
	SaveUsersToFile();
}

void Library::Deleteuser_Admin(User& user)
{
	for (int i = 0;i < users.size();++i)
	{
		if (user.Get_name() == users[i].Get_name() && user.Get_userid() == users[i].Get_userid())
		{
			cout << "删除用户成功" << endl;
			users.erase(users.begin() + i);
			SaveUsersToFile();
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

Item* Library::Finditem(string& name,string& id,string & author)
{
	for (int i = 0;i < items.size();++i)
	{
		if (name == items[i]->Get_name() && id == items[i]->Get_id()&& author==items[i]->Get_author())
		{

			return items[i];
		}

	}
	return nullptr;
}

vector<Item*> Library::Search(string& keywords)
{
	vector<Item*> outcome;
	transform(keywords.begin(), keywords.end(), keywords.begin(), ::tolower);
	for (int i = 0;i < items.size();++i)
	{

		if (items[i])
		{
			string name = items[i]->Get_name();
			string isbn = items[i]->Get_id();
			string author = items[i]->Get_author();
			transform(name.begin(), name.end(), name.begin(), ::tolower);
			transform(isbn.begin(), isbn.end(), isbn.begin(), ::tolower);
			transform(author.begin(), author.end(), author.begin(), ::tolower);
			if (name.find(keywords) != string::npos|| isbn.find(keywords) != string::npos || 
				author.find(keywords) != string::npos  )
			{
				outcome.push_back(items[i]);
			}
		}
	}
	return outcome;
}

void Library::SaveUsersToFile() {
	ofstream file(usersFilePath);
	if (file.good()) {
		for (User& user : users) {
			file << user.Get_name() << ","
				<< user.Get_userid() << ","
				<< user.Get_password() << endl;
		}
		file.close();
	}
}
void Library::LoadUsersFromFile() {
	ifstream file(usersFilePath);
	if (!file.is_open()) return;

	string line;
	while (getline(file, line)) {
		string name, id, password;
		size_t comma1 = line.find(',');
		name = line.substr(0, comma1);
		size_t comma2 = line.find(',', comma1 + 1);
		if (comma2 == string::npos) continue;
		id = line.substr(comma1 + 1, comma2 - comma1 - 1);
		password = line.substr(comma2 + 1);
		users.push_back(User(name, id, password));
	}
	file.close();
}

void Library::SaveBooksToFile() {
	ofstream file(booksFilePath);
	if (file.is_open()) {
		for (Item* item : items) {
			
			if (item) {
				file << item->Get_name() << ","
					<< item->Get_id() << ","
					<< item->Get_author() << ","
					<< item->Get_flag() << "\n";
			}
		}
		file.close();
	}
}

void Library::LoadBooksFromFile() {
	ifstream file(booksFilePath);
	if (!file.good()) return;

	string line;
	while (getline(file, line)) {
		size_t comma1 = line.find(',');
		if (comma1 == string::npos) continue;
		size_t comma2 = line.find(',', comma1 + 1);
		if (comma2 == string::npos) continue;
		string title = line.substr(0, comma1);
		string isbn = line.substr(comma1 + 1, comma2 - comma1 - 1);
		size_t comma3 = line.find(',', comma2 + 1);
		string author = line.substr(comma2 + 1, comma3 - comma2 - 1);
		bool hasEbook = (line.substr(comma3 + 1) == "1");
		items.push_back(new Book (title, isbn, author, hasEbook));
	}
	file.close();
}
