#include <iostream>
#include "menu.h"
using namespace std;

int main()
{
    char ch;
    Menu m;
    cout<<"/___________________________________________________/"<<endl;
    cout<<".....******WELCOME TO AIRLINE PORTAL******..."<<endl;
    cout<<"/____________________________________________________/"<<endl;
    cout<<"\n";
    cout<<"USER OR ADMIN"<<endl;
    cout<<"NOTE ->If you are admin enter a ,passanger enter p"<<endl;
    cin>>ch;
    if(ch=='a')
    {
        m.admin_menu();
    }
    else if(ch=='p')
    {
        m.pass_menu();
    }
    else
    {
        cout<<"***SORRY , INAVLID CHOICE**"<<endl;
    }
}
