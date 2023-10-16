#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
fstream store;
fstream pass;
struct datain         // Members data 
{
    string name;
    int Age;
    char sex;
    int idd1;
    string contact1;
    string service_type1;
    string preferred_timing1;
    double monthly_fee1;
};
datain d;
void save_member()
{
    store.open("dataStore.txt", ios::app | ios::out);
    int n;
    cout << "Enter ID:";
    cin >> d.idd1;
    cout << "Enter  Name:";
    cin >> d.name;
    cin.ignore();
    cout
        << "Enter Gender:";
    cin >> d.sex;
    cout << "Enter  Age:";
    cin >> d.Age;
    cout << "Enter contact:";
    cin >> d.contact1;
    store << d.idd1 << " ";
    store << d.name << " ";
    store << d.Age << " ";
    store << d.sex << " ";
    store << d.contact1 << " ";
again_service:
    cout << "Select service type\n1.Gym lonely(400 birr)\n2.Gym + Aerobic(800 birr)\n3.Gym + Yoga(800 birr)\n";
    cin >> n;
    switch (n)
    {
    case 1:
        d.service_type1 = "Gym_lonely";
        d.monthly_fee1 = 400;
        store << d.service_type1 << " ";
        store << d.monthly_fee1 << " ";
        break;
    case 2:
        d.service_type1 = "Gym_+_Aerobic";
        d.monthly_fee1 = 800;
        store << d.service_type1 << " ";
        store << d.monthly_fee1 << " ";
        break;
    case 3:
        d.service_type1 = "Gym_+_Yoga";
        d.monthly_fee1 = 800;
        store << d.service_type1 << " ";
        store << d.monthly_fee1 << " ";
        break;
    default:
        cout << "Invalid";
        goto again_service;
        break;
    }
again_time:
    cout << "please select your preferred timings\n";
    cout << "1.Morining\n2.Evening\n";
    cin >> n;
    switch (n)
    {
    case 1:
        d.preferred_timing1 = "Moring";
        store << d.preferred_timing1 << " ";

        break;
    case 2:
        d.preferred_timing1 = "Evening";
        store << d.preferred_timing1 << " ";

        break;
    default:
        cout << "Invalid";
        goto again_time;
        break;
    }
    system("cls");
    cout << "***********************************************\n";
    cout << "Your Profile data:";
    cout << "\n***********************************************\n";
    cout << endl
         << "member ID: " << d.idd1;
    cout << endl
         << "Name: " << d.name;
    cout << endl
         << "Gender: " << d.sex;
    cout << endl
         << "category: " << d.service_type1;
    cout << endl
         << "fee: " << d.monthly_fee1;
    cout << endl
         << "contact: " << d.contact1;
    cout << endl
         << "timings: " << d.preferred_timing1;
    cout << "\n\nthe member has been succesfully added......\n";
    store << "\n";
}

void show_all()      // used for to display all records 
{
    store.open("dataStore.txt", ios::in);
    cout << "ID\tName\t\tAge\t\tSex\t\tContact\t\tService\t\t\tFee\t\tTiming" << endl;

    if (store.is_open())
    {
        while (store >> d.idd1 >> d.name >> d.Age >> d.sex >> d.contact1 >> d.service_type1 >> d.monthly_fee1 >> d.preferred_timing1)
        {
            cout << d.idd1 << "\t" << d.name << "\t\t" << d.Age << "\t\t" << d.sex << "\t\t" << d.contact1 << "\t\t" << d.service_type1 << "\t\t" << d.monthly_fee1 << "\t\t" << d.preferred_timing1 << endl;
        }
    }
    store.close();
}
void delete_member()
{

    int m;
    bool flag = false;
    cout << "Please Enter the member ID:";
    cin >> m;
    store.open("dataStore.txt", ios::in);
    fstream edited;
    edited.open("edited.txt", ios::out);
    if (store.is_open())
    {
        int n = 0;
        while (store >> d.idd1 >> d.name >> d.Age >> d.sex >> d.contact1 >> d.service_type1 >> d.monthly_fee1 >> d.preferred_timing1)
        {
            if (d.idd1 != m)
            {
                edited << d.idd1 << " " << d.name << " " << d.Age << " " << d.sex << " " << d.contact1 << " " << d.service_type1 << " " << d.monthly_fee1 << " " << d.preferred_timing1 << endl;
            }
            else
            {
                flag = true;
            }
        }
    }
    store.close();
    edited.close();

    if (flag == true)
    {
        remove("dataStore.txt");
        rename("edited.txt", "dataStore.txt");
        cout << endl
             << endl
             << "\tRecord Deleted...\n";
    }
    else
    {
        cout << "\nID NOT FOUND!\n";
    }
}
void edit_member()
{

    // system("cls");
    int m, n;
    ofstream edited;
    bool flag = false;
    cout
        << "Please Enter The member ID: ";
    cin >> m;
    store.open("dataStore.txt", ios::in);
    edited.open("edited.txt", ios::out);
    if (store.is_open())
    {
        while (store >> d.idd1 >> d.name >> d.Age >> d.sex >> d.contact1 >> d.service_type1 >> d.monthly_fee1 >> d.preferred_timing1)
        {
            if (d.idd1 != m)
            {
                edited << d.idd1 << " " << d.name << " " << d.Age << " " << d.sex << " " << d.contact1 << " " << d.service_type1 << " " << d.monthly_fee1 << " " << d.preferred_timing1 << endl;
            }
            else
            {

                flag = true;
                cout << "***********************************************\n";
                cout << "Original data:";
                cout << "\n***********************************************\n";
                cout << endl
                     << "member ID: " << d.idd1;
                cout << endl
                     << "Name: " << d.name;
                cout << endl
                     << "Age: " << d.Age;
                cout << endl
                     << "Gender: " << d.sex;
                cout << endl
                     << "category: " << d.service_type1;
                cout << endl
                     << "fee: " << d.monthly_fee1;
                cout << endl
                     << "contact: " << d.contact1;
                cout << endl
                     << "timings: " << d.preferred_timing1;

                flag = true;
                cout << "\n\n";
                cout << "Please Choose What Do you Went to Update:\n";
                cout << "\n\t1.Name\n\t2.Sex\n\t3.Age\n\t4.Service Type\n\t5.Contact\n\t6.Preferred Timing\n\t7.total change:";
                int j;
                cin >> j;
                switch (j)
                {
                case 1:
                    cout << "Enter Name:";
                    cin >> d.name;
                    edited << d.idd1 << " " << d.name << " " << d.Age << " " << d.sex << " " << d.contact1 << " " << d.service_type1 << " " << d.monthly_fee1 << " " << d.preferred_timing1 << endl;
                    break;
                case 2:
                    cout << "Entre Sex:";
                    cin >> d.sex;
                    edited << d.idd1 << " " << d.name << " " << d.Age << " " << d.sex << " " << d.contact1 << " " << d.service_type1 << " " << d.monthly_fee1 << " " << d.preferred_timing1 << endl;
                    break;
                case 3:
                    cout << "Enter Age:";
                    cin >> d.Age;
                    edited << d.idd1 << " " << d.name << " " << d.Age << " " << d.sex << " " << d.contact1 << " " << d.service_type1 << " " << d.monthly_fee1 << " " << d.preferred_timing1 << endl;
                    break;
                case 4:
                    int n;
                again_service:
                    cout << "Select service type\n1.Gym lonely(400 birr)\n2.Gym + Aerobic(800 birr)\n3.Gym + Yoga(800 birr)\n";
                    cin >> n;

                    switch (n)
                    {
                    case 1:
                        d.service_type1 = "Gym lonely";
                        d.monthly_fee1 = 400;
                        break;
                    case 2:
                        d.service_type1 = "Gym + Aerobic";
                        d.monthly_fee1 = 800;
                        break;
                    case 3:
                        d.service_type1 = "Gym + Yoga";
                        d.monthly_fee1 = 800;
                        break;
                    default:
                        cout << "Invalid";
                        goto again_service;
                        break;
                    }
                    edited << d.idd1 << " " << d.name << " " << d.Age << " " << d.sex << " " << d.contact1 << " " << d.service_type1 << " " << d.monthly_fee1 << " " << d.preferred_timing1 << endl;
                    break;
                case 5:
                    cout << "Enter contact:";
                    cin >> d.contact1;
                    edited << d.idd1 << " " << d.name << " " << d.Age << " " << d.sex << " " << d.contact1 << " " << d.service_type1 << " " << d.monthly_fee1 << " " << d.preferred_timing1 << endl;
                    break;
                case 6:
                agmain_time:
                    int o;
                    cout << "please select your preferred timings\n";
                    cout << "1.Morining\n2.Evening\n";
                    cin >> o;
                    switch (o)
                    {
                    case 1:
                        d.preferred_timing1 = "Moring";
                        break;
                    case 2:
                        d.preferred_timing1 = "Evening";
                        break;
                    default:
                        cout << "Invalid";
                        goto agmain_time;
                        break;
                    }
                    edited << d.idd1 << " " << d.name << " " << d.Age << " " << d.sex << " " << d.contact1 << " " << d.service_type1 << " " << d.monthly_fee1 << " " << d.preferred_timing1 << endl;
                    break;
                case 7:
                    int u;
                    cout << "Enter ID:";
                    cin >> d.idd1;
                    cout << "Enter  Name:";
                    cin >> d.name;
                    cout
                        << "Enter Gender:";
                    cin >> d.sex;
                    cout << "Enter  Age:";
                    cin >> d.Age;
                    cout << "Enter contact:";
                    cin >> d.contact1;
                    edited << d.idd1 << " ";
                    edited << d.name << " ";
                    edited << d.Age << " ";
                    edited << d.sex << " ";
                    edited << d.contact1 << " ";
                again_servicet:
                    cout << "Select service type\n1.Gym lonely(400 birr)\n2.Gym + Aerobic(800 birr)\n3.Gym + Yoga(800 birr)\n";
                    cin >> u;
                    switch (u)
                    {
                    case 1:
                        d.service_type1 = "Gym_lonely";
                        d.monthly_fee1 = 400;
                        edited << d.service_type1 << " ";
                        edited << d.monthly_fee1 << " ";
                        break;
                    case 2:
                        d.service_type1 = "Gym_Plus_Aerobic";
                        d.monthly_fee1 = 800;
                        edited << d.service_type1 << " ";
                        edited << d.monthly_fee1 << " ";
                        break;
                    case 3:
                        d.service_type1 = "Gym_plus_Yoga";
                        d.monthly_fee1 = 800;
                        edited << d.service_type1 << " ";
                        edited << d.monthly_fee1 << " ";
                        break;
                    default:
                        cout << "Invalid";
                        goto again_servicet;
                        break;
                    }
                again_time:
                    cout << "please select your preferred timings\n";
                    cout << "1.Morining\n2.Evening\n";
                    cin >> u;
                    switch (u)
                    {
                    case 1:
                        d.preferred_timing1 = "Moring";
                        edited << d.preferred_timing1 << " ";

                        break;
                    case 2:
                        d.preferred_timing1 = "Evening";
                        edited << d.preferred_timing1 << endl;

                        break;
                    default:
                        cout << "Invalid";
                        goto again_time;
                        break;
                    }
                    break;
                }
            }
        }
    }
    store.close();
    edited.close();
    remove("dataStore.txt");
    rename("edited.txt", "dataStore.txt");

    if (flag == false)
    {

        cout << "\n\n\tID NOT FOUND!\n";
    }
    else
        cout << "\n\n\tRecord Successfully Updated...\n";
}
void display_record(int num)
{
    store.open("dataStore.txt", ios::in);
    bool flag = false;
    if (store.is_open())
    {
        while (store >> d.idd1 >> d.name >> d.Age >>d. sex >> d.contact1 >>d. service_type1 >>d. monthly_fee1 >>d. preferred_timing1)
        {
            if (d.idd1 == num)
            {
                flag = true;
                cout << "ID\tName\t\tAge\t\tSex\t\tContact\t\tService\t\t\tFee\t\tTiming" << endl;
                cout << d.idd1 << "\t" << d.name << "\t\t" <<d. Age << "\t\t" << d.sex << "\t\t" << d.contact1 << "\t\t" << d.service_type1 << "\t\t" <<d. monthly_fee1 << "\t\t" <<d. preferred_timing1 << endl;
                break;
            }
        }
    }
    if (flag == false)
    {
        cout << "\n\nID NOT FOUND!\n\n";
    }
    store.close();
}
bool admin_login()
{
    string name;
    string name2;
    char ch;
    string pa;
    string pa2;
    pass.open("password.txt", ios::in);
    pass >> name2 >> pa2;
endegena:
    cout << "Enter Your Username:";
    cin >> name;
    if (name != name2)
    {
        cout << "INCORRECT Username!\n";
        goto endegena;
    }
endegena2:
    cout << "Enter Your password:";
    cin >> pa;
    if (pa != pa2)
    {
        cout << "\nINCORRECT Password!\n";
        goto endegena2;
    }
    pass.close();
    cout << "Do you want to change your username and password (y/n):";
    cin >> ch;
    if (ch == 'y'| ch=='Y')
    {
        ofstream editpass;
        editpass.open("editpass.txt", ios::out);
        cout << "\nEnter your new Username:";
        cin >> name;
        cout << "\nEnter your new Password:";
        cin >> pa;
        editpass << name << " " << pa;
        editpass.close();
        pass.close();
        remove("password.txt");
        rename("editpass.txt", "password.txt");
    }

    return true;
}
void user_service()
{
    for (;;)
    {
        int m;
        cout << "\n***********************************************\n";
        cout << "\t1.Join gym\n\t2.Quit gym\n\t3.Edit your profile\n\t4.Enterance Menu\n\t5.EXIT!";
        cout << "\n***********************************************\n";
        cout << endl
             << endl
             << "\n Etenter your choice:";
        cin >> m;
        if (m == 1)
        {
            system("cls");
            save_member();
        }
        else if (m == 2)
        {
            system("cls");
            delete_member();
            break;
        }
        else if (m == 3)
        {
            system("cls");
            edit_member();
            break;
        }
        else if (m == 4)
        {
            break;
        }
        else
        {
            exit(0);
        }
    }
}
void Admin_service()
{
    for (;;)
    {
        int option;
        cout << "***********************************************";
        cout << "\n\t1.CREATE MEMBER";
        cout << "\n\t2.DISPLAY ALL RECORDS";
        cout << "\n\t3.SEARCH FOR A PARTICULAR RECORD ";
        cout << "\n\t4.EDIT MEMBER DETAILS";
        cout << "\n\t5.DELETE MEMBER";
        cout << "\n\t6.GO BACK TO MAIN MENU";
        cout << "\n\t7.EXIT!";
        cout << "\n*********************************************";
        cout << "\n\n\tSelect Option: ";
        cin >> option;
    if(option==1){

            system("cls");
            save_member();
    }
        else if(option==2){
            system("cls");
            show_all();
            
        }

        else if(option==3){
            int num;
            system("cls");
            cout << "Please Enter the member ID: ";
            cin >> num;
            display_record(num);
        }

        else if(option==4){
            edit_member();
        }

        else if(option==5){
            delete_member();
        }

       else if(option==6){
            system("cls");
            break;
            }
       else if(option==7){
            cout << "GOOD BYe";
            exit(0);
           
        }
    }
}
void aboutUs();
int main()
{
   system("cls");
    cout<<"\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\ "
        <<" WELECOME \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\  \n";
    int i, n, m;
    string name, code;
Enterance:
    cout << "***********************************************\n";
    cout << "Fitness Center (gym) management system" << endl;
    cout << "\n**********************************************";
    cout
        << endl
        << "SELECT MODE" << endl
        << "1)User" << endl
        << "2)Admin" << endl
        << "3)Guidelines" << endl
        << "4)About Us" << endl;
    cout << "Options avilable are[1/2/3/4]\n";
again:
    cout << "Enter Your Choice :";
    cin >> i;
if(i==1){
        cout << endl
             << "You're in user mode" << endl;
        user_service();
        goto Enterance;
}
    else if(i==2){
        if (admin_login())
        {
            system("cls");
            cout << endl
                 << "You're in Admin mode" << endl;
            Admin_service();
            goto Enterance;
        }
    }
    else if(i==3){
        system("cls");
        fstream guide;
        guide.open("guidelines.txt", ios::in);
        if (guide.is_open())
        {
            string line;
            while (getline(guide, line))
            {
                cout << line << endl;
            }
            guide.close();
        }
        goto Enterance;
    }
    else if(i==4){
         system("cls");
        aboutUs();
        goto Enterance;
    }
    else {
        cout << "Enter valid Choices:\n";
        goto again;
    }

    return 0;
}
void aboutUs()
{

    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^  Wellcome To About Us Page  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    cout << "****                                                                                ****\n";
    cout << "****  We are Students at Addis Ababa Science and Technology University!             ****\n";
    cout << "****  Department: Software engineering.                                             ****\n";
    cout << "****  Year: 2nd Year.                                                               ****\n";
    cout << "****  Team size: 5                                                                  ****\n";
    cout << "****                                                                                ****\n";
    cout << "****  Members                                                                       ****\n";
    cout << "****  No_    Name                                          Id                       ****\n";
    cout << "****  1.     Teklu Moges                                   ETS 1531/14              ****\n";
    cout << "****  2.    Temesgen Abebayehu                             ETS 1534/14              ****\n";
    cout << "****  3.    Tamrat Demse                                   ETS 1523/14              ****\n";
    cout << "****  4.    Tesfamikael Almaw                              ETS 1544/14              ****\n";
    cout << "****  5.    Zeal Tesfaye                                   ETS 1788/14              ****\n";
    cout << "****                                                                                ****\n";
    cout << "****  \"Alone we can do so little; together we can do so much.\" : Our Motive         ****\n";
    cout << "****  \"Knowledge is our operating system.\"                                          ****\n";
    cout << "****                                                                                ****\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
}