#ifndef NHF2_HUMAN_H
#define NHF2_HUMAN_H
#include "Record.h"

class Human: public Record {
protected:
    String nickname;
    String birthday;
public:
    Human(const String &name, const String &number, const String &nickname, const String &birthday, const String &email, const String &comment);
    ~Human();
    Human(const Human& human);
    void print(std::ostream &os=std::cout) const override;
    void save() const override;
    void setBirthday(const String& birthday);
    void setNickname(const String& nickname);


};


#endif //NHF2_HUMAN_H
