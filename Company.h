#ifndef NHF2_COMPANY_H
#define NHF2_COMPANY_H
#include "Record.h"


class Company:public Record {
protected:

    String location;
    String occupation;
    String ceoname;
public:
    Company(const String &name, const String &number, const String &email, const String &location, const String &occupation, const String &ceoname,
            const String &comment);
    ~Company();
    Company(const Company& company);
    void print(std::ostream &os=std::cout) const override;
    void save() const override;
    void setLocation(const String& location);
    void setOccupation(const String& occupation);
    void setCeoname(const String& ceoname);

};


#endif //NHF2_COMPANY_H
