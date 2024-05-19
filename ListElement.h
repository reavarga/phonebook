#ifndef NHF2_LISTELEMENT_H
#define NHF2_LISTELEMENT_H

#include <cstddef>
#include "Record.h"
#include "String.h"


class RecordList{
private:
    struct ListElement {
        Record* record;
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
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    RecordList();
    void add(Record* rec);
    void remove(const String& nev);
    void search(const String &name) const;
    void searchByNumber(const String& num) const;
    bool configure(const String& company, const String& human);
    void save() const;
    void modify(const String& name);

        //bool close();
    ~RecordList();

};

#endif //NHF2_LISTELEMENT_H
