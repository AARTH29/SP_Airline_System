#ifndef ticket_h
#define ticket_h
#include "passanger.h"
#include <string>
class ticket
{
    private:
    int res_no;
    string board_place;
    string destin_place;
    passanger p1;
public:
    void set_ticket();
    void get_ticket(int num,string name);
    void book_ticket();
    void display_ticket();
    void del_res(int c);
};
#endif

