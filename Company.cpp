#include "Company.h"
#include <exception>
#include <fstream>
#include <string.h>


static bool emailCheck(String &email) {
    return (strchr(email.c_str(), '@') && strchr(email.c_str(), '.')) || email.size()==0;
}

static bool phoneNumberCheck(String &phoneNumber) {
    if (phoneNumber.size() != 10) {
        return false;
    }
    for (size_t i = 0; i < phoneNumber.size(); i++  ) {
        if (!std::isdigit(phoneNumber[i])) {
            return false;
        }
    }
    return true;
}

Company::Company(const String &name, const String &number, const String &email, const String &location, const String &occupation, const String &ceoname,
                 const String &comment) : Record(name, number, email, comment), location(location), occupation(occupation), ceoname(ceoname) {}
                 
Company::~Company(){}

void Company::print(std::ostream &os) const {
    os<<"Company name: "<<this->name<<'\n'<<"Number: "<<this->number<<"\n"
    "Company Email: "<<this->email<<'\n'<<"Location: "<<this->location<<'\n'<<"Occupation: "<<this->occupation
    <<'\n'<<"CEO: "<<this->ceoname<<'\n'<<"Comment: "<<this->comment<<std::endl;
}

void Company::save() const {
    std::ofstream out;
    out.open("company.txt", std::ofstream::app);
    if(out.bad()){
        throw std::bad_exception();
    }
    out<<this->name<<';'<<this->number<<';'<<this->email<<';'<<this->location<<';'<<this->occupation<<';'<<this->ceoname<<';'<<this->comment<<';'<<std::endl;
    out.close();

}

void Company::setLocation(const String &location) {
    this->location=location;
}

void Company::setOccupation(const String &occupation) {
    this->occupation=occupation;
}

void Company::setCeoname(const String &ceoname) {
    this->ceoname=ceoname;
}

Company::Company(const Company &company) : Record(company), ceoname(company.ceoname), location(company.location),occupation(company.occupation){}

