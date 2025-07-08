#include <iostream>
#include <string>
#include "Book.h"
using namespace std;
#ifndef EBOOK_H
#define EBOOK_H

class EBook : public Book {
private:
    string format;   
    string downloadUrl; 
    string accessCode;  
public:
    EBook(const string& name, const string& id, const string& author,
        const string& format, const string& downloadUrl, const string& accessCode, bool flag = 1);
    virtual ~EBook();
    virtual void Display();
    virtual string Get_name();
    virtual string Get_id();
    virtual string Get_author();
    string Get_format();
    string Get_downloadUrl();
    string Get_accessCode();

};



#endif