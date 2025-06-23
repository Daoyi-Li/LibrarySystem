#include <iostream>
#include <string>
using namespace std;
#ifndef ITEM_H
#define ITEM_H

class Item
{
private:
	string id;//�鼮��Ψһ��ʶ

	string name;//�鼮�ķ������

public:
	Item(const string& name,const string& id);
	virtual ~Item();
	virtual void Display()=0;
	virtual string Get_id() = 0;
	virtual string Get_name()=0;
};


#endif


