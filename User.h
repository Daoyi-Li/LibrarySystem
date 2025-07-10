#include <iostream>
#include <string>
#include <vector>
#include "Role.h"
using namespace std;

#ifndef USER_H
#define USER_H

class Item;

class User:public Role
{
private:
	vector <Item*> BorrowRecord;
public:
	User(const string& name, const string& userid, const string& password);
	virtual ~User();
	void Borrow(Item* item);
	void Return(Item* item);
	void Display();
	virtual string Get_name();
	virtual string Get_userid();
	virtual string Get_password();
	int Get_Count();
	bool operator == (User & user);
	
};

#endif 

