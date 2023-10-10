#include "menu.h"
#include <iostream>
using namespace std;
void Menu::admin_menu()
{
    int option;char temp;
    do
    {
        cout<<">>>>>>>>>>>>>>>>>>AIRLINE RESERVATION SYSTEM<<<<<<<<<<<<<<<<<<"<<endl;
        cout<<"1] ADD NEW FLIGHT DETAILS"<<endl<<endl;
        cout<<"2] DELETE FLIGHT DETAILS"<<endl<<endl;
        cout<<"3] DISPLAY FLIGHT DETAILS "<<endl<<endl;
        cout<<"4] DISPLAY DETAILS OF PASSANGER IN SCHEDULED FLIGHT"<<endl<<endl;
        cout<<"5] DISPLAY A PASSANGER INFO"<<endl<<endl;;
        cout<<"6] MODIFY FLIGHT DETAILS"<<endl<<endl;
        cout<<"7] CREATE BRAND NEW FLIGHT RECORD"<<endl<<endl;
        cout<<"enter your choice"<<endl<<endl;
        cin>>option;
        admin_select(option);
        cout<<"****Do you wanna see another record****"<<endl;
        cout<<"yes means enter y "<<endl;
        cin>>temp;
    }while(temp=='y');
}
void Menu::pass_menu()
{
    int option;
    char temp;
    do
    {
        cout<<">>>>>>>>>>>>>>>>>AIRLINE RESERVATION SYSTEM<<<<<<<<<<<<<<<"<<endl;
        cout<<endl;
        cout<<"1] MODIFY YOUR PERSONAL DETAILS"<<endl;
        cout<<endl;
        cout<<"2] DISPLAY FLIGHTS AVAILABLE (**as u do ,book reservation to get a seat reserved for u**)"<<endl;
        cout<<endl;
        cout<<"3] BOOK YOUR RESERVATION[ticket]"<<endl;
        cout<<endl;
        cout<<"4] CANCEL YOUR RESERVATION[ticket]"<<endl;
        cout<<endl;
        cout<<"5] DISPLAY YOUR BOOKING STATUS[ticket]"<<endl;
        cout<<endl;
        cout<<"6] DISPLAY PERSONAL DETAILS"<<endl;
        cout<<endl;
        cout<<">>>>Enter your choice>>>>"<<endl;
        cin>>option;
        pass_select(option);
        cout<<"****Do you wanna continue your booking****"<<endl;
        cout<<"enter y if u wanna do so"<<endl;
        cin>>temp;
    }while(temp=='y');
}
void Menu::admin_select(int choice)
{
    flight f;
    passanger p;
    scheduled_flight s;
    switch(choice)
    {
        case 1:f.add_flight();break;
        case 2:f.delete_flight();break;
        case 3:f.display_flight();break;
        case 4:s.check_pass();break;
        case 5:p.display();break;
        case 6:f.mod_flight();break;
        case 7:f.write();break;
        default:cout<<"***SORRY , INVALID CHOICE***"<<endl;
    }
}
void Menu::pass_select(int choice)
{
    flight f;
    passanger p;
    book_status b;
    switch(choice)
    {
        case 1:p.modify();break;
        case 2:f.full_detail();break;
        case 3:b.book_ticket();break;
        case 4:b.cancel_reservation();break;
        case 5:b.display_status();break;
        case 6:p.display();break;
        default:cout<<"***SORRY, INVALID CHOICE***"<<endl;
    }
}
