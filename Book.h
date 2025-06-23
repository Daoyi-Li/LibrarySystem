#include <iostream>
#include <string>
#include "Item.h"
using namespace std;
#ifndef BOOK_H
#define BOOK_H

class Book :public Item
{
private:
	string author;
	bool flag;
public:
	Book(const string& name, const string& id, const string& author, bool flag);
	virtual ~Book();
	virtual void Display();
	virtual string Get_name();
	virtual string Get_id();
	virtual string Get_author();
	virtual bool Get_flag();
	virtual void Set_flag(bool flag);
};


#endif 