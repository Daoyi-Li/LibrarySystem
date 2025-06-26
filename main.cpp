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
            cout << "��������������:" << endl;
            cin >> name;
            cout << "��������������: " << endl;
            cin >> password;
            userid = Toid(to_string(user_num));
            User temp_user(name, userid, password);
            library.Adduser(temp_user);
            cout << "�����û�ID��:" << userid << endl;
            cout << "****  1. ������ҳ  2. �����û��˵� " << endl;
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
            cout << "��������������:" << endl;
            cin >> name;
            cout << "�����������û�ID" << endl;
            cin >> userid;
            cout << "��������������: " << endl;
            cin >> password;
            User temp_user(name, userid, password);
            if (library.Isuser(temp_user))
            {
                cout << "��½�ɹ�" << endl;
                User_function(library, user_num,temp_user);
            }
            else
            {
                cout << "�û������������������" << endl;
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
    cout << "****  1. ����  2. ���� 3. ���� 4.���ļ�¼****" << endl;
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
        cout << "����������δʵ��" << endl;
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
    cout << "���������:" << endl;
    cin >> title;
    cout << "������ISBN:" << endl;
    cin >> isbn;
    Item* temp_item;
    temp_item = library.Finditem(title, isbn);
    if (temp_item)
    {
        temp_user.Borrow(temp_item);
        cout << "����ɹ�: " << "��" << temp_item->Get_id() << "��" << endl;
        cout << "****  1. ������ҳ  2. �����û��˵� 3.�����û�ʹ�ý��� 4.�������� 5.����" << endl;
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
        cout << "��Ŀ���鼮����˶Թݲ���Ϣ" << endl;
        cout << "****  1. ������ҳ  2. �����û��˵� 3.�����û�ʹ�ý��� 4.�������� 5.����" << endl;
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
    cout << "���������:" << endl;
    cin >> title;
    cout << "������ISBN:" << endl;
    cin >> isbn;
    Item* temp_item;
    temp_item = library.Finditem(title, isbn);
    if (temp_item)
    {
        temp_user.Return(temp_item);
        cout << "����ɹ�: " << "��" << temp_item->Get_id() << "��" << endl;
        cout << "****  1. ������ҳ  2. �����û��˵� 3.�����û�ʹ�ý��� 4.�������� 5.����" << endl;
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
        cout << "��Ŀ���鼮����˶Թݲ���Ϣ" << endl;
        cout << "****  1. ������ҳ  2. �����û��˵� 3.�����û�ʹ�ý��� 4.�������� 5.����" << endl;
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
    cout << "****  1. ������ҳ  2. �����û��˵� 3.�����û�ʹ�ý��� 4.���� 5.����" << endl;
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