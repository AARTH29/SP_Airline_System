#ifndef passanger_h
#define passanger_h
#include <string>
#include"flight.h"
class passanger
{
protected:
    flight f;
    string pname;
    string surname;
    string nationality;
    string email_id;
    string airline_type;
    string board_time;
    string type_seat;
    int passport_no;
    int tele_no;
    int age;
    int plane_no;
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


