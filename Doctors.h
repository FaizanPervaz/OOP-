#ifndef DOCTORS_H
#define DOCTORS_H
#include <iostream>
#include <string>
#include <fstream>
#include<stdlib.h>
#include <ctime>
#include "Appointments.h"
using namespace std;

class Doctor
{
private:
    string id, name, speciality, stime, etime, fee, password, city, hospital;
    int rating = 0;
    int count = 0;
    Appointment *appointment;

public:
    Doctor()
    {
        appointment = new Appointment;
    };
    string getid()
    {
        return id;
    }
    void setfee(string f)
    {
        fee = f;
    }
    Appointment *getappointment()
    {
        return appointment;
    }
    void setid(string i)
    {
        id = i;
    }
    void sethospital(string h)
    {
        hospital = h;
    }
    void setname(string n)
    {
        name = n;
    }
    void setarea(string a)
    {
        city = a;
    }
    string getspeciality()
    {
        return speciality;
    }
    void setspeciality(string s)
    {
        speciality = s;
    }
    string setstime()
    {
        return stime;
    }
    void setstime(string t)
    {
        stime = t;
    }
    string getetime()
    {
        return etime;
    }
    void setetime(string t)
    {
        etime = t;
    }
    string getcharges()
    {
        return fee;
    }
    void setcharges(string n)
    {
        fee = n;
    }
    int getrating()
    {
        return rating;
    }
    void setrating(int r)
    {
        rating = r;
    }
    void deleteDoctor()
    {
        string doctor, txt, temp, txt2;
        ifstream in, in2;
        ofstream out;
        in2.open("doc.txt");
        in.open("doc.txt");
        out.open("doctor.txt");
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
        remove("doc.txt");
        rename("doctor.txt", "doc.txt");
    }
    void updateRating(string id, int r)
    {
        storeDoctor(id);
        int num = rating * count;
        num += r;
        count++;
        rating /= count;
        deleteDoctor();
        writeDoctor();
    }
    void writeDoctor()
    {
        ofstream out;
        out.open("doc.txt", ios::app);
        out << "\n"
            << id << " " << name << " " << password << " " << speciality << " " << city << " " << hospital << " " << stime << " " << etime << " " << fee << " " << rating << " " << count;
        out.close();
    }
    void reg()
    {
        string name, speciality, password, hospital, city, fee, stime, etime;
        int id;
        ;
        srand(time(0));
        id = rand() % 100;
        cout << "\t\tEnter Name ";
        cin >> name;
        cout << "\t\tEnter Password ";
        cin >> password;
        while (password.length() != 8)
        {
            cout << "\t\tPassword must be of 8 digits.Enter Password: ";
            cin >> password;
        }
        cout << "\t\tEnter Speciality ";
        cin >> speciality;
        cout << "\t\tEnter City ";
        cin >> city;
        cout << endl;
        cout << "\t\tEnter Hospital ";
        cin >> hospital;
        cout << "\t\tEnter Avaliable Timings" << endl
             << "\t\tEnter Start Time ";
        cin >> stime;
        cout << "\t\tEnter End Time ";
        cin >> etime;
        cout << "\t\tEnter Fee: ";
        cin >> fee;
        cout << "\t\tYour Registration id is : " << id << endl;
        ofstream out;
        out.open("doc.txt", ios::app);
        out << id << " " << name << " " << password << " " << speciality << " " << city << " " << hospital << " " << stime << " " << etime << " " << fee << " " << rating << " " << count << endl;
        out.close();
        storeDoctor(to_string(id));
    }
    void storeDoctor(string i)
    {
        string str, line;
        fstream in;
        in.open("doc.txt");
        while (!in.eof())
        {
            in >> str;
            if (str == i)
            {
                id = str;
                in >> str;
                name = str;
                in >> str;
                password = str;
                in >> str;
                speciality = str;
                in >> str;
                city = str;
                in >> str;
                hospital = str;
                in >> str;
                stime = str;
                in >> str;
                etime = str;
                in >> str;
                fee = str;
                in >> str;
                rating = stoi(str);
                in >> str;
                count = stoi(str);
            }
            else
                getline(in, line);
        }
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
        in.open("doc.txt");
        while (!in.eof())
        {
            in >> temp;
            in >> str;
            in >> password;
            getline(in, line);
            if (temp == id)
            {
                cout << "\t\tMatched!"<<endl;
                cout << "\t\tPassword " << endl;
                cin >> temp;
                getline(in, line);
                while (temp != password)
                {
                    cout << "\t\tWrong Password! Enter Again: ";
                    cin >> temp;
                }
                cout << "\t\tLogin Successful" << endl;
                storeDoctor(id);
                return;
            }
        }
        cout << "\t\tNo Previous Registering\n\t\tRegister Yourself" << endl;
        in.close();
        reg();
        return;
    }
    void searchDoctor(string str, string condition)
    {
        if (condition == "hospital")
        {
            string temp, id, line;
            ifstream in;
            in.open("doc.txt");
            while (!in.eof())
            {
                in >> id;
                in >> temp;
                in >> temp;
                in >> temp;
                in >> temp;
                in >> temp;
                if (temp == str)
                {
                    storeDoctor(id);
                    display();
                    getline(in, line);
                }
                else
                    getline(in, line);
            }
            in.close();
        }
        if (condition == "city")
        {
            string temp, id, line;
            ifstream in;
            in.open("doc.txt");
            while (!in.eof())
            {
                in >> id;
                in >> temp;
                in >> temp;
                in >> temp;
                in >> temp;
                if (temp == str)
                {
                    storeDoctor(id);
                    display();
                    getline(in, line);
                }
                else
                    getline(in, line);
            }
        }
        if (condition == "speciality")
        {
            string temp, id, line;
            ifstream in;
            in.open("doc.txt");
            while (!in.eof())
            {
                in >> id;
                in >> temp;
                in >> temp;
                in >> temp;
                if (temp == str)
                {
                    storeDoctor(id);
                    display();
                    getline(in, line);
                }
                else
                    getline(in, line);
            }
        }
    }
    void display()
    {
        cout << "\t\tInformation" << endl;
        cout << "\t\tName " << name << endl;
        cout << "\t\tID " << id << endl;
        cout << "\t\tRating " << rating << endl;
        cout << "\t\tCity " << city;
        cout << "\t\tHospital " << hospital << endl;
        cout << "\t\tSpeciality: " << speciality << endl;
        cout << "\t\tCharges " << fee << endl;
        cout << "\t\tAvaliablity " << endl;
        cout << "\t\tStart Time " << stime << endl;
        cout << "\t\tEnd Time " << etime << endl;
    }
};
#endif