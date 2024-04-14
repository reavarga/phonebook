#include "String.h"
#include <cstring>
#include <iostream>

void String::printDbg(const char *txt) const {
    std::cout << txt << "[" << len << "], " << (pData ? pData : "(NULL)") << '|' << std::endl;
}
String::String(): len(0) {
    pData=new char[1];
    pData[0]='\0';
}

size_t String::size() const {
    return this->len;
}

const char *String::c_str() const {
    return this->pData;
}

String::~String() {
    delete[] this->pData;
}
void String::setsize(size_t size){
    this->len=size;
}

String:: String (char const& c){
    pData=new char [2];
    pData[0]=c;
    pData[1]='\0';
    len=1;
}

String::String(const char *str){
    this->len=strlen(str);
    pData=new char[len+1];
    strcpy(pData,str);
}

String::String (const String& str){
    size_t len=str.size();
    this->len=len;
    pData=new char[len+1];
    strcpy(this->pData,str.c_str());
}

String& String::operator=(const String& str){
    if(str.c_str()==this->pData);
    else {delete[] this->pData;
        this->len=str.size();
        pData=new char[this->len+1];
        strcpy(pData,str.c_str());
    }
    return *this;
}

String String::operator+(const String& str)const{
    size_t ujlen=this->len+str.size()+1;
    char *uj=new char[ujlen];
    strcpy(uj,this->pData);
    strcat(uj,str.c_str());
    String ujstring(uj);
    delete []uj;
    return ujstring;
}

String& String:: operator+(char c){
    char*uj=new char[this->len+2];
    strcpy(uj,this->pData);
    uj[this->len]=c;
    uj[this->len+1]='\0';
    delete[] this->pData;
    pData=uj;
    this->len=this->len+1;
    return *this;
}

char& String::operator[](size_t idx){
    if(idx<0 || idx>this->len-1){
        throw "Index hiba";
    }
    return pData[idx];

}

String operator+(char c, String& str){
    char *uj=new char[str.size()+2];
    uj[0]=c;
    for(size_t i=1; i<str.size()+1;i++){
        uj[i]=str.c_str()[i-1];
    }
    uj[str.size()+1]='\0';
    String ujstr(uj);
    delete[]uj;
    return ujstr;
}
std::istream& String::getline(std::istream& is, String& s, char div){
    s=String();
    int uj;
    while( (uj=is.get())!=is.eof() && (char)uj!=div){
        s=s+ ((char)uj);
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const String& s){
    for(size_t i=0; i<s.size();i++){
        os<<s.c_str()[i];
    }
    return os;}

std::istream& operator>>(std::istream& is, String&s){
    int uj;
    size_t size=0;
    char*ujstr=new char[1];
    ujstr[0]='\0';
    while( (uj=is.get())!=is.eof() && !std::isspace(uj)  ){
        char *temp=new char[size+2];
        strcpy(temp,ujstr);
        temp[size]=uj;
        temp[size+1]='\0';
        size++;
        delete[] ujstr;
        ujstr=temp;
    }
    s=String(ujstr);
    delete[] ujstr;
    return is;
}

