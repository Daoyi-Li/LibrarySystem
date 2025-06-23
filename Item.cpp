#include <iostream>
#include "Item.h"
#include <string>
using namespace std;

Item::Item(const string& name, const string& id)
    : id(id), name(name) {
}

Item::~Item(){}

void Item::Display()
{
    cout << "±êÌâ: ¡¶" << name<<"¡·" << endl << "ISBN: " << id << endl;
}

string Item::Get_id()
{
    return id;
}
string Item::Get_name()
{
    return name;
}

