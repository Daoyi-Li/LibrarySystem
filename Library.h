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

public:
	Library();
	~Library();

	void Adduser(User& user);
	User& Finduser(User& user);
	void Deleteuser(User& user);

	void Additem_Admin(Item* item);
	Item* Finditem(string& name,string& id);
	void Deleteitem_Admin(Item* item);
	void Display_item();

	void Adduser_Admin(User& user);
	void Deleteuser_Admin(User& user);
	void Displayuser_Admin();

	bool Isuser(User& user);

};

#endif 
