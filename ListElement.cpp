//
// Created by Rea on 2024. 03. 31..
//

#include "ListElement.h"
#include <string.h>
#include <fstream>

RecordList::iterator RecordList::begin() {
    return RecordList::iterator(this->first);
}

RecordList::iterator RecordList::end() {
    return RecordList::iterator(this->last);
}

RecordList::RecordList() :first(NULL), last(NULL){}

void RecordList::add(Record *rec) {
    ListElement* element = new ListElement;
    element->record=rec;
    if(this->first==NULL){ //ha ures a lista
        element->next=NULL;
        this->first=this->last=element;
    }
    else if(strcmp( this->first->record->getName().c_str() , rec->getName().c_str())>0){ //ha elore kell berakni ;)
        element->next=this->first;
        this->first=element;
    }
    else if(strcmp(this->last->record->getName().c_str(), rec->getName().c_str())<0){ //ha hatra kell berakni :O
        element->next=NULL;
        this->last->next=element;
        this->last=element;
    }
    else{ //amugy
        RecordList::ListElement* mov=this->first;
        while(mov->next!=NULL && strcmp(mov->next->record->getName().c_str(), rec->getName().c_str())>0){
            mov=mov->next;
        }
        element->next=mov->next;
        mov->next=element;
    }
}

void RecordList::remove(String &nev) {
    if(this->first==NULL){ //ha ures a lista
        return;
    }else if(strcmp(this->first->record->getName().c_str(), nev.c_str())==0){ //ha az elso
        if(this->last==this->first){ //ha csak egy elem van a listaban
            delete this->first;
            this->last=this->first=NULL;
        }else{
            ListElement * tmp = this->first;
            this->first=this->first->next;
            delete tmp;
        }
    }
    else if(strcmp(this->last->record->getName().c_str(), nev.c_str())==0){ //ha az utolso
        RecordList::ListElement* mov=this->first;

        while(mov->next!=this->last){
            mov=mov->next;
        }
        delete mov->next;
        mov->next=NULL;
        this->last=mov;
    }
    else{ //amugy
        RecordList::ListElement* mov=this->first;

        while(mov!=NULL && strcmp(mov->next->record->getName().c_str(), nev.c_str())!=0){
            mov=mov->next;
        }
        if(mov!=NULL){
            RecordList::ListElement* tmp=mov->next;
            mov->next=mov->next->next;
            delete tmp;
        }
    }
}

RecordList::~RecordList() {
    ListElement * mov=this->first;
    while(mov!=NULL){
        ListElement * tmp = mov;
        mov=mov->next;
        delete tmp;
    }

}

Record *RecordList::search(String &name) const {
    RecordList::const_iterator iter=this->begin();
    while(iter!=this->end() && strcmp(name.c_str(), (*iter)->getName().c_str())!=0){
        ++iter;
    }
    if(iter==this->end()){
        return NULL;
    }else{
        return *iter;
    }
}

RecordList::const_iterator RecordList::begin() const {
    return RecordList::const_iterator(this->first);
}

RecordList::const_iterator RecordList::end() const {
    return RecordList::const_iterator(NULL);
}

bool RecordList::configure(const String &company, const String &human) {
    return false;
}


RecordList::iterator::iterator(RecordList::ListElement *element) :element(element) {}

RecordList::iterator &RecordList::iterator::operator++() {
    if(this->element!=NULL){
        this->element=this->element->next;
    }
    return *this;
}

RecordList::iterator RecordList::iterator::operator++(int) {
    RecordList::iterator copy=*this;
    ++(*this);
    return copy;
}

Record*& RecordList::iterator::operator*() const {
    return this->element->record;
}

bool RecordList::iterator::operator==(RecordList::iterator rhs) const {
    return this->element==rhs.element;
}

bool RecordList::iterator::operator!=(RecordList::iterator rhs) const {
    return this->element!=rhs.element;
}


RecordList::ListElement::~ListElement() {
    delete record;
}

RecordList::const_iterator &RecordList::const_iterator::operator++() {
    if(this->element!=NULL){
        this->element=this->element->next;
    }
    return *this;}

RecordList::const_iterator RecordList::const_iterator::operator++(int) {
    RecordList::const_iterator copy=*this;
    ++(*this);
    return copy;}

 Record* const& RecordList::const_iterator::operator*() const {
    return this->element->record;
}

bool RecordList::const_iterator::operator==(RecordList::const_iterator rhs) const {
    return this->element==rhs.element;
}

bool RecordList::const_iterator::operator!=(RecordList::const_iterator rhs) const {
    return this->element!=rhs.element;
}

RecordList::const_iterator::const_iterator(RecordList::ListElement *element) :element(element){}
