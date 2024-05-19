
#ifndef NHF2_HUMAN_H
#define NHF2_HUMAN_H
#include "Record.h"

class Human: public Record {
protected:
    String nickname;
    String birthday;
public:
    Human(String &name, String &number, String &nickname, String &birthday, String &email, String &comment);
    ~Human();
    void print() const override;
    void save() const override;
    void setNickName(const String& nickname);
    void setbirthday(const String& birthday);
    void modify() override;



};


#endif //NHF2_HUMAN_H
