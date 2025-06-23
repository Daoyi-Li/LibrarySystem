#include <iostream>
#include <string>
using namespace std;
#ifndef ITEM_H
#define ITEM_H

class Item
{
private:
	string id;//书籍的唯一标识

	string name;//书籍的封面标题

public:
	Item(const string& name,const string& id);
	virtual ~Item();
	virtual void Display()=0;
	virtual string Get_id() = 0;
	virtual string Get_name()=0;
};


#endif


