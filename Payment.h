#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Payment
{
private:
    string paymentType;
    int payment;

public:
    string getPaymentType()
    {
        return paymentType;
    }

    void setPaymentType(string type)
    {
        paymentType = type;
    }

    int getPay()
    {
        return payment;
    }

    void setPay(int p)
    {
        payment = p;
    }
    void chargepayment()
    {
        cout << "\t\t\t\t|-------------------------------------------------|\n";
        cout << "\t\t\t\t|                                                 |\n";
        cout << "\t\t\t\t|        Select The Payment Method                |\n";
        cout << "\t\t\t\t|        1. EasyPaisa                             |\n";
        cout << "\t\t\t\t|        2. Jazzcash                              |\n";   
        cout << "\t\t\t\t|        3. PayPak                                |\n";
        cout << "\t\t\t\t|        4. UnionPay                              |\n";
        cout << "\t\t\t\t|        5. Bank Transfer                         |\n";
        cout << "\t\t\t\t|                                                 |\n";
        cout << "\t\t\t\t|        Enter your choice:                       |\n";
        cout << "\t\t\t\t|                                                 |\n";
        cout << "\t\t\t\t|-------------------------------------------------|\n";
        int num;
        string temp;
        cin >> num;
        system("CLS");
        switch (num)
        {
        case 1:
            cout << "\t\t\t\tEnter EasyPaisa Number ";
            cin >> temp;
            cout << payment << "\t\t\t\t has been charged"<<endl;
            paymentType = "EasyPaisa";
            break;
        case 2:
            cout << "\t\t\t\tEnter Jazzcash Number ";
            cin >> temp;
            cout << payment << "\t\t\t\t has been charged" << endl;
            paymentType = "Jazzcash";
            break;
        case 3:
            cout << "\t\t\t\tEnter PayPak Number ";
            cin >> temp;
            cout << "\t\t\t\tEnter PIN ";
            paymentType = "PayPak";
            cin >> temp;
            cout << payment << "\t\t\t\t has been charged" << endl;
            break;
        case 4:
            cout << "\t\t\t\tEnter UnionPay Number ";
            cin >> temp;
            cout << "\t\t\t\tEnter PIN ";
            cin >> temp;
            cout << payment << "\t\t\t\t has been charged" << endl;
            paymentType = "UnionPay";
            break;
        case 5:
            cout << "\t\t\t\tEnter Bank Number ";
            cin >> temp;
            cout << payment << "\t\t\t\t has been charged" << endl;
            paymentType = "Bank";
            break;
        default:
            cout << "\t\t\t\tInput Wrong";
            break;
        }
        return;
    }
};
#endif