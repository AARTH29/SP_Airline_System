#ifndef menu_h
#define menu_h
#include "flight.h"
#include "passanger.h"
#include "book_status.h"
#include "scheduled_flight.h"
class Menu
{
public:
    void admin_menu();
    void pass_menu();
    void admin_select(int choice);
    void pass_select(int choice);
};
#endif
