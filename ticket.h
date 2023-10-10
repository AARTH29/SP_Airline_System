#ifndef ticket_h
#define ticket_h
#include "passanger.h"
#include <string>
class ticket
{
    private:
    int res_no;
    char board_place[50],destin_place[50];
    passanger p1;
public:
    void set_ticket();
    void get_ticket(int num,char name[10]);
    void book_ticket();
    void display_ticket();
    void del_res(int c);
};
#endif

