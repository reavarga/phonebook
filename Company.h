
#ifndef NHF2_COMPANY_H
#define NHF2_COMPANY_H
#include "Record.h"


class Company:public Record {
protected:

 String number;
    String email;
    String location;
    String occupation;
    String ceoname;
    String comment;
public:
    Company(String &name, String &number, String &email, String &location, String &occupation, String &ceoname,
            String &comment);
    ~Company();
    void print();

};


#endif //NHF2_COMPANY_H
