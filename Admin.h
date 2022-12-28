#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <string>
#include <ctime>
#include<stdlib.h>
#include "Doctors.h"
using namespace std;

class Admin
{
private:
    string name;
    string password;
    string id;

public:
    string getPassword()
    {
        return password;
    }

    void setPassword(string p)
    {
        password = p;
    }

    string getid()
    {
        return id;
    }

    void setid(string i)
    {
        id = i;
    }
    void reg()
    {
        string name, password;
        int id;
        srand(time(0));
        id = rand() % 9999;
        cout << "\t\t\t\tName: "<<endl;
        cin >> name;
        cout << "\t\t\t\tPassword: "<<endl;
        cin >> password;

        while (password.size() != 8)
        {
            cout << "\t\t\t\tMore then 8 digits Allowed ";
            cin >> password;
        }
        cout << "\t\t\t\tId " << id << endl;
        ofstream out;
        out.open("admin.txt", ios::app);
        out << id << " " << name << " " << password << endl;
        out.close();
        storeadmin(to_string(id));
        writeadmin();
    }
    void display()
    {
        cout << "\t\t\t\tID: " << id << endl;
        cout << "\t\t\t\tName: " << name << endl;
        cout << "\t\t\t\tPassword: " << password << endl;
        cout << endl;
    }
    void log()
    {
        string id, temp, line, str, password;
        cout << "Login:" << endl;
        cout << "Enter ID ";
        cin >> id;
        ifstream in;
        in.open("admin.txt");
        while (!in.eof())
        {
            in >> temp;
            in >> str;
            in >> password;
            getline(in, line);
            if (temp == id)
            {
                cout << "\t\t\t\tMatched!";
                cout << "\t\t\t\tPassword ";
                cin >> temp;
                getline(in, line);
                while (temp != password)
                {
                    cout << "\t\t\t\tEnter Again: ";
                    cin >> temp;
                }
                cout << "\t\t\t\tSuccessful" << endl;
                storeadmin(id);
                return;
            }
        }
        cout << "\t\t\t\tNo Existing Registery\n\t\t\t\tRegister Yourself" << endl;
        in.close();
        reg();
        return;
    }
    void storeadmin(string id)
    {
        string temp, text;
        ifstream in;
        in.open("admin.txt");
        while (!in.eof())
        {
            in >> temp;
            if (temp == id)
            {
                id = temp;
                in >> temp;
                name = temp;
                in >> temp;
                password = temp;
            }
            else
                getline(in, text);
        }
        in.close();
    }
    void deleteAdmin()
    {
        string line, temp, line2;
        ifstream in, in2;
        ofstream out;
        in2.open("admin.txt");
        in.open("admin.txt");
        out.open("admins.txt");
        while (getline(in, line))
        {
            in2 >> temp;
            if (temp != id)
            {
                out << line << endl;
                getline(in2, line2);
            }
        }
        in.close();
        in2.close();
        out.close();
        remove("admin.txt");
        rename("admins.txt", "admin.txt");
    }
    void writeadmin()
    {
        ofstream out;
        out.open("admin.txt", ios::app);
        out << endl
            << id << " " << name << " " << password;
        out.close();
    }
};
#endif