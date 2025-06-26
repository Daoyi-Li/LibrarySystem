#include <iostream>
#include <string>
#include <vector>
#include "Role.h"
using namespace std;

Role::Role(const string& name, const string& userid, const string& password):name(name),userid(userid),
password(password){}

Role::~Role(){}

string Role::Get_name()
{
	return name;
}

string Role::Get_password()
{
	return password;
}

string Role::Get_userid()
{
	return userid;
}