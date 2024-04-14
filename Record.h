//
// Created by Rea on 2024. 03. 30..
//


#ifndef NHF2_RECORD_H
#define NHF2_RECORD_H

#include "String.h"
class Record{
protected:
    String name;
public:
    Record(String& name);
    //Record(const Record& r);
    virtual ~Record(){};
    virtual void print() const=0;
    String& getName();
};

#endif //NHF2_RECORD_H
