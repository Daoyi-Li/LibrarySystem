#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

void Set(Library& library, int& user_num, Manager& manager);
void Run();
void Usermenu(Library& library, int& user_num, Manager& manager);
void User_function(Library& library, int& user_num, User& user, Manager& manager);
void User_function_borrow(Library& library, int& user_num, User& user, Manager& manager);
void User_function_return(Library& library, int& user_num, User& user, Manager& manager);
void User_function_search(Library& library, int& user_num, User& user, Manager& manager);
void User_function_record(Library& library, int& user_num, User& user, Manager& manager);
void Adminmenu(Library& library, int& user_num, Manager& manager);

void Adminmenu(Library& library, int& user_num, Manager& manager);
void Admin_function(Library& library, int& user_num, Manager& manager);
void Admin_function_item(Library& library, int& user_num, Manager& manager);
void Admin_function_user(Library& library, int& user_num, Manager& manager);
void Admin_function_book_add(Library& library, int& user_num, Manager& manager);
void Admin_function_book_delete(Library& library, int& user_num, Manager& manager);
void Admin_function_user_add(Library& library, int& user_num, Manager& manager);
void Admin_function_user_delete(Library& library, int& user_num, Manager& manager);
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
    Manager manager("MANAGER", " 00000", "111111", library);
    int user_num = 0;
    while(!EXIT)
    Set(library, user_num, manager);
    return;
}

void Set(Library& library, int& user_num, Manager& manager)
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
    if (role == 'q'||role=='Q')
    {
        library.SaveBooksToFile();
        library.SaveUsersToFile();
        EXIT = 1;
        return;
    }
    else if (role == '1')
    {
        Usermenu(library, user_num, manager);
    }
    else if (role == '2')
    {
        Adminmenu(library, user_num, manager);
    }
    else
    {
        Set(library, user_num, manager);
    }
}

void Adminmenu(Library& library, int& user_num, Manager& manager)
{
    system("cls");
    cout << "****************************************" << endl;
    cout << "*           User Menu            *" << endl;
    cout << "****        1. login ****" << endl;
    cout << "            click q to quit       " << endl;
    cout << "****************************************" << endl;
    cout << "ע������Ա����ע��" << endl;
    cout << "���ù���Ա�˺ţ�MANAGER  ID��00000  ���룺111111" << endl;
    char choice;
    cin >> choice;
    if (choice == '1')
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
        
        if (name=="MANAGER"&&userid=="00000"&&password=="111111")
        {
            cout << "��½�ɹ�" << endl;
            Admin_function(library, user_num, manager);
        }
        else
        {
            cout << "�û������������������" << endl;
            Adminmenu(library, user_num, manager);
        }
    }
}

void Admin_function(Library& library, int& user_num, Manager& manager)
{
    system("cls");
    cout << "****************************************" << endl;
    cout << "*           Admin Menu            *" << endl;
    cout << "****  1. �鼮����  2. �û�����    ****" << endl;
    cout << "            click q to quit       " << endl;
    cout << "****************************************" << endl;
    char choice;
    cin >> choice;
    if (choice == '1')
    {
        Admin_function_item(library, user_num, manager);
    }
    else if (choice == '2')
    {
        Admin_function_user(library, user_num, manager);
    }
    else if (choice == 'q'||choice=='Q')

    {
        library.SaveBooksToFile(); 
        library.SaveUsersToFile();
        EXIT = 1;
        return;
    }
    else
    {
        Admin_function(library, user_num, manager);
    }
    
}

void Admin_function_item(Library& library, int& user_num, Manager& manager)
{
    system("cls");
    cout << "****************************************" << endl;
    cout << "*           Book Managerment Menu            *" << endl;
    cout << "****  1. ����鼮  2. ɾ���鼮 3. �鿴�����鼮****" << endl;
    cout << "            click q to quit       " << endl;
    cout << "****************************************" << endl;
    char choice;
    cin >> choice;
    if (choice == '1')
    {
        Admin_function_book_add(library, user_num, manager);
    }
    else if (choice == '2')
    {
        Admin_function_book_delete(library, user_num, manager);
    }
    else if (choice == '3')
    {
        manager.Displayitem();
    }
    else if (choice == 'q' || choice == 'Q')
    {
        
        library.SaveBooksToFile();
        library.SaveUsersToFile();
        EXIT = 1;
        return;
    }
    else
    {
        Admin_function_item(library, user_num, manager);
    }

    if (choice == '1' || choice == '2' || choice == '3')
    {
        cout << "****  1. ������ҳ  2. ���ع���Ա�˵� " << endl;
        cout << "            click q to quit       " << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
        {
            Set(library, user_num, manager);
        }
        if (choice == '2')
        {
            Admin_function(library, user_num, manager);
        }
        else if (choice == 'q' || choice == 'Q')
        {

            library.SaveBooksToFile();
            library.SaveUsersToFile();
            EXIT = 1;
            return;
        }
        else
        {
            Admin_function_item(library, user_num, manager);
        }
    }
}

void Admin_function_user(Library& library, int& user_num, Manager& manager)
{
    system("cls");
    cout << "****************************************" << endl;
    cout << "*           User Managerment Menu            *" << endl;
    cout << "****  1. ����û�  2. ɾ���û� 3. �鿴�����û�****" << endl;
    cout << "            click q to quit       " << endl;
    cout << "****************************************" << endl;
    char choice;
    cin >> choice;
    if (choice == '1')
    {
        Admin_function_user_add(library, user_num, manager);
    }
    else if (choice == '2')
    {
        Admin_function_user_delete(library, user_num, manager);
    }
    else if (choice == '3')
    {
        manager.Displayuser();
    }
    else if (choice == 'q' || choice == 'Q')
    {
        library.SaveBooksToFile();
        library.SaveUsersToFile();
        EXIT = 1;
        return;
    }
    else
    {
        Admin_function_user(library, user_num, manager);
    }

    if (choice == '1' || choice == '2' || choice == '3')
    {
        cout << "****  1. ������ҳ  2. ���ع���Ա�˵� " << endl;
        cout << "            click q to quit       " << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
        {
            Set(library, user_num, manager);
        }
        if (choice == '2')
        {
            Admin_function(library, user_num, manager);
        }
        else if (choice == 'q' || choice == 'Q')
        {
            library.SaveBooksToFile();
            library.SaveUsersToFile();
            EXIT = 1;
            return;
        }
        else
        {
            Admin_function_user(library, user_num, manager);
        }
    }
}

void Admin_function_user_add(Library& library, int& user_num, Manager& manager)
{
    string name;
    string userid;
    string password="000000";
    user_num++;
    cout << "�������û�����:" << endl;
    cin >> name;
    userid = Toid(to_string(user_num));
    User temp_user(name, userid, password);
    manager.Adduser(temp_user);
    cout << "��ӳɹ�" << endl;
    cout << "�û�����:" << name << endl << "�û�ID:" << userid << endl << "�û�����(Ĭ��):" << password << endl;
}

void Admin_function_user_delete(Library& library, int& user_num, Manager& manager)
{
    string name;
    string userid;
    string password = "000000";
    user_num++;
    cout << "�������û�����:" << endl;
    cin >> name;
    cout << "�������û�ID:" << endl;
    cin >> userid;
    cout << "�������û�����:" << endl;
    cin >> password;
    User temp_user(name, userid, password);
    if (library.Isuser(temp_user))
    {
        manager.Deleteuser(library.Finduser(temp_user));
    }
    else
    {
        cout << "�޸��û���Ϣ����˶��û���Ϣ" << endl;
    }
}

void Admin_function_book_add(Library& library, int& user_num, Manager& manager)
{
    string title;
    string isbn;
    string author;
    bool flag;
    cout << "���������:" << endl;
    cin >> title;
    cout << "������ISBN:" << endl;
    cin >> isbn;
    cout << "����������:" << endl;
    cin >> author;
    cout << "�Ƿ��е�����(��:1    ��:0)" << endl;
    cin >> flag;
    Item* temp_item = new Book(title, isbn, author, flag);
    manager.Additem(temp_item);
    cout << "��ӳɹ���" << endl;
}

void Admin_function_book_delete(Library& library, int& user_num, Manager& manager)
{
    string title;
    string isbn;
    string author;
    bool flag;
    cout << "���������:" << endl;
    cin >> title;
    cout << "������ISBN:" << endl;
    cin >> isbn;
    cout << "����������:" << endl;
    cin >> author;
    cout << "�Ƿ��е�����(��:1    ��:0)" << endl;
    cin >> flag;
    Item* temp_item = new Book(title, isbn, author, flag);
    manager.Deleteitem(temp_item);
    cout << "ɾ���ɹ���" << endl;
}

void Usermenu(Library& library, int& user_num,Manager& manager)
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
        cout << "              click q to quit                     " << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
        {
            Set(library, user_num,manager);
        }
        else if (choice == '2')
        {
            Usermenu(library, user_num,manager);
        }
        else if (choice == 'q' || choice == 'Q')
        {
            library.SaveBooksToFile();
            library.SaveUsersToFile();
            EXIT = 1;
            return;
        }
        else
        {
            Usermenu(library, user_num, manager);
        }


    }
    else if (choice == '2')
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
                User_function(library, user_num, library.Finduser(temp_user), manager);
            }
            else
            {
                cout << "�û������������������" << endl;
                Usermenu(library, user_num, manager);
            }
        
    }
    else if (choice == '3')
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
            library.Deleteuser(library.Finduser(temp_user));
            cout << "****  1. ������ҳ  2. �����û��˵� " << endl;
            cout << "            click q to quit       " << endl;
            char choice;
            cin >> choice;
            if (choice == '1')
                Set(library, user_num, manager);
            else if (choice == '2')
                Usermenu(library, user_num, manager);
            else if (choice == 'q' || choice == 'Q')
            {
                library.SaveBooksToFile();
                library.SaveUsersToFile();
                EXIT = 1;
                return;
            }
            else
            {
                Usermenu(library, user_num, manager);
            }
        }
        else
        {
            cout << "δ�ҵ��û�����˶��û���Ϣ" << endl;
            Usermenu(library, user_num, manager);
        }
    }
    else if (choice == 'q' || choice == 'Q')
    {
        library.SaveBooksToFile();
        library.SaveUsersToFile();
        EXIT = 1;
        return;
    }
    else
    {
        Usermenu(library, user_num, manager);
    }

}

void User_function(Library& library, int& user_num, User& user,Manager& manager)
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
        User_function_borrow(library, user_num, user,manager);
    }
    else if (choice == '2')
    {
        User_function_return(library, user_num, user,manager);
    }
    else if (choice == '3')
    {
        User_function_search(library, user_num, user,manager);
    }
    else if (choice == '4')
    {
        User_function_record(library, user_num, user,manager);
    }
    else if (choice == 'q' || choice == 'Q')
    {
        library.SaveBooksToFile();
        library.SaveUsersToFile();
        EXIT = 1;
        return;
    }
    else
    {
        User_function(library, user_num, user, manager);
    }
}



void User_function_borrow(Library& library, int& user_num, User& user,Manager& manager)
{
    User& temp_user = library.Finduser(user);
    string title;
    string isbn;
    string author;
    cout << "���������:" << endl;
    cin >> title;
    cout << "������ISBN:" << endl; 
    cin >> isbn;
    cout << "����������:" << endl;
    cin >> author;
    Item* temp_item;
    temp_item = library.Finditem(title, isbn,author);
    if (temp_item)
    {
        temp_user.Borrow(temp_item);
        cout << "����ɹ�: " << "��" << temp_item->Get_id() << "��" << endl;
        cout << "****  1. ������ҳ  2. �����û��˵� 3.�����û�ʹ�ý��� " << endl;
        cout << "              click q to quit                               " << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
            Set(library, user_num,manager);
        else if (choice == '2')
            Usermenu(library, user_num,manager);
        else if (choice == '3')
            User_function(library, user_num, user,manager);
        else if (choice == 'q' || choice == 'Q')
        {
            library.SaveBooksToFile();
            library.SaveUsersToFile();
            EXIT = 1;
            return;
        }
        else
        {
            User_function(library, user_num, user, manager);
        }
    }
    else
    {
        cout << "��Ŀ���鼮����˶Թݲ���Ϣ" << endl;
        cout << "****  1. ������ҳ  2. �����û��˵� 3.�����û�ʹ�ý���" << endl;
        cout << "              click q to quit                               " << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
            Set(library, user_num,manager);
        else if (choice == '2')
            Usermenu(library, user_num,manager);
        else if (choice == '3')
            User_function(library, user_num, user,manager);
        else if (choice == 'q' || choice == 'Q')
        {
            library.SaveBooksToFile();
            library.SaveUsersToFile();
            EXIT = 1;
            return;
        }
        else
        {
            User_function(library, user_num, user, manager);
        }

    }
}

void User_function_return(Library& library, int& user_num, User& user,Manager& manager)
{
    User& temp_user = library.Finduser(user);
    string title;
    string isbn;
    string author;
    cout << "���������:" << endl;
    cin >> title;
    cout << "������ISBN:" << endl;
    cin >> isbn;
    cout << "����������:" << endl;
    cin >> author;
    Item* temp_item;
    temp_item = library.Finditem(title, isbn,author);
    if (temp_item)
    {
        temp_user.Return(temp_item);
        cout << "����ɹ�: " << "��" << temp_item->Get_id() << "��" << endl;
        cout << "****  1. ������ҳ  2. �����û��˵� 3.�����û�ʹ�ý��� " << endl;
        cout << "              click q to quit                               " << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
            Set(library, user_num, manager);
        else if (choice == '2')
            Usermenu(library, user_num, manager);
        else if (choice == '3')
            User_function(library, user_num, user, manager);
        else if (choice == 'q' || choice == 'Q')
        {
            library.SaveBooksToFile();
            library.SaveUsersToFile();
            EXIT = 1;
            return;
        }
        else
        {
            User_function(library, user_num, user, manager);
        }



    }
    else
    {
        cout << "��Ŀ���鼮����˶Թݲ���Ϣ" << endl;
        cout << "****  1. ������ҳ  2. �����û��˵� 3.�����û�ʹ�ý��� " << endl;
        cout << "              click q to quit                               " << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
            Set(library, user_num, manager);
        else if (choice == '2')
            Usermenu(library, user_num, manager);
        else if (choice == '3')
            User_function(library, user_num, user, manager);
        else if (choice == 'q' || choice == 'Q')
        {
            library.SaveBooksToFile();
            library.SaveUsersToFile();
            EXIT = 1;
            return;
        }
        else
        {
            User_function(library, user_num, user, manager);
        }
    }
}

void User_function_search(Library& library, int& user_num, User& user,Manager& manager)
{
    string keywords;
    system("cls");
    cout << "****************************************" << endl;
    cout << "*           �����˵�            *" << endl;
    cout << "          ������ͼ�������Ϣ(���⡢ISBN������)     " << endl;
    getline(cin, keywords);
    vector<Item*> results = library.Search(keywords);
    if (results.empty())
    {
        cout << "δ�ҵ����ͼ��" << endl;
        cout << "****  1. ������ҳ  2. �����û��˵� 3.�����û�ʹ�ý��� " << endl;
        cout << "              click q to quit                               " << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
            Set(library, user_num, manager);
        else if (choice == '2')
            Usermenu(library, user_num, manager);
        else if (choice == '3')
            User_function(library, user_num, user, manager);
        else if (choice == 'q' || choice == 'Q')
        {
            library.SaveBooksToFile();
            library.SaveUsersToFile();
            EXIT = 1;
            return;
        }
        else
        {
            User_function(library, user_num, user, manager);
        }
    }
    else
    {
        cout << "�����������" << results.size() << "������" << endl;
        for (int i = 0; i < results.size(); ++i)
        {
            cout << "[" << i + 1 << "] ";
            results[i]->Display();
            cout << "--------------------------------" << endl;
        }
        cout << "****  1. ������ҳ  2. �����û��˵� 3.�����û�ʹ�ý��� " << endl;
        cout << "              click q to quit                               " << endl;
        char choice;
        cin >> choice;
        if (choice == '1')
            Set(library, user_num, manager);
        else if (choice == '2')
            Usermenu(library, user_num, manager);
        else if (choice == '3')
            User_function(library, user_num, user, manager);
        else if (choice == 'q' || choice == 'Q')
        {
            library.SaveBooksToFile();
            library.SaveUsersToFile();
            EXIT = 1;
            return;
        }
        else
        {
            User_function(library, user_num, user, manager);
        }
    }
}

void User_function_record(Library& library, int& user_num, User& user,Manager& manager)
{

    user.Display();
    cout << endl << endl;
    cout << "****  1. ������ҳ  2. �����û��˵� 3.�����û�ʹ�ý��� " << endl;
    cout << "              click q to quit                               " << endl;
    char choice;
    cin >> choice;
    if (choice == '1')
        Set(library, user_num, manager);
    else if (choice == '2')
        Usermenu(library, user_num, manager);
    else if (choice == '3')
        User_function(library, user_num, user, manager);
    else if (choice == 'q' || choice == 'Q')
    {
        library.SaveBooksToFile();
        library.SaveUsersToFile();
        EXIT = 1;
        return;
    }
    else
    {
        User_function(library, user_num, user, manager);
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
