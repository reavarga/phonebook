
#include "Company.h"
Company::Company(String &name, String &number, String &email, String &location, String &occupation, String &ceoname,
                 String &comment) : Record(name), number(number), email(email), location(location), occupation(occupation), ceoname(ceoname) {};
Company::~Company(){};
void Company::print(){
    std::cout<<"Company name: "<<this->name<<'\t'<<"Number: "<<this->number<<
    "Company Email: "<<this->email<<'\t'<<"Location: "<<this->location<<'\t'<<"Occupation: "<<this->occupation
    <<'\t'<<"CEO: "<<this->ceoname<<'\t'<<"Comment: "<<this->comment<<std::endl;
}
