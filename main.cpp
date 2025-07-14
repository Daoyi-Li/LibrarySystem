#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include "Library.h"
#include "Role.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Library.h"
#include "Role.h"
#include "Manager.h"
#include "Item.h"


bool EXIT=0;

using namespace std;

void Set(Library& library, Manager& manager);
void Run();
void Usermenu(Library& library, Manager& manager);
void User_function(Library& library,  User& user, Manager& manager);
void User_function_borrow(Library& library, User& user, Manager& manager);
void User_function_return(Library& library,  User& user, Manager& manager);
void User_function_search(Library& library,  User& user, Manager& manager);
void User_function_record(Library& library,  User& user, Manager& manager);

void Adminmenu(Library& library, Manager& manager);
void Admin_function(Library& library, Manager& manager);
void Admin_function_item(Library& library,  Manager& manager);
void Admin_function_user(Library& library,  Manager& manager);
void Admin_function_book_add(Library& library, Manager& manager);
void Admin_function_book_delete(Library& library, Manager& manager);
void Admin_function_user_add(Library& library, Manager& manager);
void Admin_function_user_delete(Library& library, Manager& manager);
string Toid(string a);
int main()
{
    Run();
}

void Run()
{
    
    Library library;
    library.LoadBooksFromFile();
    library.LoadUsersFromFile();
    library.LoadNumFromFile();
    library.LoadBorrowRecords();
    Manager manager("MANAGER", " 00000", "111111", library);
    while(!EXIT)
    Set(library, manager);
    return;
}

void Set(Library& library, Manager& manager)
{
    system("cls");
    cout << "****************************************" << endl;
    cout << "*           Library System            *" << endl;
    cout << "*  Welcome to Manage Your Library!    *" << endl;
    cout << "               Your ARE:      " << endl;
    cout << "****  1. User  2. Admin     ****" << endl;
    cout << "            click q to quit       " << endl;
    cout << "****************************************" << endl;
    char role;
    cin >> role;
    if (role == 'q'||role=='Q')
    {
        library.SaveBooksToFile();
        library.SaveUsersToFile();
        EXIT = 1;
        return;
    }
    else if (role == '1')
    {
        Usermenu(library,manager);
    }
    else if (role == '2')
    {
        Adminmenu(library, manager);
    }
    else
    {
        cout << "输入有误，将跳转..." << endl;
        Sleep(3000);
        Set(library, manager);
    }
}

void Adminmenu(Library& library, Manager& manager)
{
    system("cls");
    cout << "****************************************" << endl;
    cout << "*           User Menu            *" << endl;
    cout << "****        1. login       ****" << endl;
    cout << "            click q to quit       " << endl;
    cout << "****************************************" << endl;
    cout << "注：管理员不可注册" << endl;
    cout << "内置管理员账号：MANAGER  ID：00000  密码：111111" << endl;
    char choice;
    cin >> choice;
    if (choice == '1')
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
        
        if (name=="MANAGER"&&userid=="00000"&&password=="111111")
        {
            cout << "登陆成功" << endl;
            Admin_function(library, manager);
        }
        else
        {
            cout << "用户名或密码错误，请重试" << endl;
            Adminmenu(library, manager);
        }
    }
    else if (choice == 'q' || choice == 'Q')
    {
        library.SaveBooksToFile();
        library.SaveNumToFile();
        library.SaveUsersToFile();
        return;
    }
    else
    {
        cout << "输入有误，将跳转..." << endl;
        Sleep(3000);
        Set(library, manager);
    }
}

void Admin_function(Library& library, Manager& manager)
{
    system("cls");
    cout << "****************************************" << endl;
    cout << "*           Admin Menu            *" << endl;
    cout << "****  1. 书籍管理  2. 用户管理    ****" << endl;
    cout << "            click q to quit       " << endl;
    cout << "****************************************" << endl;
    char choice;
    cin >> choice;
    if (choice == '1')
    {
        Admin_function_item(library, manager);
    }
    else if (choice == '2')
    {
        Admin_function_user(library, manager);
    }
    else if (choice == 'q'||choice=='Q')

    {
        library.SaveBooksToFile(); 
        library.SaveNumToFile();
        library.SaveUsersToFile();
        EXIT = 1;
        return;
    }
    else
    {
        cout << "输入有误，将跳转..." << endl;
        Sleep(3000);
        Admin_function(library, manager);
    }
    
}

void Admin_function_item(Library& library, Manager& manager)
{
    system("cls");
    cout << "****************************************" << endl;
    cout << "*           Book Managerment Menu            *" << endl;
    cout << "****  1. 添加书籍  2. 删除书籍 3. 查看所有书籍    ****" << endl;
    cout << "            click q to quit       " << endl;
    cout << "****************************************" << endl;
    char choice;
    cin >> choice;
    if (choice == '1')
    {
        Admin_function_book_add(library, manager);
    }
    else if (choice == '2')
    {
        Admin_function_book_delete(library, manager);
    }
    else if (choice == '3')
    {
        manager.Displayitem();
    }
    else if (choice == 'q' || choice == 'Q')
    {
        
        library.SaveBooksToFile();
        library.SaveNumToFile();
        library.SaveUsersToFile();
        EXIT = 1;
        return;
    }
    else
    {
        cout << "输入有误，将跳转..." << endl;
        Sleep(3000);
        Admin_function_item(library, manager);
    }

    if (choice == '1' || choice == '2' || choice == '3')
    {
        cout << "****  1. 返回首页  2. 返回管理员菜单  ****" << endl;
        cout << "            click q to quit       " << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
        {
            Set(library, manager);
        }
        if (choice == '2')
        {
            Admin_function(library, manager);
        }
        else if (choice == 'q' || choice == 'Q')
        {

            library.SaveBooksToFile();
            library.SaveNumToFile();
            library.SaveUsersToFile();
            EXIT = 1;
            return;
        }
        else
        {
            cout << "输入有误，将跳转..." << endl;
            Sleep(3000);
            Admin_function_item(library, manager);
        }
    }
}

void Admin_function_user(Library& library, Manager& manager)
{
    system("cls");
    cout << "****************************************" << endl;
    cout << "*           User Managerment Menu            *" << endl;
    cout << "****  1. 添加用户  2. 删除用户 3. 查看所有用户   ****" << endl;
    cout << "            click q to quit       " << endl;
    cout << "****************************************" << endl;
    char choice;
    cin >> choice;
    if (choice == '1')
    {
        Admin_function_user_add(library, manager);
    }
    else if (choice == '2')
    {
        Admin_function_user_delete(library, manager);
    }
    else if (choice == '3')
    {
        manager.Displayuser();
    }
    else if (choice == 'q' || choice == 'Q')
    {
        library.SaveBooksToFile();
        library.SaveNumToFile();
        library.SaveUsersToFile();
        EXIT = 1;
        return;
    }
    else
    {
        cout << "输入有误，将跳转..." << endl;
        Sleep(3000);
        Admin_function_user(library, manager);
    }

    if (choice == '1' || choice == '2' || choice == '3')
    {
        cout << "****  1. 返回首页  2. 返回管理员菜单  ****" << endl;
        cout << "            click q to quit       " << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
        {
            Set(library, manager);
        }
        if (choice == '2')
        {
            Admin_function(library, manager);
        }
        else if (choice == 'q' || choice == 'Q')
        {
            library.SaveBooksToFile();
            library.SaveNumToFile();
            library.SaveUsersToFile();
            EXIT = 1;
            return;
        }
        else
        {
            cout << "输入有误，将跳转..." << endl;
            Sleep(3000);
            Admin_function_user(library, manager);
        }
    }
}

void Admin_function_user_add(Library& library, Manager& manager)
{
    string name;
    string userid;
    string password="000000";
    cout << "请输入用户姓名:" << endl;
    cin >> name;
    userid = Toid(to_string(library.Getuser_num()+1));
    User temp_user(name, userid, password);
    manager.Adduser(temp_user);
    cout << "添加成功" << endl;
    cout << "用户姓名:" << name << endl << "用户ID:" << userid << endl << "用户密码(默认):" << password << endl;
}

void Admin_function_user_delete(Library& library, Manager& manager)
{
    string name;
    string userid;
    string password = "000000";
    cout << "请输入用户姓名:" << endl;
    cin >> name;
    cout << "请输入用户ID:" << endl;
    cin >> userid;
    cout << "请输入用户密码:" << endl;
    cin >> password;
    User temp_user(name, userid, password);
    manager.Deleteuser(library.Finduser(temp_user));
}

void Admin_function_book_add(Library& library, Manager& manager)
{
    string title;
    string isbn;
    string author;
    bool flag;
    cout << "请输入标题:" << endl;
    cin >> title;
    cout << "请输入ISBN:" << endl;
    cin >> isbn;
    cout << "请输入作者:" << endl;
    cin >> author;
    cout << "是否有电子书(有:1    否:0)" << endl;
    cin >> flag;
    Item* temp_item = new Book(title, isbn, author, flag);
    manager.Additem(temp_item);
    cout << "添加成功！" << endl;
}

void Admin_function_book_delete(Library& library, Manager& manager)
{
    string title;
    string isbn;
    string author;
    bool flag;
    cout << "请输入标题:" << endl;
    cin >> title;
    cout << "请输入ISBN:" << endl;
    cin >> isbn;
    cout << "请输入作者:" << endl;
    cin >> author;
    cout << "是否有电子书(有:1    否:0)" << endl;
    cin >> flag;
    Item* temp_item = new Book(title, isbn, author, flag);
    manager.Deleteitem(temp_item);
    cout << "删除成功！" << endl;
}

void Usermenu(Library& library, Manager& manager)
{
    system("cls");
    cout << "****************************************" << endl;
    cout << "*           User Menu            *" << endl;
    cout << "****  1. Register  2. login 3. Cancel Account   ****" << endl;
    cout << "            click q to quit       " << endl;
    cout << "****************************************" << endl;
    char choice;
    cin >> choice;
    if (choice == '1')
    {
        string name;
        string userid;
        string password;
        cout << "请输入您的姓名:" << endl;
        cin >> name;
        cout << "请输入您的密码: " << endl;
        cin >> password;
        userid = Toid(to_string(library.Getuser_num() + 1));
        User temp_user(name, userid, password);
        library.Adduser(temp_user);
        cout << "您的用户ID是:" << userid << endl;
        cout << "****  1. 返回首页  2. 返回用户菜单  ****" << endl;
        cout << "              click q to quit                     " << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
        {
            Set(library, manager);
        }
        else if (choice == '2')
        {
            Usermenu(library, manager);
        }
        else if (choice == 'q' || choice == 'Q')
        {
            library.SaveBooksToFile();
            library.SaveNumToFile();
            library.SaveUsersToFile();
            EXIT = 1;
            return;
        }
        else
        {
            cout << "输入有误，将跳转..." << endl;
            Sleep(3000);
            Usermenu(library, manager);
        }


    }
    else if (choice == '2')
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
                Sleep(2000);
                User_function(library, library.Finduser(temp_user), manager);
            }
            else
            {
                cout << "用户名或密码错误，请重试" << endl;
                Sleep(3000);
                Usermenu(library, manager);
            }
        
    }
    else if (choice == '3')
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
        library.Deleteuser(library.Finduser(temp_user));
        cout << "****  1. 返回首页  2. 返回用户菜单  ****" << endl;
        cout << "            click q to quit       " << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
            Set(library, manager);
        else if (choice == '2')
           Usermenu(library, manager);
        else if (choice == 'q' || choice == 'Q')
        {
            library.SaveBooksToFile();
            library.SaveNumToFile();
            library.SaveUsersToFile();
            EXIT = 1;
            return;
        }
        else
        {
                cout << "输入有误，将跳转..." << endl;
                Sleep(3000);
                Usermenu(library, manager);
        }
    }
    else if (choice == 'q' || choice == 'Q')
    {
        library.SaveBooksToFile();
        library.SaveNumToFile();
        library.SaveUsersToFile();
        EXIT = 1;
        return;
    }
    else
    {
        cout << "输入有误，将跳转..." << endl;
        Sleep(3000);
        Usermenu(library, manager);
    }

}

void User_function(Library& library, User& user,Manager& manager)
{
    system("cls");
    cout << "****************************************" << endl;
    cout << "*           User Menu            *" << endl;
    cout << "****  1. 借书  2. 还书 3. 搜索 4.借阅记录  ****" << endl;
    cout << "            click q to quit       " << endl;
    cout << "****************************************" << endl;
    char choice;
    cin >> choice;
    if (choice == '1')
    {
        User_function_borrow(library, user,manager);
    }
    else if (choice == '2')
    {
        User_function_return(library, user,manager);
    }
    else if (choice == '3')
    {
        User_function_search(library, user,manager);
    }
    else if (choice == '4')
    {
        User_function_record(library, user,manager);
    }
    else if (choice == 'q' || choice == 'Q')
    {
        library.SaveBooksToFile();
        library.SaveNumToFile();
        library.SaveUsersToFile();
        EXIT = 1;
        return;
    }
    else
    {
        cout << "输入有误，将跳转..." << endl;
        Sleep(3000);
        User_function(library, user, manager);
    }
}

void User_function_borrow(Library& library, User& user,Manager& manager)
{
    User& temp_user = library.Finduser(user);
    string title;
    string isbn;
    string author;
    cout << "请输入标题:" << endl;
    cin >> title;
    cout << "请输入ISBN:" << endl; 
    cin >> isbn;
    cout << "请输入作者:" << endl;
    cin >> author;
    Item* temp_item;
    temp_item = library.Finditem(title, isbn,author);
    if (temp_item)
    {
        temp_user.Borrow(temp_item);
        cout << "借书成功: " << "《" << temp_item->Get_id() << "》" << endl;
        cout << "****  1. 返回首页  2. 返回用户菜单 3.返回用户使用界面  ****" << endl;
        cout << "                 click q to quit                               " << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
            Set(library, manager);
        else if (choice == '2')
            Usermenu(library, manager);
        else if (choice == '3')
            User_function(library, user,manager);
        else if (choice == 'q' || choice == 'Q')
        {
            library.SaveBooksToFile();
            library.SaveNumToFile();
            library.SaveUsersToFile();
            EXIT = 1;
            return;
        }
        else
        {
            cout << "输入有误，将跳转..." << endl;
            Sleep(3000);
            User_function(library, user, manager);
        }
    }
    else
    {
        cout << "无目标书籍，请核对馆藏信息" << endl;
        cout << "****  1. 返回首页  2. 返回用户菜单 3.返回用户使用界面  ****" << endl;
        cout << "                 click q to quit                               " << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
            Set(library, manager);
        else if (choice == '2')
            Usermenu(library, manager);
        else if (choice == '3')
            User_function(library, user,manager);
        else if (choice == 'q' || choice == 'Q')
        {
            library.SaveBooksToFile();
            library.SaveNumToFile();
            library.SaveUsersToFile();
            EXIT = 1;
            return;
        }
        else
        {
            cout << "输入有误，将跳转..." << endl;
            Sleep(3000);
            User_function(library, user, manager);
        }

    }
}

void User_function_return(Library& library, User& user,Manager& manager)
{
    User& temp_user = library.Finduser(user);
    string title;
    string isbn;
    string author;
    cout << "请输入标题:" << endl;
    cin >> title;
    cout << "请输入ISBN:" << endl;
    cin >> isbn;
    cout << "请输入作者:" << endl;
    cin >> author;
    Item* temp_item;
    temp_item = library.Finditem(title, isbn,author);
    if (temp_item)
    {
        temp_user.Return(temp_item);
        cout << "还书成功: " << "《" << temp_item->Get_id() << "》" << endl;
        cout << "****  1. 返回首页  2. 返回用户菜单 3.返回用户使用界面  ****" << endl;
        cout << "                click q to quit                               " << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
            Set(library, manager);
        else if (choice == '2')
            Usermenu(library, manager);
        else if (choice == '3')
            User_function(library, user, manager);
        else if (choice == 'q' || choice == 'Q')
        {
            library.SaveBooksToFile();
            library.SaveNumToFile();
            library.SaveUsersToFile();
            EXIT = 1;
            return;
        }
        else
        {
            cout << "输入有误，将跳转..." << endl;
            Sleep(3000);
            User_function(library, user, manager);
        }
    }
    else
    {
        cout << "无目标书籍，请核对馆藏信息" << endl;
        cout << "****  1. 返回首页  2. 返回用户菜单 3.返回用户使用界面 ****" << endl;
        cout << "                  click q to quit                               " << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
            Set(library, manager);
        else if (choice == '2')
            Usermenu(library, manager);
        else if (choice == '3')
            User_function(library, user, manager);
        else if (choice == 'q' || choice == 'Q')
        {
            library.SaveBooksToFile();
            library.SaveNumToFile();
            library.SaveUsersToFile();
            EXIT = 1;
            return;
        }
        else
        {
            cout << "输入有误，将跳转..." << endl;
            Sleep(3000);
            User_function(library, user, manager);
        }
    }
}

void User_function_search(Library& library, User& user,Manager& manager)
{
    string keywords;
    system("cls");
    cout << "****************************************" << endl;
    cout << "*           搜索菜单            *" << endl;
    cout << "          请输入图书相关信息(标题、ISBN、作者)     " << endl;
    getline(cin, keywords);
    vector<Item*> results = library.Search(keywords);
    if (results.empty())
    {
        cout << "未找到相关图书" << endl;
        cout << "****  1. 返回首页  2. 返回用户菜单 3.返回用户使用界面 ****" << endl;
        cout << "                click q to quit                               " << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
            Set(library, manager);
        else if (choice == '2')
            Usermenu(library, manager);
        else if (choice == '3')
            User_function(library, user, manager);
        else if (choice == 'q' || choice == 'Q')
        {
            library.SaveBooksToFile();
            library.SaveNumToFile();
            library.SaveUsersToFile();
            EXIT = 1;
            return;
        }
        else
        {
            cout << "输入有误，将跳转..." << endl;
            Sleep(3000);
            User_function(library, user, manager);
        }
    }
    else
    {
        cout << "搜索结果（共" << results.size() << "本）：" << endl;
        for (int i = 0; i < results.size(); ++i)
        {
            cout << "[" << i + 1 << "] ";
            results[i]->Display();
        }
        cout << "****  1. 返回首页  2. 返回用户菜单 3.返回用户使用界面  ****" << endl;
        cout << "                 click q to quit                               " << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
            Set(library, manager);
        else if (choice == '2')
            Usermenu(library, manager);
        else if (choice == '3')
            User_function(library, user, manager);
        else if (choice == 'q' || choice == 'Q')
        {
            library.SaveBooksToFile();
            library.SaveNumToFile();
            library.SaveUsersToFile();
            EXIT = 1;
            return;
        }
        else
        {
            cout << "输入有误，将跳转..." << endl;
            Sleep(3000);
            User_function(library, user, manager);
        }
    }
}

void User_function_record(Library& library, User& user,Manager& manager)
{

    user.Display();
    cout << endl << endl;
    cout << "****  1. 返回首页  2. 返回用户菜单 3.返回用户使用界面  ****" << endl;
    cout << "                 click q to quit                               " << endl;
    char choice;
    cin >> choice;
    if (choice == '1')
        Set(library, manager);
    else if (choice == '2')
        Usermenu(library, manager);
    else if (choice == '3')
        User_function(library, user, manager);
    else if (choice == 'q' || choice == 'Q')
    {
        library.SaveBooksToFile();
        library.SaveBooksToFile();
        library.SaveUsersToFile();
        EXIT = 1;
        return;
    }
    else
    {
        cout << "输入有误，将跳转..." << endl;
        Sleep(3000);
        User_function(library, user, manager);
    }

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