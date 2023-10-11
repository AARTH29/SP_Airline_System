#include "ticket.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;
std::default_random_engine generator;
std::uniform_int_distribution distribution(0, 49);
void ticket::set_ticket()
{
    cout<<"ENTER YOUR BOARDING PLACE"<<endl;
    cin.ignore();
    cin.getline(board_place,sizeof(board_place));
    cout<<"ENTER THE DESTINATION PLACE"<<endl;
    cin>>destin_place;
    int res_no = distribution(generator);
    cout<<"WAIT TILL YOUR TICKET IS BOOKED"<<endl;
    cout<<"YOUR RESERVATAION NUMBER IS"<<res_no<<endl;
}
void ticket::display_ticket()
{
    cout<<"BOARDING PLACE:"<<board_place<<endl;
    cout<<"DESTINATION:"<<destin_place<<endl;
    cout<<"RESERVATION NUMBER:"<<res_no<<endl;
}
void ticket::get_ticket(int num,string name)
{
    ticket t;
    ifstream st;
    st.open("ticket.txt",ios::in);
    st.read((char*)&t,sizeof(t));
    if(!st)
    {
        cout<<"FILE NOT FOUND"<<endl;
    }
    char found = 'n';
    int res = p1.check(num,name);
    while(!st.eof())
    {
        if(res==1)
        {
            found = 'f';
            cout<<"YES UR TICKET IS BOOKED"<<endl;
            p1.display();
            t.display_ticket();
            break;
        }
        st.read((char*)&t,sizeof(t));
    }
    if(found=='n')
    {
        cout<<"TICKET NOT FOUND"<<endl;
    }
    else
        cout<<"TICKET BOOKED SUCCESSFULLY"<<endl;
    st.close();
}
void ticket::book_ticket()
{
    ticket t;
    ofstream tick;
    tick.open("ticket.txt",ios::out);
    if(!tick)
    {
        cout<<"FILE CANNOT BE CREATED"<<endl;
    }
    p1.book_flight();
    t.set_ticket();
    tick.write((char*)&t,sizeof(t));
    tick.close();
}
void ticket::del_res(int c)
{
    ticket t;
    ifstream resn;
    ofstream file;
    resn.open("ticket.txt",ios::in);
    file.open("temp.txt",ios::out);
    resn.read((char*)&t,sizeof(t));
    char found='n';
    char option='y';
    if(!resn)
        cout<<"FILE NOT FOUND"<<endl;
    while(option=='y')
    {
        while(!resn.eof())
        {
            if(t.res_no==c)
            {
                found='f';
                file.write((char*)&t,sizeof(t));
                cout<<"your reservation cancellation is perfectly done"<<endl;
            }
            else
            {
                file.write((char*)&t,sizeof(t));
            }
            resn.read((char*)&t,sizeof(t));
        }
        if(found=='n')
            cout<<"TICKET RECORD NOT FOUND"<<endl;
        file.close();
        resn.close();
        remove("ticket.txt");
        rename("temp.txt","ticket.txt");
        cout<<"Do you want to delete any other reservation?[if yes enter y]"<<endl;
        cin>>option;
    }
}
