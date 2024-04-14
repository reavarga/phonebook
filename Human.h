
#ifndef NHF2_HUMAN_H
#define NHF2_HUMAN_H
#include "Record.h"

class Human: public Record {
protected:
    String number;
    String nickname;
    String birthday;
    String email;
    String comment;
public:
    Human(String &name, String &number, String &nickname, String &birthday, String &email, String &comment);
    ~Human();
    void print() const;





};


#endif //NHF2_HUMAN_H
