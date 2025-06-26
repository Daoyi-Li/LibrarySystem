#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef ROLE_H
#define ROLE_H

class Role
{
private:
	string name;
	string userid;
	string password;
public:
	Role(const string& name, const string& userid, const string& password);
	virtual ~Role();
	virtual string Get_name();
	virtual string Get_userid();
	virtual string Get_password();
};


#endif 
