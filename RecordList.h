#ifndef NHF2_RECORDLIST_H
#define NHF2_RECORDLIST_H

#include <cstddef>
#include "Record.h"
#include "String.h"

enum Type{
    human, company
};

class RecordList{
private:
    struct ListElement {
        Record* record;
        Type type;
        ListElement* next;
        ~ListElement();
    };
    ListElement* first;
    ListElement* last;
public:
    class iterator{
    private:
        ListElement* element;
    public:
        iterator(ListElement* element = NULL);
        iterator& operator++();
        iterator operator++(int);
        Record*& operator*() const;
        Record* operator->() const;
        bool operator==(iterator rhs) const;
        bool operator!=(iterator rhs) const;
    };
    class const_iterator{
    private:
        ListElement* element;
    public:
        const_iterator(ListElement* element = NULL);
        const_iterator& operator++();
        const_iterator operator++(int);
        Record* const& operator*() const;
        Record* const& operator->() const;

        bool operator==(const_iterator rhs) const;
        bool operator!=(const_iterator rhs) const;
    };
    iterator begin(); //visszaadja a lista elejet
    iterator end(); //visszaadja a lista veget
    const_iterator begin() const; //visszaadja a lista elejet
    const_iterator end() const; //visszaadja a lista veget

    RecordList();
    RecordList(const RecordList& rec);
    void add(Record *rec, Type type); //uj record felvetele
    bool remove(const String& nev); //egy record torlese
    RecordList search(const String &name) const; //record kereses nev alapjan
    RecordList searchByNumber(const String& num) const; //record kereses szam alapjan
    bool configure();
    void save() const; //mentes fajlba
    Record * modify(const String& name);// record valtoztatasa
    Type type(const String& name);
    void print(std::ostream& os=std::cout) const;
    RecordList& operator=(const RecordList& rsh);
        //bool close();
    ~RecordList();

};

#endif //NHF2_RECORDLIST_H
