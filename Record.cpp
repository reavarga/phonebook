#include "String.h"
#include "Record.h"
String Record::getName() const{
    return this->name;
}

String Record::getNumber() const{
    return this->number;
}

Record::Record(String &name, String& number, String& email, String& comment) :name(name), number(number),email(email), comment(comment){}

void Record::setName(const String &name) {
    this->name=name;
}

void Record::setNumber(const String &number) {
    this->number=number;
}

void Record::setEmail(const String &email) {
    this->email=email;
}

void Record::setComment(const String &comment) {
    this->comment=comment;
}
