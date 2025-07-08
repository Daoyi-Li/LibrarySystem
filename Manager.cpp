#include <vector>
#include "Manager.h"
#include "Item.h"
#include "Book.h"
#include "EBook.h"
#include "Library.h"
using namespace std;

Manager::Manager(const string& name,const string& userid,const string& password, Library&library):
	Role(name, userid, password),library(library) {  }

Manager::~Manager(){}

string Manager::Get_name()
{
	return Role::Get_name();
}

string Manager::Get_password()
{
	return Role::Get_password();
}

string Manager::Get_userid()
{
	return Role::Get_userid();
}

void Manager::Additem(Item* item)
{
	library.Additem_Admin(item);
}

void Manager::Deleteitem(Item* item)
{
	library.Deleteitem_Admin(item);
}

void Manager::Adduser(User& user)
{
	library.Adduser_Admin(user);
}

void Manager::Deleteuser(User& user)
{
	library.Deleteuser_Admin(user);
}

void Manager::Displayitem()
{
	library.Display_item();
}

void Manager::Displayuser()
{
	library.Displayuser_Admin();
}