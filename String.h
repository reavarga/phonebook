#ifndef NHF2_STRING_H
#define NHF2_STRING_H

#include <iostream>

class String {

    char *pData;
    size_t len; //hossz lezaro nulla nelkul
public:
    String();
    ~String ();
    //void setsize(size_t size);
    size_t size() const;
    const char* c_str() const;
    //String (const char& c);
    String(const char *str);
    String (const String& str);
    String& operator=(const String& str);
    //String& operator=(const char* str);
    //String operator+(const String& str)const;
    String& operator+(char c);
    char& operator[](size_t idx);


    static std::istream &getline(std::istream &is, String &s, char div);
};

//String operator+(char c, String& str);
std::ostream& operator<<(std::ostream& os, const String& s);
std::istream& operator>>(std::istream& is, String&s);


#endif //NHF2_STRING_H
