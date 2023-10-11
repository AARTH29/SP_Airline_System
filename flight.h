#ifndef flight_h
#define flight_h
#include <string>
class flight
{
    private:
        int fl_no;
        int e_seat;
        int b_seat;
        int booked_seats;
        int number;
        vector<vector<string>>arr_time
        vector<vector<string>>depart_time;
        string from;
        string to;
        string airline_name;
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

