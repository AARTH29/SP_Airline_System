#ifndef passanger_h
#define passanger_h
#include <string>
#include"flight.h"
class passanger
{
protected:
    flight f;
    char pname[50],surname[50],nationality[50],email_id[50],airline_type[50],board_time[50],type_seat[50];
    int passport_no,tele_no,age,plane_no;
public:
    void set_data();
    void get_data();
    void book_flight();
    void modify();
    void display();
    int check(int num,char name[]);
    void pass(int flno,char dep[10],char fltype[10]);
};
#endif


