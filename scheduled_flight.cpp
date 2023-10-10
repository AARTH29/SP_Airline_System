
#include "scheduled_flight.h"
#include <iostream>
using namespace std;
void scheduled_flight::check_pass()
{
    cout<<"ENTER THE FLIGHT NUMBER TO BE CHECKED"<<endl;
    cin>>flno;
    cout<<"ENTER THE FLIGHT TYPE TO BE CHECKED"<<endl;
    cin>>fltype;
    cout<<"ENTER THE DEPSRTURE TIME TO BE CHECKED"<<endl;
    cin>>dep;
    p2.pass(flno,dep,fltype);
}
