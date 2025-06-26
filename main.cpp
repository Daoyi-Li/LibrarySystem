#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Library.h"
#include "Role.h"
#include "Item.h"

using namespace std;

void Set(Library& library,int user_num);
void Run();
void Usermenu(Library& library, int& user_num);
void User_function(Library& library, int& user_num, User& user);
void User_function_borrow(Library& library, int& user_num, User& user);
void User_function_return(Library& library, int& user_num, User& user);
void User_function_search(Library& library, int& user_num, User& user);
string Toid(string a);
int main()
{
    Run();
}

void Run()
{
    Library library;
    int user_num = 0;
    while (1)
	{
        Set(library,user_num);
	}
    return;
}

void Set(Library& library,int user_num)
{
    
    system("cls");
    cout << "****************************************" << endl;
    cout << "*           Library System            *" << endl;
    cout << "*  Welcome to Manage Your Library!    *" << endl;
    cout << "               Your ARE:      " << endl;
    cout << "****  1. User  2. Admin ****" << endl; 
    cout << "            click q to quit       " << endl;
    cout << "****************************************" << endl;
    char role;
    cin >> role;
    if (role == 'q')
        return;
    else if (role == '1')
    {
        Usermenu(library, user_num);
    }
}

void Usermenu(Library &library,int& user_num)
{
    system("cls");
    cout << "****************************************" << endl;
    cout << "*           User Menu            *" << endl;
    cout << "****  1. Register  2. login 3. Cancel Account****" << endl;
    cout << "            click q to quit       " << endl;
    cout << "****************************************" << endl;
    char choice;
    cin >> choice;
    if (choice == '1')
    {
        while (1)
        {
            user_num++;
            string name;
            string userid;
            string password;
            cout << "请输入您的姓名:" << endl;
            cin >> name;
            cout << "请输入您的密码: " << endl;
            cin >> password;
            userid = Toid(to_string(user_num));
            User temp_user(name, userid, password);
            library.Adduser(temp_user);
            cout << "您的用户ID是:" << userid << endl;
            cout << "****  1. 返回首页  2. 返回用户菜单 " << endl;
            char choice;
            cin >> choice;
            if (choice == '1')
            {
                Set(library, user_num);
            }
            if (choice == '2')
            {
                Usermenu(library, user_num);
            }
        }

    }
    if (choice == '2')
    {
        while (1)
        {
            string name;
            string userid;
            string password;
            cout << "请输入您的姓名:" << endl;
            cin >> name;
            cout << "请输入您的用户ID" << endl;
            cin >> userid;
            cout << "请输入您的密码: " << endl;
            cin >> password;
            User temp_user(name, userid, password);
            if (library.Isuser(temp_user))
            {
                cout << "登陆成功" << endl;
                User_function(library, user_num,temp_user);
            }
            else
            {
                cout << "用户名或密码错误，请重试" << endl;
                continue;
            }
        }
    }
        
        
}

void User_function(Library& library, int& user_num,User& user)
{
    system("cls");
    cout << "****************************************" << endl;
    cout << "*           User Menu            *" << endl;
    cout << "****  1. 借书  2. 还书 3. 搜索 4.借阅记录****" << endl;
    cout << "            click q to quit       " << endl;
    cout << "****************************************" << endl;
    char choice;
    cin >> choice;
    if (choice == '1')
    {
        User_function_borrow(library, user_num, user);
    }
    else if (choice == '2')
    {
        User_function_return(library, user_num, user);
    }
    else if (choice == '3')
    {
        cout << "搜索功能暂未实现" << endl;
    }
    else if (choice == '4')
    {
        User_function_search(library, user_num, user);
    }
}



void User_function_borrow(Library& library, int& user_num, User& user)
{
    User& temp_user = library.Finduser(user);
    string title;
    string isbn;
    cout << "请输入标题:" << endl;
    cin >> title;
    cout << "请输入ISBN:" << endl;
    cin >> isbn;
    Item* temp_item;
    temp_item = library.Finditem(title, isbn);
    if (temp_item)
    {
        temp_user.Borrow(temp_item);
        cout << "借书成功: " << "《" << temp_item->Get_id() << "》" << endl;
        cout << "****  1. 返回首页  2. 返回用户菜单 3.返回用户使用界面 4.继续借书 5.还书" << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
            Set(library, user_num);
        else if (choice == '2')
            Usermenu(library, user_num);
        else if (choice == '3')
            User_function(library, user_num, user);
        else if (choice == '4')
            User_function_borrow(library, user_num, user);
        else if (choice == '5')
            User_function_return(library, user_num, user);
    }
    else
    {
        cout << "无目标书籍，请核对馆藏信息" << endl;
        cout << "****  1. 返回首页  2. 返回用户菜单 3.返回用户使用界面 4.继续借书 5.还书" << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
            Set(library, user_num);
        else if (choice == '2')
            Usermenu(library, user_num);
        else if (choice == '3')
            User_function(library, user_num, user);
        else if (choice == '4')
            User_function_borrow(library, user_num, user);
        else if (choice == '5')
            User_function_return(library, user_num, user);
    
    }
}

void User_function_return(Library& library, int& user_num, User& user)
{
    User& temp_user = library.Finduser(user);
    string title;
    string isbn;
    cout << "请输入标题:" << endl;
    cin >> title;
    cout << "请输入ISBN:" << endl;
    cin >> isbn;
    Item* temp_item;
    temp_item = library.Finditem(title, isbn);
    if (temp_item)
    {
        temp_user.Return(temp_item);
        cout << "还书成功: " << "《" << temp_item->Get_id() << "》" << endl;
        cout << "****  1. 返回首页  2. 返回用户菜单 3.返回用户使用界面 4.继续借书 5.还书" << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
            Set(library, user_num);
        else if (choice == '2')
            Usermenu(library, user_num);
        else if (choice == '3')
            User_function(library, user_num, user);
        else if (choice == '4')
            User_function_borrow(library, user_num, user);
        else if (choice == '5')
            User_function_return(library, user_num, user);
    

    }
    else
    {
        cout << "无目标书籍，请核对馆藏信息" << endl;
        cout << "****  1. 返回首页  2. 返回用户菜单 3.返回用户使用界面 4.继续借书 5.还书" << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
            Set(library, user_num);
        else if (choice == '2')
            Usermenu(library, user_num);
        else if (choice == '3')
            User_function(library, user_num, user);
        else if (choice == '4')
            User_function_borrow(library, user_num, user);
        else if (choice == '5')
            User_function_return(library, user_num, user);
    }
}

void User_function_search(Library& library, int& user_num, User& user)
{
    user.Display();
    cout << endl << endl;
    cout << "****  1. 返回首页  2. 返回用户菜单 3.返回用户使用界面 4.借书 5.还书" << endl;
    char choice;
    cin >> choice;
    if (choice == '1')
        Set(library, user_num);
    else if (choice == '2')
        Usermenu(library, user_num);
    else if (choice == '3')
        User_function(library, user_num, user);
    else if (choice == '4')
        User_function_borrow(library, user_num, user);
    else if (choice == '5')
        User_function_return(library, user_num, user);
}




















































































string Toid(string a)
{
    if (a.size() < 8)
    {
        for (int i = 0;i < 8 - a.size();++i)
        {
            a = '0' + a;
        }
    }
    return a;
}