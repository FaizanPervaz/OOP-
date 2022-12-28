#ifndef APPOINTMENTS_H
#define APPOINTMENTS_H
#include <iostream>
#include <string>
#include <fstream>
#include<stdlib.h>
#include "Payment.h"
using namespace std;

class Appointment
{
private:
    string did, pid, time, location, type, date;
    string status = "Pending";
    Payment payment;

public:
    Payment getPayment()
    {
        return payment;
    }

    void setPayment(int charges)
    {
        if (type == "Physical")
            payment.setPay(charges);
        if (type == "Online")
            payment.setPay(charges - (charges * 30 / 100));
    }
    string getpid()
    {
        return pid;
    }

    void setpid(string id)
    {
        pid = id;
    }

    string getdid()
    {
        return did;
    }

    void setdid(string id)
    {
        did = id;
    }

    string GetType()
    {
        return type;
    }

    void SetType(string t)
    {
        type = t;
    }
    void setTime(string t)
    {
        time = t;
    }
    string getStatus()
    {
        return status;
    }

    void setStatus(string s)
    {
        status = s;
    }
    void writeAppointment()
    {
        fstream out;
        out.open("appoint", ios::app);
        out << did << " " << pid << " " << location << " " << type << " " << date << " " << time << " " << status << " " << payment.getPay() << " " << payment.getPaymentType() << endl;
        out.close();
    }
    void bookAppointment(string pay)
    {
        string temp;
        int n;
        cout << "\t\t\t\tInput Location ";
        cin >> temp;
        location = temp;
        cout << "\n\t\t\t\tInput Appointment Type (Physical/Online) ";
        cin >> temp;
        type = temp;
        cout << "\t\t\t\tInput Date: ";
        cin >> temp;
        date = temp;
        cout << "\t\t\t\tInput Time ";
        cin >> temp;
        time = temp;
        payment.setPay(stoi(pay));
        payment.chargepayment();
        writeAppointment();
    }
    void storeAppoinment(string d_id, string p_id)
    {
        string temp, doctor, patient, text;
        ifstream in;
        in.open("appoint");
        while (!in.eof())
        {
            in >> doctor;
            in >> patient;
            if (doctor == d_id && patient == p_id)
            {
                did = d_id;
                pid = p_id;
                in >> temp;
                location = temp;
                in >> temp;
                type = temp;
                in >> temp;
                date = temp;
                in >> temp;
                time = temp;
                in >> temp;
                status = temp;
                in >> temp;
                payment.setPay(stoi(temp));
                in >> temp;
                payment.setPaymentType(temp);
                getline(in, text);
                return;
            }
            else
                getline(in, text);
        }
        in.close();
    }
    void display()
    {
        cout << "\t\t\t\tInformation" << endl;
        cout << "\t\t\t\tStatus: " << status << endl;
        cout << "\t\t\t\tLocation: " << location << " Hospital" << endl;
        cout << "\t\t\t\tPatient ID: " << pid << endl;
        cout << "\t\t\t\tDoctor ID: " << did << endl;
        cout << "\t\t\t\tType: " << type << endl;
        cout << "\t\t\t\tPayment: " << payment.getPay() << endl;
        cout << "\t\t\t\tPayment Type: " << payment.getPaymentType() << endl;
        cout << "\t\t\t\tDate: " << date << " of This Month" << endl;
        cout << "\t\t\t\tTime: " << time << " o'clock" << endl;
    }

    bool displayAppointmnet(string id, string type)
    {
        string txt, temp, temp2;
        ifstream in1;
        bool check = false;
        in1.open("appoint");
        while (!in1.eof())
        {
            in1 >> temp;
            in1 >> temp2;
            getline(in1, txt);
            if (type == "doctor")
            {
                cout << temp << endl;
                if (id == temp)
                {
                    check = true;
                    storeAppoinment(temp, temp2);
                    display();
                }
            }
            if (type == "patient")
            {
                if (id == temp2)
                {
                    check = true;
                    storeAppoinment(temp, temp2);
                    display();
                }
            }
        }
        in1.close();
        if (check == false)
        {
            cout << "\t\t\t\tNo Appointment Found.";
            return false;
        }
        else
            return true;
    }
    void deleteAppointment()
    {
        string doctor, txt, temp, temp2, txt2;
        ifstream in, in2;
        ofstream out;
        in2.open("appoint");
        in.open("appoint");
        out.open("appointment.txt");
        while (getline(in, txt))
        {
            in2 >> temp;
            in2 >> temp2;
            if (temp != did && temp2 != pid)
            {
                out << txt << "";
                getline(in2, txt2);
                cout << txt2 << endl;
            }
        }
        in.close();
        in2.close();
        out.close();
        remove("appoint");
        rename("appointment.txt", "appoint");
    }
};
#endif