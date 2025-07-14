#include <iostream>
#include "Library.h"
#include <algorithm>
using namespace std;

Library::Library() :user_num(0) {}

Library::~Library() 
{
	for (Item* item : items) { 
		delete item;
	}
	items.clear();
}

void Library::Additem_Admin(Item* item)
{
	items.push_back(item);
	cout << "����鼮�ɹ�" << endl;
	SaveBooksToFile();
}

void Library::Deleteitem_Admin(Item* item)
{
	for (int i = 0;i < items.size();++i)
	{
		if (item->Get_name() == items[i]->Get_name() && item->Get_id() == items[i]->Get_id())
		{
			items.erase(items.begin() + i);
			cout << "ɾ���ɹ�" << endl;
			SaveBooksToFile();
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
	user_num++;
	SaveUsersToFile();
	SaveNumToFile();
}

void Library::Deleteuser_Admin(User& user)
{
	for (int i = 0;i < users.size();++i)
	{
		if (user==users[i])
		{
			cout << "ɾ���û��ɹ�" << endl;
			users.erase(users.begin() + i);
			SaveUsersToFile();
			return;
		}

	}
	cout << "���û���Ϣ����˶��û���Ϣ" << endl;
	return;
}

void Library::Displayuser_Admin()
{
	for (int i = 0; i < users.size();++i)
	{
		cout << i+1<<"."<<"����:"<<users[i].Get_name() << " �û�ID:" << users[i].Get_userid() << endl;
	}
}

void Library::Adduser(User& user)
{
	users.push_back(user);
	cout << "ע��ɹ�" << endl;
	user_num++;
	SaveNumToFile();
}

void Library::Deleteuser(User& user)
{
	for (int i = 0;i < users.size();++i)
	{
		if (user==users[i])
		{
			cout << "ע���ɹ�" << endl;
			users.erase(users.begin() + i);
			SaveUsersToFile();
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
		if (user==users[i])
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
		if (user==users[i])
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

	ofstream file1(borrowrecordFilePath);
	
	if (file1.good())
	{
		for (User& user : users)
		{
			for (Item *& item : user.GetBorrowRecords()) {  
				file1 << user.Get_userid() << ","
					<< item->Get_name() << ","
					<< item->Get_id() << ","
					<< item->Get_author() << ","
					<< item->Get_flag() << endl;
			}
			
		}
	}
	file1.close();
}

void Library::LoadUsersFromFile() {
	ifstream file(usersFilePath);
	if (file.is_open())
	{
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
		int maxId = 0;
		for (User& user : users) {
			string idStr = user.Get_userid();
			int idNum = stoi(idStr);
			if (idNum > maxId) maxId = idNum;
		}
		user_num = maxId;
		SaveNumToFile();
	}
}

void Library::LoadBorrowRecords() {
	ifstream recordFile(borrowrecordFilePath);
	if (!recordFile.good()) return;

	string line;
	while (getline(recordFile, line)) {
		size_t comma1 = line.find(',');
		size_t comma2 = line.find(',', comma1 + 1);
		size_t comma3 = line.find(',', comma2 + 1);
		size_t comma4 = line.find(',', comma3 + 1);
		if (comma1 == string::npos || comma2 == string::npos ||
			comma3 == string::npos || comma4 == string::npos) {
			continue;  
		}

		string userid = line.substr(0, comma1);
		string name = line.substr(comma1 + 1, comma2 - comma1 - 1);
		string id = line.substr(comma2 + 1, comma3 - comma2 - 1);
		string author = line.substr(comma3 + 1, comma4 - comma3 - 1);
		bool flag = (line.substr(comma4 + 1) == "1");

		// 1. ���Ҷ�Ӧ���û�
		User* user = nullptr;
		for (auto& u : users) {
			if (u.Get_userid() == userid) {
				user = &u;
				break;
			}
		}
		if (!user) continue;  
		Item* targetItem = nullptr;
		for (Item* item : items) {
			if (item->Get_name() == name && item->Get_id() == id &&
				item->Get_author() == author && item->Get_flag() == flag) {
				targetItem = item;
				break;
			}
		}
		if (!targetItem) continue;  
		user->Borrow(targetItem); 
	}
	recordFile.close();
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

void Library::SaveNumToFile()
{
	ofstream file(maxIdFilePath);
	if (file.good())
	{
		file << user_num;
	}
	file.close();
}

void Library::LoadNumFromFile()
{
	ifstream file(maxIdFilePath);
	if (file.good())
	{
		file >> user_num;
	}
	file.close();
}

int Library::Getitem_num()
{
	return items.size();
}

int Library::Getuser_num()
{
	return user_num;
}
