#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include "Item.h"
#include "Role.h"
#include "User.h"
#include "Book.h"
#include "EBook.h"

using namespace std;

#ifndef LIBRARY_H
#define LIBRARY_H

class Library
{
private:
	vector<Item*> items;
	vector<User> users;
	string usersFilePath = "users.txt";
	string booksFilePath = "books.txt";
	string maxIdFilePath = "max_user_id.txt";
	int user_num;
	
public:
	Library();
	~Library();

	void Adduser(User& user);
	User& Finduser(User& user);
	void Deleteuser(User& user);

	void Additem_Admin(Item* item);
	Item* Finditem(string& name,string& id,string& author);
	void Deleteitem_Admin(Item* item);
	void Display_item();
	void Adduser_Admin(User& user);
	void Deleteuser_Admin(User& user);
	void Displayuser_Admin();

	bool Isuser(User& user);

	vector<Item*> Search(string& keywords);


	void SaveUsersToFile();  
	void LoadUsersFromFile();
	
	void SaveBooksToFile(); 
	void LoadBooksFromFile();
	void SaveNumToFile();
	void LoadNumFromFile();

	int Getitem_num();
	int Getuser_num();
};

#endif 
