//
// Created by Rea on 2024. 03. 31..
//

#include "ListElement.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include "Company.h"
#include "Human.h"
#include <exception>

RecordList::iterator RecordList::begin() {
    return RecordList::iterator(this->first);
}

RecordList::iterator RecordList::end() {
    return RecordList::iterator(nullptr);
}

RecordList::RecordList() :first(nullptr), last(nullptr){}

void RecordList::add(Record *rec) {
    ListElement* element = new ListElement;
    if(element== nullptr){
        throw std::bad_alloc();
    }

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
        while(mov->next!=NULL && strcmp(mov->next->record->getName().c_str(), rec->getName().c_str())<0){
            mov=mov->next;
        }
        element->next=mov->next;
        mov->next=element;
    }
}

void RecordList::remove(const String &nev) {
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

        while(mov->next!=NULL && strcmp(mov->next->record->getName().c_str(), nev.c_str())!=0){
            mov=mov->next;
        }
        if(mov!=this->last){
            RecordList::ListElement* tmp=mov->next;
            mov->next=mov->next->next;
            delete tmp;
            std::cout<<"Successfully deleted!"<<std::endl;

        }else{
            std::cout<<"Not found!"<<std::endl;
            return;
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

void RecordList::search(const String &name) const {
    RecordList::const_iterator iter=this->begin();
    int num=1;
    while(iter!=this->end()){
        if(strstr(iter->getName().c_str(), name.c_str())!=nullptr){
            std::cout<<num<<":\n";
            num++;
            iter->print();
            std::cout<<std::endl;
        }
        ++iter;
    }
    if(num==1){
        std::cout<<"No matches found!"<<std::endl;
    }
}

void RecordList::searchByNumber(const String &num) const{
    RecordList::const_iterator iter=this->begin();
    int ind=1;
    while(iter!=this->end()){
        if(strstr(iter->getNumber().c_str(), num.c_str())!=nullptr){
            std::cout<<ind<<":\n";
            ind++;
            iter->print();
            std::cout<<std::endl;
        }
        ++iter;
    }

    if(ind==1){
        std::cout<<"No matches found!"<<std::endl;
    }
}

RecordList::const_iterator RecordList::begin() const {
    return RecordList::const_iterator(this->first);
}

RecordList::const_iterator RecordList::end() const {
    return RecordList::const_iterator(NULL);
}

bool RecordList::configure(const String &company, const String &human) {
    std::ifstream companyIn(company.c_str());
    std::ifstream humanIn(human.c_str());

    bool ret=companyIn.good() && humanIn.good();

    while(companyIn.good()){
        String name, number, email, location, occupation, ceoname,comment;
        String::getline(companyIn,name,';');
        String::getline(companyIn,number,';');
        String::getline(companyIn,email,';');
        String::getline(companyIn,location,';');
        String::getline(companyIn,occupation,';');
        String::getline(companyIn,ceoname,';');
        String::getline(companyIn,comment,';');
        char c=companyIn.get();
        if(c=='\r'){
            companyIn.get();
        }
        if(!companyIn.good()){
            break;
        }
        Company* comp=new Company(name, number, email, location, occupation,ceoname,comment);
        if(comp== nullptr){
            throw std::bad_alloc();
        }
        this->add(comp);
    }

    companyIn.close();

    while(humanIn.good()){
        String name, number,nickname, birthday,email, comment;
        String::getline(humanIn,name,';');
        String::getline(humanIn,number,';');
        String::getline(humanIn,nickname,';');
        String::getline(humanIn,birthday,';');
        String::getline(humanIn,email,';');
        String::getline(humanIn,comment,';');
        char c= humanIn.get();
        if(c=='\r'){
            companyIn.get();
        }
        if(!humanIn.good()){
            break;
        }
        Human* hum=new Human(name, number, nickname, birthday, email,comment);
        if(hum == nullptr){
            throw std::bad_alloc();
        }
        this->add(hum);
    }
    humanIn.close();

    //torolje a benne levo dolgokat
    std::ofstream delIn;
    delIn.open(human.c_str(), std::ofstream::trunc | std::ofstream::out);
    delIn.close();
    delIn.open(company.c_str(), std::fstream::trunc | std::ofstream::out);
    delIn.close();
    return ret;
}

void RecordList::save() const{
    for(RecordList::const_iterator it=this->begin();it!=this->end();++it){
        it->save();
    }
}

void RecordList::modify(const String &name) {
    RecordList::iterator iter=this->begin();
    while(iter!=this->end() && strcmp(name.c_str(), iter->getName().c_str())!=0){
        ++iter;
    }
    if(iter==this->end()){
        std::cout<<"Not found!"<<std::endl;
    }else{

        iter->modify();
    }
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

Record* RecordList::iterator::operator->() const{
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

Record* const& RecordList::const_iterator::operator->() const{
    return this->element->record;
}

bool RecordList::const_iterator::operator==(RecordList::const_iterator rhs) const {
    return this->element==rhs.element;
}

bool RecordList::const_iterator::operator!=(RecordList::const_iterator rhs) const {
    return this->element!=rhs.element;
}

RecordList::const_iterator::const_iterator(RecordList::ListElement *element) :element(element){}
