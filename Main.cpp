//20I-0565
//CS-G
//Faizan Pervaz
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <ctime>

#include "Doctors.h"
#include "Appointments.h"
#include "Payment.h"
#include "Patients.h"
#include "Feedback.h"
#include "Admin.h"

using namespace std;

int main()
{
    int choice = 1;

    Payment pay;
    Appointment app;
    Admin a;
    Doctor d;
    Feedback f;
    Patient p;

    while (choice)
    {
    FrontPage:
        cout << "\t\t\t\t|-------------------------------------------------|\n";
        cout << "\t\t\t\t|                                                 |\n";
        cout << "\t\t\t\t|                                                 |\n";
        cout << "\t\t\t\t|              WELCOME  To                        |\n";
        cout << "\t\t\t\t|            OLADOC HOSPITAL                      |\n";
        cout << "\t\t\t\t|              1. Admin                           |\n";
        cout << "\t\t\t\t|              2. Patient                         |\n";
        cout << "\t\t\t\t|              3. Doctor                          |\n";
        cout << "\t\t\t\t|            Press Anykey to                      |\n";
        cout << "\t\t\t\t|                 Exit                            |\n";
        cout << "\t\t\t\t|                                                 |\n";
        cout << "\t\t\t\t|          ->Enter your choice:                   |\n";
        cout << "\t\t\t\t|                                                 |\n";
        cout << "\t\t\t\t|                                                 |\n";
        cout << "\t\t\t\t|-------------------------------------------------|\n";
        cin >> choice;
        system("CLS");

        if (choice == 1)
        {
        Menu_Admin:
            cout << "\t\t\t\t|-------------------------------------------------|\n";
            cout << "\t\t\t\t|                                                 |\n";
            cout << "\t\t\t\t|              1. Login                           |\n";
            cout << "\t\t\t\t|              2. Register                        |\n";
            cout << "\t\t\t\t|              Input your choice:                 |\n";
            cout << "\t\t\t\t|                                                 |\n";
            cout << "\t\t\t\t|-------------------------------------------------|\n";
            int temp;
            cin >> temp;
            system("CLS");

            switch (temp)
            {
            case 1:
                a.log();
                break;
            case 2:
                a.reg();
                break;
            default:
                cout << "\t\tInvalid" << endl;
                goto Menu_Admin;
                break;
            }
        Menu_Admin_Attributes:
            cout << "\t\t\t\t|-------------------------------------------------|\n";
            cout << "\t\t\t\t|                                                 |\n";
            cout << "\t\t\t\t|              1. Change Password                 |\n";
            cout << "\t\t\t\t|              2. View Details                    |\n";
            cout << "\t\t\t\t|              3. Delete a Docotr                 |\n";
            cout << "\t\t\t\t|              4. Logout                          |\n";
            cout << "\t\t\t\t|                                                 |\n";
            cout << "\t\t\t\t|              Input your choice:                 |\n";
            cout << "\t\t\t\t|                                                 |\n";
            cout << "\t\t\t\t|-------------------------------------------------|\n";
            int tempch, input1;
            string str1, str2;
            cin >> tempch;
            system("CLS");
            switch (tempch)
            {
            case 4:
                goto FrontPage;
                break;
            case 1:
                cout << "\t\tEnter New & Strong Password : ";
                cin >> str1;
                system("CLS");
                a.setPassword(str1);
                a.deleteAdmin();
                a.writeadmin();
                cout << "Changed Succesfully" << endl;

                break;
            case 2:
                a.display();
                break;
            case 3:
                cout << "\t\t\t\t|-------------------------|\n";
                cout << "\t\t\t\t|                         |\n";
                cout << "\t\t\t\t|        Enter Id         |\n";
                cout << "\t\t\t\t|                         |\n";
                cout << "\t\t\t\t|-------------------------|\n";
                cin >> str1;
                system("CLS");

                d.storeDoctor(str1);
                d.deleteDoctor();
                cout << "\t\tDeleted" << endl;
                break;
            default:
                cout << "Invalid";
                goto Menu_Admin_Attributes;
                break;
            }
            goto Menu_Admin_Attributes;
        }
        else if (choice == 2)
        {
        Menu_Patient:
            cout << "\t\t\t\t|-------------------------------------------------|\n";
            cout << "\t\t\t\t|                                                 |\n";
            cout << "\t\t\t\t|              1. Login                           |\n";
            cout << "\t\t\t\t|              2. Register                        |\n";
            cout << "\t\t\t\t|              Input your choice:                 |\n";
            cout << "\t\t\t\t|                                                 |\n";
            cout << "\t\t\t\t|-------------------------------------------------|\n";
            int temp;
            cin >> temp;
            switch (temp)
            {
            case 1:
                p.log();
                break;
            case 2:
                p.reg();
                break;
            default:
                cout << "\t\tWrong Input" << endl;
                goto Menu_Patient;
                break;
            }
        Menu_Pat_Attributes:
            cout << "\t\t\t\t|-------------------------------------------------|\n";
            cout << "\t\t\t\t|                                                 |\n";
            cout << "\t\t\t\t|        1. Change Password                       |\n";
            cout << "\t\t\t\t|        2. Details                               |\n";
            cout << "\t\t\t\t|        3. Display Appointments                  |\n";
            cout << "\t\t\t\t|        4. Change Balace                         |\n";
            cout << "\t\t\t\t|        5. Seach Doctor                          |\n";
            cout << "\t\t\t\t|        6. Book Appointment                      |\n";
            cout << "\t\t\t\t|        7. Edit time                             |\n";
            cout << "\t\t\t\t|        8. Cancel Appointment                    |\n";
            cout << "\t\t\t\t|        9. Give Feedback                         |\n";
            cout << "\t\t\t\t|       10. Logout                                |\n";
            cout << "\t\t\t\t|                                                 |\n";
            cout << "\t\t\t\t|        Enter your choice:                       |\n";
            cout << "\t\t\t\t|                                                 |\n";
            cout << "\t\t\t\t|-------------------------------------------------|\n";
            int tempch, input1, input2;
            string str1, str2;
            cin >> tempch;
            system("CLS");

            switch (tempch)
            {
            case 10:
                goto FrontPage;
                break;
            case 1:
                cout << "\t\tEnter New & Strong Password : ";
                cin >> str1;

                p.setpassword(str1);
                p.deletePatient();
                p.writepatient();
                cout << "\t\tChanged Succesfully" << endl;
                break;
            case 2:
                p.display();
                break;
            case 3:
                p.getappointment()->displayAppointmnet(p.getid(), "patient");
                break;
            case 4:
                cout << "\t\tEnter Amount to add " << endl;
                cin >> input1;
                p.setbalance(p.getbalance() + input1);
                cout << "\t\tUpdated" << endl;
                p.deletePatient();
                p.writepatient();
                break;
            case 5:
                cout << "\t\t\t\t|-------------------------------------------------|\n";
                cout << "\t\t\t\t|                                                 |\n";
                cout << "\t\t\t\t|              1. By Speciality                   |\n";
                cout << "\t\t\t\t|              2. By Area                         |\n";
                cout << "\t\t\t\t|              3. By Hospital                     |\n";
                cout << "\t\t\t\t|                                                 |\n";
                cout << "\t\t\t\t|              Input your choice:                 |\n";
                cout << "\t\t\t\t|                                                 |\n";
                cout << "\t\t\t\t|-------------------------------------------------|\n";
                cin >> input2;
                cout << "\t\tEnter Keyword " << endl;
                cin >> str1;
                system("CLS");
                if (input2 == 1)
                    p.searchDoctor(str1, "speciality");
                else if (input2 == 2)
                    p.searchDoctor(str1, "area");
                else if (input2 == 3)
                    p.searchDoctor(str1, "hospital");
                break;
            case 6:
                cout << "\t\t\t\t|-------------------------|\n";
                cout << "\t\t\t\t|                         |\n";
                cout << "\t\t\t\t|        Enter Id         |\n";
                cout << "\t\t\t\t|                         |\n";
                cout << "\t\t\t\t|-------------------------|\n";
                cin >> str1;
                system("CLS");
                d.storeDoctor(str1);
                p.getappointment()->setdid(str1);
                p.getappointment()->setpid(p.getid());
                p.getappointment()->bookAppointment(d.getcharges());
                p.updateBalance();
                cout << "\t\tAppointment Booked" << endl;
                p.getappointment()->display();
                break;
            case 7:
                cout << "\t\t\t\t|-------------------------|\n";
                cout << "\t\t\t\t|                         |\n";
                cout << "\t\t\t\t|        Enter Id         |\n";
                cout << "\t\t\t\t|                         |\n";
                cout << "\t\t\t\t|-------------------------|\n";
                cin >> str1;
                system("CLS");
                d.storeDoctor(str1);
                p.getappointment()->storeAppoinment(str1, p.getid());
                cout << "\t\t\t\t|-------------------------|\n";
                cout << "\t\t\t\t|                         |\n";
                cout << "\t\t\t\t|       New Time          |\n";
                cout << "\t\t\t\t|                         |\n";
                cout << "\t\t\t\t|-------------------------|\n";
                cin >> str2;
                system("CLS");
                p.getappointment()->setTime(str2);
                p.getappointment()->deleteAppointment();
                p.getappointment()->writeAppointment();
                break;
            case 8:
                cout << "\t\t\t\t|-------------------------|\n";
                cout << "\t\t\t\t|                         |\n";
                cout << "\t\t\t\t|        Enter Id         |\n";
                cout << "\t\t\t\t|                         |\n";
                cout << "\t\t\t\t|-------------------------|\n";
                cin >> str1;
                system("CLS");
                d.storeDoctor(str1);
                p.getappointment()->storeAppoinment(str1, p.getid());
                p.getappointment()->deleteAppointment();
                break;
            case 9:
                cout << "\t\t\t\t|-------------------------|\n";
                cout << "\t\t\t\t|                         |\n";
                cout << "\t\t\t\t|        Enter Id         |\n";
                cout << "\t\t\t\t|                         |\n";
                cout << "\t\t\t\t|-------------------------|\n";
                cin >> str1;
                system("CLS");
                d.storeDoctor(str1);
                p.getappointment()->storeAppoinment(str1, p.getid());
                cout << "\t\t\t\t|-------------------------|\n";
                cout << "\t\t\t\t|                         |\n";
                cout << "\t\t\t\t|        Feedback         |\n";
                cout << "\t\t\t\t|                         |\n";
                cout << "\t\t\t\t|-------------------------|\n";
                cin >> str2;
                system("CLS");

                cout << "\t\t\t\t|-----------------------|\n";
                cout << "\t\t\t\t|                       |\n";
                cout << "\t\t\t\t|          Give         |\n";
                cout << "\t\t\t\t|         Rating        |\n";
                cout << "\t\t\t\t|                       |\n";
                cout << "\t\t\t\t|-----------------------|\n";
                cin >> input1;
                system("CLS");
                f.setFeed(str2);
                f.setRating(input1);
                f.writeFeedback(d.getid(), p.getid());
                p.updateRating(str1, input1);
                break;
            default:
                cout << "\t\tInvalid" << endl;
                goto Menu_Patient;
                break;
            }
            goto Menu_Pat_Attributes;
        }
        else if (choice == 3)
        {
        Menu_Doctor:
            cout << "\t\t\t\t|-------------------------------------------------|\n";
            cout << "\t\t\t\t|                                                 |\n";
            cout << "\t\t\t\t|              1. Login                           |\n";
            cout << "\t\t\t\t|              2. Register                        |\n";
            cout << "\t\t\t\t|              Input your choice:                 |\n";
            cout << "\t\t\t\t|                                                 |\n";
            cout << "\t\t\t\t|-------------------------------------------------|\n";

            int temp;
            cin >> temp;
            system("CLS");

            switch (temp)
            {
            case 1:
                d.log();
                break;
            case 2:
                d.reg();
                break;
            default:
                cout << "\t\tEnter a Valid opt" << endl;
                goto Menu_Doctor;
                break;
            }
        Menu_Doc_Attributes:
            cout << "\t\t\t\t|-------------------------------------------------|\n";
            cout << "\t\t\t\t|                                                 |\n";
            cout << "\t\t\t\t|        1. Change Time                           |\n";
            cout << "\t\t\t\t|        2. Change Fee                            |\n";
            cout << "\t\t\t\t|        3. Change Location                       |\n";
            cout << "\t\t\t\t|        4. Delete Time                           |\n";
            cout << "\t\t\t\t|        5. Display Detail                        |\n";
            cout << "\t\t\t\t|        6. Dispplay Appointments                 |\n";
            cout << "\t\t\t\t|        7. Change Status                         |\n";
            cout << "\t\t\t\t|        8. Logout                                |\n";
            cout << "\t\t\t\t|                                                 |\n";
            cout << "\t\t\t\t|        Enter your choice:                       |\n";
            cout << "\t\t\t\t|                                                 |\n";
            cout << "\t\t\t\t|-------------------------------------------------|\n";

            int tempch;
            string str1, str2;
            cin >> tempch;
            system("CLS");
            switch (tempch)
            {
            case 8:
                goto FrontPage;
                break;
            case 1:
                cout << "\t\t\t\t|----------------------------------|\n";
                cout << "\t\t\t\t|                                  |\n";
                cout << "\t\t\t\t|        Enter END Time            |\n";
                cout << "\t\t\t\t|                                  |\n";
                cout << "\t\t\t\t|----------------------------------|\n";
                cin >> str1;
                system("CLS");

                cout << "\t\t\t\t|----------------------------------|\n";
                cout << "\t\t\t\t|                                  |\n";
                cout << "\t\t\t\t|        Enter END Time            |\n";
                cout << "\t\t\t\t|                                  |\n";
                cout << "\t\t\t\t|----------------------------------|\n";
                cin >> str2;
                system("CLS");
                d.setstime(str1);
                d.setetime(str2);
                d.deleteDoctor();
                d.writeDoctor();
                break;
            case 4:
                d.setstime("0");
                d.setetime("0");
                d.deleteDoctor();
                d.writeDoctor();
                cout << "\t\tDeleted" << endl;
                break;
            case 2:
                cout << "\t\tEnter Fee " << endl;
                cin >> str1;
                system("CLS");
                d.setfee(str1);
                d.deleteDoctor();
                d.writeDoctor();
                cout << "\t\tUpdated" << endl;
                break;
            case 3:
                cout << "\t\t\t\t|----------------------------------|\n";
                cout << "\t\t\t\t|                                  |\n";
                cout << "\t\t\t\t|        Enter City name           |\n";
                cout << "\t\t\t\t|                                  |\n";
                cout << "\t\t\t\t|----------------------------------|\n";
                cin >> str1;
                system("CLS");

                cout << "\t\t\t\t|-----------------------------------|\n";
                cout << "\t\t\t\t|                                   |\n";
                cout << "\t\t\t\t|        Enter hospital name        |\n";
                cout << "\t\t\t\t|                                   |\n";
                cout << "\t\t\t\t|-----------------------------------|\n";
                cin >> str2;
                system("CLS");
                d.setarea(str1);
                d.sethospital(str2);
                d.deleteDoctor();
                d.writeDoctor();
                cout << "\t\tUpdated<" << endl;
                break;
            case 5:
                d.display();
                break;
            case 6:
                d.getappointment()->displayAppointmnet(d.getid(), "doctor");
                break;
            case 7:
                cout << "\t\t\t\t|-------------------------|\n";
                cout << "\t\t\t\t|                         |\n";
                cout << "\t\t\t\t|        Enter Id         |\n";
                cout << "\t\t\t\t|                         |\n";
                cout << "\t\t\t\t|-------------------------|\n";
                cin >> str1;
                system("CLS");

                d.getappointment()->storeAppoinment(d.getid(), str1);
                d.getappointment()->setStatus("Confirmed");
                cout << "\t\tConfirmed" << endl;
                d.getappointment()->display();
                d.getappointment()->deleteAppointment();
                d.getappointment()->writeAppointment();
                cout << endl;
                break;
            default:
                cout << "\t\tWrong Input" << endl;
                goto Menu_Doc_Attributes;
                break;
            }
            goto Menu_Doc_Attributes;
        }

        else
        {
            goto FrontPage;
        }
    }
}