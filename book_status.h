#ifndef book_status_h
#define book_status_h
#include "ticket.h"
class book_status : public ticket
{
    public:
        void display_status();
        void cancel_reservation();
};
#endif



