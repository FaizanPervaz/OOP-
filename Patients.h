#ifndef PATIENTS_H
#define PATIENTS_H
#include <stdlib.h>
#include "Doctors.h"
#include "Feedback.h"
using namespace std;

class Patient : public Doctor
{
private:
    Feedback feedback;
    int balance;
    string id, name, password;

public:
    Patient()
    {
        balance = 3500;
    }

    Feedback getfeedback()
    {
        return feedback;
    }
    string getid()
    {
        return id;
    }
    void setid(string i)
    {
        id = id;
    }
    int getbalance()
    {
        return balance;
    }
    string getname()
    {
        return name;
    }
    string getpassword()
    {
        return password;
    }
    void setpassword(string i)
    {
        password = i;
    }
    void setbalance(int b)
    {
        balance = b;
    }
    void updateBalance()
    {
        int pay = Doctor::getappointment()->getPayment().getPay();
        balance = balance - pay;
    }
    void log()
    {
        string id, temp, line, str, password;
        cout << "\t\t\t\t|-------------------------------------------------|\n";
        cout << "\t\t\t\t|                                                 |\n";
        cout << "\t\t\t\t|                 Login                           |\n";
        cout << "\t\t\t\t|               Enter ID                          |\n";
        cout << "\t\t\t\t|                                                 |\n";
        cout << "\t\t\t\t|-------------------------------------------------|\n";
        cin >> id;
        system("CLS");
        ifstream in;
        in.open("patient.txt");
        while (!in.eof())
        {
            in >> temp;
            in >> str;
            in >> password;
            getline(in, line);
            if (temp == id)
            {
                cout << "\t\t\t\tUser Found!";
                cout << "\t\t\t\tEnter Password ";
                cin >> temp;
                getline(in, line);
                while (temp != password)
                {
                    cout << "\t\t\t\tWrong Password! Enter Again: ";
                    cin >> temp;
                }
                cout << "\t\t\t\tSuccessfully Logined" << endl;
                storePatient(id);
                return;
            }
        }
        cout << "\t\t\t\tNO Existing User\n\t\t\t\tRegister Yourself" << endl;
        in.close();
        reg();
        return;
    }
    void storePatient(string i)
    {
        string temp, text;
        ifstream in;
        in.open("patient.txt");
        while (!in.eof())
        {
            in >> temp;
            if (temp == i)
            {
                id = temp;
                in >> temp;
                name = temp;
                in >> temp;
                password = temp;
                in >> temp;
                balance = stoi(temp);
            }
            else
                getline(in, text);
        }
    }
    void writepatient(string id)
    {
        string temp, text;
        ifstream in;
        in.open("patient.txt");
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
                in >> temp;
                balance = stoi(temp);
            }
            else
                getline(in, text);
        }
    }
    void reg()
    {
        string name, password;
        int id;
        srand(time(0));
        id = rand() % 100;
        cout << "\t\t\t\tName: ";
        cin >> name;
        cout << "\t\t\t\tPassword: ";
        cin >> password;
        while (password.length() != 8)
        {
            cout << "\t\t\t\tPassword must be of 8 digits.Enter Password ";
            cin >> password;
        }
        cout << "\t\t\t\tYour Registration id " << id << endl;
        ofstream out;
        out.open("patient.txt", ios::app);
        out << id << " " << name << " " << password << " " << balance << endl;
        out.close();
        storePatient(to_string(id));
        writepatient();
    }
    void display()
    {
        cout << "\t\t\t\tPatient Details" << endl;
        cout << "\t\t\t\tID: " << id << endl;
        cout << "\t\t\t\tName: " << name << endl;
        cout << "\t\t\t\tPassword: " << password << endl;
        cout << "\t\t\t\tBalance: " << balance << endl;
    }
    void deletePatient()
    {
        string doctor, txt, temp, txt2;
        ifstream in, in2;
        ofstream out;
        in2.open("patient.txt");
        in.open("patient.txt");
        out.open("pat.txt");
        while (getline(in, txt))
        {
            in2 >> temp;
            if (temp != id)
            {
                out << txt << "\n";
                getline(in2, txt2);
            }
        }
        in.close();
        in2.close();
        out.close();
        remove("patient.txt");
        rename("pat.txt", "patient.txt");
    }
    void writepatient()
    {
        ofstream out;
        out.open("patient.txt", ios::app);
        out << endl
            << id << " " << name << " " << password << " " << balance;
        out.close();
    }
};
#endif