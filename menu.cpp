#include "menu.h"
#include "Human.h"
#include "Company.h"
#include "String.h"
#include <string.h>
#include <iostream>

static bool emailCheck(String &email) {
    return (strchr(email.c_str(), '@') && strchr(email.c_str(), '.')) || email.size()==0;
}

static bool phoneNumberCheck(String &phoneNumber) {
    if (phoneNumber.size() != 10) {
        return false;
    }
    for (size_t i = 0; i < phoneNumber.size(); i++) {
        if (!std::isdigit(phoneNumber[i])) {
            return false;
        }
    }
    return true;
}

void Menu::CreateNumberMenu() {
    std::cout << "PLease choose what kind of number you would like to add:" << '\n' <<
              "1.Personal number." << '\t' << "2.Company number." << std::endl;
    int i;
    std::cin >> i;
    if (i < 0 || i >= 3) {
        std::cout << "No matching task. try again." << std::endl;
        return;
    }

    String name, number, email, comment;
    String nickname, birthday;
    String location, occupation, ceoname;

    getchar();
    std::cout << "Name: ";
    String::getline(std::cin,name,'\n');
    std::cout << "Number(10 digits): ";
    String::getline(std::cin,number,'\n');
    if (!phoneNumberCheck(number)) {
        std::cout << "Wrong format!";
        return;
    }

    switch (i) {
        case 1:
            std::cout << "Nickname: ";
            String::getline(std::cin,nickname,'\n');

            std::cout << "Birthday(yyyy.mm.dd): ";
            String::getline(std::cin,birthday,'\n');
            break;
        case 2:
            std::cout << "Location: ";
            String::getline(std::cin,location,'\n');

            std::cout << "Occupation: ";
            String::getline(std::cin,occupation,'\n');

            std::cout << "Ceo name: ";
            String::getline(std::cin,ceoname,'\n');

            break;
        default:
            std::cout << "Wrong option!" << std::endl;
            return;
            break;
    }

    std::cout << "Email (local-part@domain.tld): ";
    String::getline(std::cin,email,'\n');
    if (!emailCheck(email)) {
        std::cout << "Wrong format!";
        return;
    }

    std::cout << "Comment: ";
    String::getline(std::cin,comment,'\n');

    if (i == 1) {
        Human *hum = new Human(name, number, nickname, birthday, email, comment);
        if(hum== nullptr){
            throw std::bad_alloc();
        }
        this->rec.add(hum, human);
    } else if (i == 2) {
        Company *com = new Company(name, number, email, location, occupation, ceoname, comment);
        if(com== nullptr){
            throw std::bad_alloc();
        }
        this->rec.add(com, company);
    }

    std::cout << "Added successfully!";
}

void Menu::menu() {
    bool run = true;
    while (run) {
        std::cout << "Welcome to your phonebook. Please choose from the following:" << std::endl;
        std::cout << "1.New phone number." << '\n' << "2.Search by number." << '\n' << "3.Search by name." << '\n'
                  << "4.Delete number." << '\n' << "5.List numbers."
                  << '\n' << "6.Modify number." << '\n' << "7.Exit." << std::endl;
        String temp;
        String name, number, nickname, birthday, email, comment, location, occupation, ceoname;
        Record* tmp;
        Human* human;
        Company* company;
        int i;
        bool succ;
        std::cin >> i;
        switch (i) {
            case 1:
                CreateNumberMenu();

                break;

            case 2:
                std::cout << "Type some digits of the phone number." << std::endl;
                getchar();
                std::cin >> temp;
                this->rec.searchByNumber(temp).print(std::cout);
                break;

            case 3:
                std::cout << "You can search for the name by Name or Company Name." << std::endl;
                getchar();
                String::getline(std::cin, temp,'\n');
                this->rec.search(temp).print(std::cout);
                break;

            case 4:
                std::cout << "You can delete the number by typing the Name or Company Name." << std::endl;
                getchar();
                String::getline(std::cin,temp,'\n');
                succ=this->rec.remove(temp);
                if(succ){
                    std::cout<<"Removed successfully!"<<std::endl;
                }else{
                    std::cout<<"Not found!"<<std::endl;
                }
                break;

            case 5:
                this->rec.print(std::cout);
                getchar();
                break;

            case 6:
                std::cout << "You can modify a number by searching for Name or Company Name." << std::endl;
                getchar();
                String::getline(std::cin, temp, '\n');
                tmp=this->rec.modify(temp);
                if(!tmp){
                    std::cout<<"Not found!"<<std::endl;
                }else{
                    switch (this->rec.type(temp)) {
                        case Type::human:
                            human=dynamic_cast<Human*>(tmp);
                            std::cout<<"New name: ";
                            String::getline(std::cin, name, '\n');

                            std::cout<<"New number: ";
                            std::cin>>number;

                            if(!phoneNumberCheck(number) && number.size()!=0){
                                std::cout<<"Wrong format!";
                                getchar();
                                break;
                            }

                            std::cout<<"New nickname: ";
                            String::getline(std::cin, nickname, '\n');

                            std::cout<<"New birthday: ";
                            std::cin>>birthday;

                            std::cout<<"New email: ";
                            std::cin>>email;

                            if(!emailCheck(email) && email.size()!=0){
                                std::cout<<"Wrong format!";
                                getchar();
                                break;
                            }

                            std::cout<<"New comment: ";
                            String::getline(std::cin, comment, '\n');

                            if(name.size()!=0){
                                human->setName(name);
                            }
                            if(number.size()!=0){
                                human->setNumber(number);
                            }
                            if(nickname.size()!=0){
                                human->setNickname(nickname);
                            }
                            if(birthday.size()!=0){
                                human->setBirthday(birthday);
                            }
                            if(email.size()!=0){
                                human->setEmail(email);
                            }
                            if(comment.size()!=0){
                                human->setComment(comment);
                            }
                            break;
                        case Type::company:
                            company=dynamic_cast<Company*>(tmp);
                            std::cout<<"New name: ";
                            String::getline(std::cin, name, '\n');

                            std::cout<<"New number: ";
                            std::cin>>number;

                            if(!phoneNumberCheck(number) && number.size()!=0){
                                std::cout<<"Wrong format!";
                                getchar();
                                break;
                            }

                            std::cout<<"New email: ";
                            std::cin>>email;

                            if(!emailCheck(email) && email.size()!=0){
                                std::cout<<"Wrong format!";
                                getchar();
                                break;
                            }

                            std::cout<<"New location: ";
                            String::getline(std::cin, location, '\n');

                            std::cout<<"New occupation: ";
                            String::getline(std::cin, occupation, '\n');

                            std::cout<<"New ceoname: ";
                            String::getline(std::cin, ceoname, '\n');

                            std::cout<<"New comment: ";
                            String::getline(std::cin, comment, '\n');

                            if(name.size()!=0){
                                company->setName(name);
                            }
                            if(number.size()!=0){
                                company->setNumber(number);
                            }
                            if(email.size()!=0){
                                company->setEmail(email);
                            }
                            if(location.size()!=0){
                                company->setLocation(location);
                            }
                            if(occupation.size()!=0){
                                company->setOccupation(occupation);
                            }
                            if(ceoname.size()!=0){
                                company->setCeoname(ceoname);
                            }
                            if(comment.size()!=0){
                                company->setComment(comment);
                            }
                            break;
                        default:
                            break;
                    }
                    std::cout<<"Successfully modified!"<<std::endl;
                }
                break;

            case 7:
                std::cout << "Goodbye." << std::endl;
                run = false;
                this->rec.save();

                break;

            default:
                std::cout << "No matching task. Try again." << std::endl;

                break;

        }
        getchar();
    }


}

Menu::Menu() {
    this->rec.configure();
}
