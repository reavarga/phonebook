#include <iostream>
#include "String.h"
#include "ListElement.h"
#include "Human.h"
#include "Company.h"
#include "memtrace.h"


int main() {
    String name("Szusi");
    String name2("Szusi2");
    String name3("Alma");
    String name4("Korte");
    String number("30");
    String nickname("Macsek");
    String birthday("2003");
    String email("szus@asd.hu");
    String comment("");
    Record* uj= new Human(name, number, name, birthday, email, comment);
    Record* uj2= new Human(name2, number, name2, birthday, email, comment);
    Record* uj3= new Human(name3, number, name3, birthday, email, comment);
    Record* uj4= new Human(name4, number, name4, birthday, email, comment);

    RecordList list;



    list.add(uj);
    list.add(uj2);
    list.add(uj3);
    list.add(uj4);

    Record* rec;
    if((rec=list.search(name2))!=NULL) rec->print();
    else std::cout<<"nincs";


    list.remove(name4);
    list.remove(name3);
    list.remove(name2);
    //list.remove(name);


    return 0;
}
