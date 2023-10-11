#include "flight.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;
void flight::set_flight_info()
{
    cout<<"ENTER THE AIRLINE NAME:"<<endl;
    cin.ignore();
    cin.getline(airline_name,sizeof(airline_name));
    cout<<"ENTER THE FLIGHT NUMBER:"<<endl;
    cin>>fl_no;
    cout<<"ENTER THE BOARDING POINT OF FLIGHT:"<<endl;
    cin.ignore();
    cin.getline(from,sizeof(from));
    cout<<"ENTER HE DESTINATION POINT OF FLIGHT:"<<endl;
    cin.getline(to,sizeof(to));
    cout<<"ENTER THE NUMBER OF ECONOMIC SEATS AVAILABLE IN FLIGHT:"<<endl;
    cin>>e_seat;
    cout<<"ENTER THE NUMBER OF BUSINESS SEATS AVAILABLE IN FLIGHT:"<<endl;
    cin>>b_seat;
    cout<<"ENTER THE NUMBER OF DEPARTURE TIMES:"<<endl;
    cin>>number;
    for(int i=0;i<number;i++)
    {
        cin>>depart_time[i];
    }
}
void flight::get_flight_info()
{
    cout<<"AIRLINE NAME:"<<airline_name<<endl;
    cout<<"FLIGHT NUMBER:"<<fl_no<<endl;
    cout<<"BOARDING POINT:"<<from<<endl;
    cout<<"DESTINATION:"<<to<<endl;
    cout<<"NUMBER OF ECONOMIC SEATS:"<<e_seat<<endl;
    cout<<"NUMBER OF BUSINESS SEAT AVAILABLE:"<<b_seat<<endl;
    for(int i=0;i<number;i++)
    {
        cout<<depart_time[i]<<endl;
    }
    cout<<"/________________________________/"<<endl;
}
void flight::depart(int flno)
{
    int g=0;
    flight k;
    ifstream h1("plane.txt");
    h1.read((char*)&k,sizeof(k));
    while(!h1.eof())
    {
        if(k.fl_no==flno)
        {
            g=1;
            for(int i=0;i<k.number;i++)
            {
                cout<<k.depart_time[i]<<endl;
            }
            break;
        }
        h1.read((char*)&k,sizeof(k));
    }
    h1.close();
    if(g==0)
    {
        cout<<">>>>>>>>FLIGHT NOT AVAILABLE<<<<<<<<"<<endl;
    }
}
void flight::write()
{
    flight f;
    ofstream file;
    file.open("plane.txt",ios::out);
    if(!file)
    {
        cout<<"ERROR OPENING FILE"<<endl;
    }
    char ch='y';
    while(ch=='y')
    {
        f.set_flight_info();
        file.write((char*)&f,sizeof(f));
        cout<<"WANT TO ENTER MOER? [yes ENETR y,no ENTER n]"<<endl;
        cin>>ch;
    }
    file.close();
}
void flight::add_flight()
{
    flight f;
    ofstream file1;
    file1.open("plane.txt",ios::out);
    if(!file1)
    {
        cout<<"ERROR OPENING FILE"<<endl;
    }
    char ch='y';
    while(ch=='y')
    {
        f.set_flight_info();
        file1.write((char*)&f,sizeof(f));
        cout<<"WANT TO ENTER MORE?[yes or no]"<<endl;
        cin>>ch;
    }
    file1.close();
}
void flight::delete_flight() {
    int pl_no;
    char option;
    
    do {
        cout << "WHETHER YOU WANNA DELETE ANYMORE DETAIL?[if yes enter y]" << endl;
        cin >> option;

        if (option == 'y') {
            cout << "ENTER THE PLANE NUMBER WHOSE DETAILS ARE TO BE DELETED" << endl;
            cin >> pl_no;

            char found = findAndDeleteFlight(pl_no);

            if (found == 'n') {
                cout << "FLIGHT RECORD NOT FOUND" << endl;
            }
        }
    } while (option == 'y');
}

char flight::findAndDeleteFlight(int pl_no) {
    char found = 'n';
    flight f;
    ifstream fio("plane.txt");
    ofstream filef("temp.txt", ios::out);

    fio.read((char*)&f, sizeof(f));
    
    while (!fio.eof()) {
        if (f.fl_no == pl_no) {
            found = 'f';
            f.get_flight_info();
            cout << ">>>>>>Are you sure to delete this record?[if yes enter y, if not enter n]<<<<<<" << endl;
            char option1;
            cin >> option1;
            
            if (option1 == 'n') {
                filef.write((char*)&f, sizeof(f));
            } else {
                cout << "***********//YOUR RECORD SUCCESSFULLY DELETED//*********" << endl;
            }
        } else {
            filef.write((char*)&f, sizeof(f));
        }
        
        fio.read((char*)&f, sizeof(f));
    }

    fio.close();
    filef.close();
    remove("plane.txt");
    rename("temp.txt", "plane.txt");

    return found;
}

void flight::display_flight()
{
    ifstream fo;
    flight f;
    fo.open("plane.txt");
    fo.read((char*)&f,sizeof(f));
    if(!fo)
    {
        cout<<"File not found"<<endl;
    }
    int pl_no;
    char found = 'n';
    cout<<">>>>>consider the latest info<<<<<<<<"<<endl;
    cout<<"ENTER THE PLANE NUMBER WHOSE DETAILS ARE TO BE DISPLAYED"<<endl;
    cin>>pl_no;
    while(!fo.eof())
    {
        if(f.fl_no==pl_no)
        {
            found = 'f';
            f.get_flight_info();
        }
        fo.read((char*)&f,sizeof(f));
    }
    if(found=='n')
    {
        cout<<"RECORD NOT FOUND"<<endl;
    }
    fo.close();
}
void flight::mod_flight()
{
    fstream file2;
    flight f;
    file2.open("plane.txt",ios::in|ios::out);
    file2.read((char*)&f,sizeof(f));
    int pl_no;
    char found = 'n';
    string type;
    cout<<"ENTER THE PLANE NUMBER WHOSE RECORD HAS TO BE ALTERED"<<endl;
    cin>>pl_no;
    cout<<"ENTER THE PLANE TYPE AS WELL"<<endl;
    cin.ignore();
    cin.getline(type,sizeof(type));
    while(!file2.eof())
    {
        if(f.fl_no==pl_no && strcmp(f.airline_name,type)==0)
        {
            found = 'f';
            char choice = 'y';
            int n;
            while(choice=='y')
            {
                cout<<"WHICH DATA OF THE FLIGHT YOU WANNA CHANGE"<<endl;
                cout<<"1]FLIGHT NUMBER\n 2]AIRLINE NAME\n 3]START OF\n 4]DESTINATION\n 5]DEPART TIME\n6]E_SEAT_NO \n7]B_SEAT_NO"<<endl;
                cin>>n;
                switch(n){
                    case 1:{
                            cout<<"ENTER NEW FLIGHT NUMBER[enter -1 to retain the old number]"<<endl;
                            cin>>f.fl_no;
                            if(f.fl_no==-1)
                                cout<<"******old one retained******"<<endl;
                            else
                                file2.write((char*)&f,sizeof(f));
                            };break;
                    case 2:{
                            cout<<"ENTER THE NEW AIRLINE NAME[enter '.' to retain the old name]"<<endl;
                            cin.ignore();
                            cin.getline(f.airline_name,sizeof(f.airline_name));
                            if(strcmp(f.airline_name,".")!=0)
                            {
                                file2.write((char*)&f,sizeof(f));
                            }
                            };break;
                    case 3:{
                            cout<<"ENTER THE START OF PLACE [enter '.' to retain the old name]"<<endl;
                            cin.ignore();
                            cin.getline(f.from,sizeof(f.from));
                            if(strcmp(f.from,".")!=0)
                            {
                                file2.write((char*)&f,sizeof(f));
                            }
                            };break;
                    case 4:{
                            cout<<"ENTER THE DROP OF PLACE[enter '.' to retain the old name]"<<endl;
                            cin.ignore();
                            cin.getline(f.to,sizeof(f.to));
                            if(strcmp(f.to,".")!=0)
                                {
                                    file2.write((char*)&f,sizeof(f));
                                }
                            };break;
                    case 5:{cout<<"THE NUMBER OF DEPART TIME TO BE GIVEN"<<f.number<<endl;
                            cout<<"ENTER THE NEW DEPART TIME[enter '.' to retain the old time]"<<endl;
                            for(int i=0;i<f.number;i++)
                            {
                                cin>>f.depart_time[i];
                                if(strcmp(f.depart_time[i],".")==0)
                                     cout<<"****old one retained****"<<endl;
                                else
                                {
                                    file2.write((char*)&f,sizeof(f));
                                }
                            }
                            };break;
                    case 6:{
                            cout<<"ENTER THE NEW NUMBER OF ECONOMIC SEATS AVAILABLE[enter -1 to retain old one]"<<endl;
                            cin>>f.e_seat;
                            if(f.e_seat==-1)
                                cout<<"****old one retained****"<<endl;
                            else
                            {
                                file2.write((char*)&f,sizeof(f));
                            }
                            };break;
                    case 7:{
                            cout<<"ENTER THE NEW NUMBER OF BUSINESS SEATS AVAILABLE[enter -1 o retain old one]"<<endl;
                            cin>>f.b_seat;
                            if(f.b_seat==-1)
                                cout<<"****old one retained****"<<endl;
                            else
                            {
                                file2.write((char*)&f,sizeof(f));
                            }
                            } ;break;
                    default:cout<<"NOT VALID OPTION"<<endl;break;
                }
                cout<<"WHETHER YOU WANNA MODIFY ANY FURTHER DETAIL RECORD?[if yes ,enter y]"<<endl;
                cin>>choice;
            }
        }
        file2.read((char*)&f,sizeof(f));
    }
    if(found=='n')
    {

        cout<<"RECORD NOT FOUND"<<endl;
    }
    file2.close();
}
void flight::full_detail()
{
    flight f;
    ifstream obj;
    obj.open("plane.txt",ios::in);
    obj.read((char*)&f,sizeof(f));
    if(!obj)
    {
        cout<<"FILE NOT FOUND"<<endl;
    }
    while(!obj.eof())
    {
        f.get_flight_info();
        obj.read((char*)&f,sizeof(f));
   }
   obj.close();
}
void flight::choose_seat(int flno,string type)
{
    flight f;
    fstream pla("plane.txt");
    pla.read((char*)&f,sizeof(f));
    if(!pla)
    {
        cout<<"FILE NOT FOUND"<<endl;
    }
    while(!pla.eof())
    {
        if(f.fl_no==flno)
        {
            if(strcmp(type,"b")==0)
            {
                f.b_seat=f.b_seat-1;
            }
            else if(strcmp(type,"e")==0)
            {
                f.e_seat=f.e_seat-1;
            }
            pla.write((char*)&f,sizeof(f));
            break;
        }
        pla.read((char*)&f,sizeof(f));
    }
    pla.close();
}

