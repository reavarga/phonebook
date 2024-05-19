//
// Created by Rea on 2024. 03. 30..
//


#ifndef NHF2_RECORD_H
#define NHF2_RECORD_H

#include "String.h"
class Record{
protected:
    String name;
    String number;
    String comment;
    String email;

public:
    Record(String& name, String& number, String& email, String& comment);
    //Record(const Record& r);
    virtual ~Record(){};
    virtual void print() const=0;
    virtual void save() const = 0;
    virtual void modify() =0;
    String getName() const;
    String getNumber() const;
    void setName(const String& name);
    void setNumber(const String& number);
    void setEmail(const String& email);
    void setComment(const String& comment);
};

#endif //NHF2_RECORD_H
