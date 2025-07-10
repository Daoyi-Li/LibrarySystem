#include <iostream>
#include "Item.h"
#include <string>
using namespace std;

Item::Item(const string& name, const string& id,const string& author,bool flag)
    : id(id), name(name),author(author),flag(flag) {
}

Item::~Item(){}

void Item::Display()
{
    cout << "����: ��" << name<<"��" << endl << "ISBN: " << id << endl<<"����:"<<author<<endl;
    if (flag == 1)
    {
        cout << "�Ƿ��е�����: ��" << endl;
    }
    if (flag == 0)
    {
        cout << "�Ƿ��е�����: ��" << endl;
    }
    cout << "############################"<< endl;
}

string Item::Get_id()
{
    return id;
}
string Item::Get_name()
{
    return name;
}

string Item::Get_author()
{
    return author;
}

bool Item::Get_flag()
{
    return flag;
}

