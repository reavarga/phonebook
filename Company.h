
#ifndef NHF2_COMPANY_H
#define NHF2_COMPANY_H
#include "Record.h"


class Company:public Record {
protected:

    String location;
    String occupation;
    String ceoname;
public:
    Company(String &name, String &number, String &email, String &location, String &occupation, String &ceoname,
            String &comment);
    ~Company();
    void print() const override;
    void save() const override;
    void modify() override;
    void setLocation(const String& location);
    void setOccupation(const String& occupation);
    void setCeoname(const String& ceoname);
};


#endif //NHF2_COMPANY_H
