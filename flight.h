#ifndef flight_h
#define flight_h
#include <string>
class flight
{
    private:
        int fl_no,e_seat,b_seat,booked_seats,number;
        char arr_time[10][10],depart_time[10][10];
        char from[50],to[50];
        char airline_name[50];
    public:
        void set_flight_info();
        void get_flight_info();
        void write();
        void add_flight();
        void delete_flight();
        void display_flight();
        void full_detail();
        void mod_flight();
        void depart(int flno);
        void choose_seat(int flno,char type[]);
};
#endif

