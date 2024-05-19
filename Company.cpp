
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
    for (size_t i = 0; i < phoneNumber.size(); i++) {
        if (!std::isdigit(phoneNumber[i])) {
            return false;
        }
    }
    return true;
}

Company::Company(String &name, String &number, String &email, String &location, String &occupation, String &ceoname,
                 String& comment) : Record(name, number,email,comment), location(location), occupation(occupation), ceoname(ceoname) {}
                 
Company::~Company(){}

void Company::print() const {
    std::cout<<"Company name: "<<this->name<<'\n'<<"Number: "<<this->number<<"\n"
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

void Company::modify() {
    String name, number, email, birthday, location, occupation, ceoname,comment;
    std::cout<<"New name: ";
    std::cin>>name;

    std::cout<<"New number: ";
    std::cin>>number;

    if(!phoneNumberCheck(number)){
        std::cout<<"Wrong format!";
        getchar();
        return;
    }

    std::cout<<"New email: ";
    std::cin>>email;

    if(!emailCheck(email)){
        std::cout<<"Wrong format!";
        getchar();
        return;
    }

    std::cout<<"New location: ";
    std::cin>>location;

    std::cout<<"New occupation: ";
    std::cin>>occupation;

    std::cout<<"New ceoname: ";
    std::cin>>ceoname;

    std::cout<<"New comment: ";
    std::cin>>comment;

    if(name.size()!=0){
        this->name=name;
    }
    if(number.size()!=0){
        this->number=number;
    }
    if(email.size()!=0){
        this->email=email;
    }
    if(location.size()!=0){
        this->location=location;
    }
    if(occupation.size()!=0){
        this->occupation=occupation;
    }
    if(ceoname.size()!=0){
        this->ceoname=ceoname;
    }
    if(comment.size()!=0){
        this->comment=comment;
    }


}

