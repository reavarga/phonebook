#include "Human.h"
#include "fstream"
#include "exception"
#include <iostream>
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

Human::Human(const String &name, const String &number, const String &nickname, const String &birthday, const String &email, const String &comment)
        : Record(name, number,email, comment), nickname(nickname), birthday(birthday){}
Human::~Human(){}
void Human::print(std::ostream &os) const{
    os<<"Name: "<< this->name<<'\n'<<"Number: "<<this->number<< '\n'<<
             "Email: "<<this->email<<'\n'<<"Birthday: "<<this->birthday<<'\n'<<"Nickname: "<<this->nickname
             <<'\n'<<"Comment: "<<this->comment<<std::endl;
}

void Human::save() const {
    std::ofstream out;
    out.open("human.txt", std::ofstream::app);
    if(out.bad()){
        throw std::bad_exception();
    }
    out<<this->name<<';'<<this->number<<';'<<this->nickname<<';'<<this->birthday<<';'<<this->email<<';'<<this->comment<<';'<<std::endl;
    out.close();
}

void Human::setBirthday(const String& birthday){
    this->birthday=birthday;
}

void Human::setNickname(const String &nickname) {
    this->nickname=nickname;
}

Human::Human(const Human &human) : Record(human), nickname(human.nickname), birthday(human.birthday){}
