#include <iostream>
#include <string>
#include <vector>
#include "Role.h"
#include "User.h"
#include "Library.h"

using namespace std;
#ifndef MANAGER_H
#define MANAGER_H
class Item;

class Manager:public Role
{
private:
	Library& library;
public:
	Manager(const string& name, const string& userid, const string& password, Library& library);
	virtual ~Manager();
	virtual string Get_name();
	virtual string Get_userid();
	virtual string Get_password();
	void Additem(Item* item);
	void Deleteitem(Item* item);
	void Adduser(User& user);
	void Deleteuser(User& user);
	void Displayitem();
	void Displayuser();
};

#endif 

