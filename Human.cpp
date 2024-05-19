//
// Created by Rea on 2024. 03. 30..
//

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

Human::Human(String &name, String &number, String &nickname, String &birthday, String &email, String &comment)
        : Record(name, number,email, comment), nickname(nickname), birthday(birthday){}
Human::~Human(){}
void Human::print() const{
    std::cout<<"Name: "<< this->name<<'\n'<<"Number: "<<this->number<< '\n'<<
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

void Human::setNickName(const String &nickname) {
    this->nickname=nickname;
}

void Human::setbirthday(const String &birthday) {
    this->birthday=birthday;
}

void Human::modify() {
    String name, number, nickname, birthday, email, comment;
    std::cout<<"New name: ";
    std::cin>>name;

    std::cout<<"New number: ";
    std::cin>>number;

    if(!phoneNumberCheck(number)){
        std::cout<<"Wrong format!";
        getchar();
        return;
    }

    std::cout<<"New nickname: ";
    std::cin>>nickname;

    std::cout<<"New birthday: ";
    std::cin>>birthday;

    std::cout<<"New email: ";
    std::cin>>email;

    if(!emailCheck(email)){
        std::cout<<"Wrong format!";
        getchar();
        return;
    }

    std::cout<<"New comment: ";
    std::cin>>comment;

    if(name.size()!=0){
        this->name=name;
    }
    if(number.size()!=0){
        this->number=number;
    }
    if(nickname.size()!=0){
        this->nickname=nickname;
    }
    if(birthday.size()!=0){
        this->birthday=birthday;
    }
    if(email.size()!=0){
        this->email=email;
    }
    if(comment.size()!=0){
        this->comment=comment;
    }

}
