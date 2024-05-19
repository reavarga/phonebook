//
// Created by zero6575 on 2024. 05. 18..
//

#ifndef NHF2_MENU_H
#define NHF2_MENU_H

#include <iostream>
#include "ListElement.h"

class Menu{
private:
    RecordList rec;

    void CreateNumberMenu();
public:
    Menu();
    void menu();
};


#endif //NHF2_MENU_H
