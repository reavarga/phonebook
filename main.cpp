#include <iostream>
#include "String.h"
#include "ListElement.h"
#include "Human.h"
#include "Company.h"
#include "menu.h"

//#define MEMTRACE
#include "memtrace.h"


int main() {

    Menu menu;

    try{
        menu.menu();
    }
    catch(const std::exception& e){
        std::cout<<"Error with memory"<<std::endl;
    }

    return 0;
}
