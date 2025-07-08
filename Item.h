#include <iostream>
#include <string>
using namespace std;
#ifndef ITEM_H
#define ITEM_H

class Item
{
private:
	string id;

	string name;

	string author;

	bool flag;

public:
	Item(const string& name,const string& id,const string& author,bool flag);
	virtual ~Item();
	virtual void Display()=0;
	virtual string Get_id() = 0;
	virtual string Get_name()=0;
	virtual string Get_author() = 0;
	virtual bool Get_flag() = 0;
};


#endif


