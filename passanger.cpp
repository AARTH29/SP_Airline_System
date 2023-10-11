#include "passanger.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
void passanger::set_data()
{
    cout<<"WELOCOME"<<endl;
    cout<<"Enter your name"<<endl;
    cin.ignore();
    cin.getline(pname,sizeof(pname));
    cout<<"Enter your surname"<<endl;
    cin.ignore();
    cin.getline(surname,sizeof(surname));
    cout<<"Enter your nationality"<<endl;
    cin.ignore();
    cin.getline(nationality,sizeof(nationality));
    cout<<"Enter your passport number"<<endl;
    cin>>passport_no;
    cout<<"Enter your age"<<endl;
    cin>>age;
    cout<<"Enter your email id"<<endl;
    cin.ignore();
    cin.getline(email_id,sizeof(email_id));
    cout<<"Enter your phone number"<<endl;
    cin>>tele_no;
    cout<<"Enter the airline name u wanna travel"<<endl;
    cin>>airline_type;
    cout<<"Enter the flight number as well"<<endl;
    cin>>plane_no;
    cout<<"The departure time available"<<endl;
    f.depart(plane_no);
    cout<<"enter the boarding time"<<endl;
    cin.ignore();
    cin.getline(board_time,sizeof(board_time));
    cout<<"Which type of seat do you need[business or economical]?"<<endl;
    cin.ignore();
    cin.getline(type_seat,sizeof(type_seat));
    f.choose_seat(plane_no,type_seat);
}
void passanger::book_flight()
{
    passanger p;
    ofstream pass;
    pass.open("user.txt",ios::out);
    if(!pass)
        cout<<"ERROR OPENING FILE"<<endl;
    p.set_data();
    pass.write((char*)&p,sizeof(p));
    pass.close();
}
void passanger::get_data()
{
    cout<<"PASSANGER NAME:"<<pname<<endl;
    cout<<"HIS/HER SURNAME:"<<surname<<endl;
    cout<<"NATIONALITY:"<<nationality<<endl;
    cout<<"PASSPORT NUMBER:"<<passport_no<<endl;
    cout<<"AGE:"<<age<<endl;
    cout<<"EMAIL ID:"<<email_id<<endl;
    cout<<"TELEPHONE NUMBER:"<<tele_no<<endl;
    cout<<"PREFERED AIRPLANE NAME:"<<airline_type<<endl;
    cout<<"PLANE NUMBER PREFERENCE:"<<plane_no<<endl;
}
void passanger::modify()
{
    passanger p;
    fstream peop;
    peop.open("user.txt",ios::in|ios::out);
    peop.read((char*)&p,sizeof(p));
    int no;
    char found='n';
    cout<<"ENTER YOUR PASSPORT NUMBER"<<endl;
    cin>>no;
    while(!peop.eof())
    {
        if(p.passport_no==no)
        {
            int n;
            found = 'f';
            cout<<"WHICH DATA OF YOURS DO YOU WANNA ALTER"<<endl;
            cout<<"1] NAME\n 2] SURNAME\n 3] NATIONALITY\n 4]PASSPORT NUMBER\n 5]AIRLINE PREFERENCE\n 6]EMAIL ID\n 7]TELEPHONE NUMBER"<<endl;
            cin>>n;
            switch(n){
                case 1:{;
                    cout<<"ENTER THE NEW NAME OF THE PASSENGER['.' to retain the old name]"<<endl;
                    cin.ignore();
                    cin.getline(p.pname,sizeof(p.pname));
                    if(strcmp(p.pname,".")==0)
                           cout<<"****old name retained****"<<endl;
                    else
                        peop.write((char*)&p,sizeof(p));
                    };break;
                case 2:{
                        cout<<"ENTER TEH NEW SURNAME['.' to retain the old name]"<<endl;
                        cin.ignore();
                        cin.getline(p.surname,sizeof(p.surname));
                        if(strcmp(p.surname,".")==0)
                            cout<<"old name retained"<<endl;
                        else
                            peop.write((char*)&p,sizeof(p));
                    };break;
                case 3:{
                        cout<<"ENTER THE NEW NATIONALITY['.' to retain the old nationality]"<<endl;
                        cin.ignore();
                        cin.getline(p.nationality,sizeof(p.nationality));
                        if(strcmp(p.nationality,".")!=0)
                            peop.write((char*)&p,sizeof(p));
                        else
                            cout<<"****old nationality retained****"<<endl;
                        };break;
                case 4:{
                        cout<<"ENTER THE NEW NUMBER[-1 to retain old number]"<<endl;
                        cin>>p.passport_no;
                        if(p.passport_no==-1)
                            cout<<"****old number retained****"<<endl;
                        else
                            peop.write((char*)&p,sizeof(p));
                        };break;
                case 5:{
                        cout<<"ENTER THE NEW AIRLINE PREFERENCE'.' to retain old name]"<<endl;
                        cin.ignore();
                        cin.getline(p.airline_type,sizeof(p.airline_type));
                        if(strcmp(p.airline_type,".")!=0)
                            peop.write((char*)&p,sizeof(p));
                        else
                            cout<<"****old airline name retained****"<<endl;
                        };break;
                case 6:{
                        cout<<"ENTER THE NEW ID['.' to retain old id]"<<endl;
                        cin.ignore();
                        cin.getline(p.email_id,sizeof(p.email_id));
                        if (strcmp(p.email_id,".")!=0)
                            peop.write((char*)&p,sizeof(p));
                        else
                            cout<<"*****old id retained****"<<endl;
                        };break;
                case 7:{
                        cout<<"ENTER THE NEW TELEPHONE NUMBER[-1 to retain old number]"<<endl;
                        cin>>p.tele_no;
                        if(p.tele_no==-1)
                            cout<<"****The old number retained****"<<endl;
                        else
                            peop.write((char*)&p,sizeof(p));
                        };break;
                default:cout<<"SORRY,INVALID OPTION"<<endl;
            }
        }
       peop.read((char*)&p,sizeof(p));
    }
    if(found =='n')
        cout<<"RECORD NOT FOUND"<<endl;
    peop.close();
}
void passanger::display()
{
    passanger p;
    ifstream fl;
    fl.open("user.txt",ios::in);
    fl.read((char*)&p,sizeof(p));
    if(!fl)
        cout<<"FILE NOT FOUND"<<endl;
    int nm;
    char found = 'n';
    cout<<"ENTER THE PASSPORT NUMBER"<<endl;
    cin>>nm;
    while(!fl.eof())
    {
        if(p.passport_no==nm)
        {
            found = 'f';
            p.get_data();
        }
        fl.read((char*)&p,sizeof(p));
    }
    if(found=='n')
    {
        cout<<"RECORD NOT FOUND"<<endl;
    }
    fl.close();
}
int passanger::check(int num,string name)
{
                    passanger pa;
                    ifstream us;
                    us.open("user.txt",ios::in);
                    us.read((char*)&pa,sizeof(pa));
                    if(!us)
                        cout<<"PASSENGER FILE NOT FOUND"<<endl;
                    while(!us.eof())
                    {
                        if(pa.passport_no==num && strcmp(pa.pname,name)==0)
                            {
                                pa.get_data();
                                return 1;
                                break;
                            }
                        us.read((char*)&pa,sizeof(pa));
                    }
                    us.close();
}
void passanger::pass(int flno,string dep,string fltype)
{
    int k=0;
    passanger p3;
    ifstream s("user.txt");
    s.read((char*)&p3,sizeof(p3));
    while(!s.eof())
    {
        if(p3.plane_no==flno && strcmp(p3.board_time,dep)==0 && strcmp(p3.airline_type,fltype)==0)
        {
            k=1;
            p3.get_data();
            break;
        }
        s.read((char*)&p3,sizeof(p3));
    }
    s.close();
    if(k==0)
    {
        cout<<"PASSANGERS NOT AVAILABLE"<<endl;
    }
}

