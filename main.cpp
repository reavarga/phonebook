#include <iostream>
#include "Human.h"
#include "RecordList.h"
#include "menu.h"

//#define MEMTRACE
#include "memtrace.h"

#define TESTMODE

#ifdef TESTMODE
#include "gtest_lite.h"
#endif


int main() {

#ifdef TESTMODE
    RecordList list;
    TEST("van-e company.txt es human.txt", ){
        EXPECT_EQ(true, list.configure());
    }END
    TEST("nev szerinti kereses talalattal", ){
        RecordList temp=list.search("Alisa");
        RecordList::iterator iter=temp.begin();
        EXPECT_STREQ("Alisa", iter->getName().c_str());
    }END
    TEST("nev szerinti kereses talalattal", ){
            RecordList temp=list.search("asd");
            EXPECT_EQ(true, temp.begin()==temp.end());
    }END
    TEST("szam szerinti kereses talalattal", ){
            RecordList temp=list.searchByNumber("0855483312");
            RecordList::iterator iter=temp.begin();
            EXPECT_STREQ("0855483312", iter->getNumber().c_str());
        }END
    TEST("szam szerinti kereses talalattal", ){
            RecordList temp=list.searchByNumber("1119999991");
            EXPECT_EQ(true, temp.begin()==temp.end());
        }END
    TEST("torles talalattal", ){

            EXPECT_EQ(true, list.remove("Nick"));
        }END
    TEST("torles talalat nelkul", ){

            EXPECT_EQ(false, list.remove("asd"));
    }END
    TEST("modify talalattal", ){
        Record* mod=list.modify("Alisa");
        EXPECT_EQ(false, mod== nullptr);
    }END
    TEST("modify talalat nelkul", ){
            Record* mod=list.modify("asd");
            EXPECT_EQ(true, mod== nullptr);
    }END
    TEST("add", ){
            Human* mod=new Human("Nick","0966785534","the goat","2001.03.29","Nickthebest01@gmail.com","Need to pay back for drinks");
            EXPECT_NO_THROW(list.add(mod, Type::human));
    }END

    TEST("mentes", ){
        EXPECT_NO_THROW(list.save());
    }END

#endif

#ifndef TESTMODE

    try{
        Menu menu;
        menu.menu();
    }
    catch(const std::bad_alloc& e){
        std::cout<<"Error with memory!"<<std::endl;
    }
    catch(const std::bad_exception& e){
        std::cout<<"Could not create files to save to!"<<std::endl;
    }
#endif

    return 0;
}
