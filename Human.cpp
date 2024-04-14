//
// Created by Rea on 2024. 03. 30..
//

#include "Human.h"
Human::Human(String &name, String &number, String &nickname, String &birthday, String &email, String &comment)
        : Record(name), number(number), nickname(nickname), birthday(birthday), email(email), comment(comment) {}
Human::~Human(){}
void Human::print() const{
    std::cout<<"Name: "<< this->name<<'\n'<<"Number: "<<this->number<< '\n'<<
             "Email: "<<this->email<<'\n'<<"Birthday: "<<this->birthday<<'\n'<<"Nickname: "<<this->nickname
             <<'\n'<<"Comment: "<<this->comment<<std::endl;
}