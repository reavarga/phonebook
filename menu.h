#ifndef NHF2_MENU_H
#define NHF2_MENU_H

#include <iostream>
#include "RecordList.h"

class Menu{
private:
    RecordList rec;

    void CreateNumberMenu();
public:
    Menu();
    void menu();
};


#endif //NHF2_MENU_H
