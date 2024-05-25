#ifndef NHF2_RECORD_H
#define NHF2_RECORD_H

#include "String.h"
class Record{
protected:
    String name;
    String number;
    String email;
    String comment;

public:
    Record(const String &name, const String &number, const String &email, const String &comment);
    virtual ~Record(){};
    Record(const Record& record);
    virtual void print(std::ostream &os=std::cout) const=0;
    virtual void save() const = 0;
    String getName() const;
    String getNumber() const;
    void setName(const String& name);
    void setNumber(const String& number);
    void setEmail(const String& email);
    void setComment(const String& comment);


};

#endif //NHF2_RECORD_H
