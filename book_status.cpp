#include "book_status.h"
#include <string>
#include <iostream>
using namespace std;
void book_status::display_status()
{
    int num;
    char name[10];
    cout<<"///*************STATUS OF YOUR BOOKING***************///"<<endl;
    cout<<"ENTER YOUR NAME"<<endl;
    cin.ignore();
    cin.getline(name,sizeof(name));
    cout<<"ENTER YOUR PASSPORT NUMBER"<<endl;
    cin>>num;
    cout<<"......DISPLAYING TICKET......"<<endl;
    get_ticket(num,name);
}
void book_status::cancel_reservation()
{
    char ch='n';
    int c;
    cout<<"ARE YOU SURE YOU WANNA DELETE YOUR TICKET"<<endl;
    cout<<"if yes enter y"<<endl;
    cin>>ch;
    if(ch=='y')
    {
        cout<<"ENTER YOUR RESERVTION NUMBER"<<endl;
        cin>>c;
        del_res(c);
    }
    else
    {
        cout<<"YOUR RESERVATION PREVAILS"<<endl;
    }
}


