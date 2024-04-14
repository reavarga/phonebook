#include "String.h"
#include "Record.h"
String& Record::getName(){
    return this->name;
}

Record::Record(String &name) :name(name){}
