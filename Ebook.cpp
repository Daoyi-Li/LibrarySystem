#include <iostream>
#include "EBook.h"
#include <string>
using namespace std;

EBook::EBook(const string& name, const string& id, const string& author,
	bool flag, const string& format, const string& downloadUrl, const string& accessCode) :
	Book(name ,id, author,flag), format(format),downloadUrl(downloadUrl),accessCode(accessCode) {
}

EBook::~EBook(){}

void EBook::Display()
{
	cout << "标题: 《" << Get_name() << "》" << endl << "ISBN: " << Get_id() << endl << "作者：" << Get_author() << endl
		<<"储存格式: "<<format<<endl<<"下载地址: "<<downloadUrl<<endl<<"获取密钥: "<<accessCode<<endl;
}

string EBook::Get_name()
{
	return Book::Get_name();
}

string EBook::Get_id()
{
	return Book::Get_id();
}

string EBook::Get_author()
{
	return Book::Get_author();
}

string EBook::Get_format()
{
	return format;
}

string EBook::Get_downloadUrl()
{
	return downloadUrl;
}

string EBook::Get_accessCode()
{
	return accessCode;
}