//
// Created by zero6575 on 2024. 05. 18..
//

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
    }

    String name, number, email, comment;
    String nickname, birthday;
    String location, occupation, ceoname;

    char c=getchar();
    std::cout << "Name: ";
    String::getline(std::cin,name,'\n');
    std::cout << "Number: ";
    String::getline(std::cin,number,'\n');
    if (!phoneNumberCheck(number)) {
        std::cout << "Wrong format!";
        return;
    }

    switch (i) {
        case 1:
            std::cout << "Nickname: ";
            String::getline(std::cin,nickname,'\n');

            std::cout << "Birthday: ";
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

    std::cout << "Email: ";
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
        this->rec.add(hum);
    } else if (i == 2) {
        Company *com = new Company(name, number, email, location, occupation, ceoname, comment);
        if(com== nullptr){
            throw std::bad_alloc();
        }
        this->rec.add(com);
    }

    std::cout << "Added successfully!";
}

void Menu::menu() {
    bool run = true;
    while (run) {
        std::cout << "Welcome to your phonebook. Please choose from the following:" << std::endl;
        std::cout << "1.New phone number." << '\n' << "2.Search by number." << '\n' << "3.Search by name." << '\n'
                  << "4.Delete number." << '\n' << "5.List numbers"
                  << '\n' << "6.Modify number." << '\n' << "7.Exit." << std::endl;
        String temp;
        int i;
        std::cin >> i;
        switch (i) {
            case 1:
                CreateNumberMenu();

                break;

            case 2:
                std::cout << "Type some digits of the phone number." << std::endl;
                getchar();
                std::cin >> temp;
                this->rec.searchByNumber(temp);

                break;

            case 3:
                std::cout << "You can search for the name by Name or Company Name." << std::endl;
                getchar();
                std::cin >> temp;
                this->rec.search(temp);

                break;

            case 4:
                std::cout << "You can delete the number by typing the Name or Company Name." << std::endl;
                getchar();
                String::getline(std::cin,temp,'\n');
                this->rec.remove(temp);
                break;

            case 5:
                this->rec.search("");
                getchar();
                break;

            case 6:
                std::cout << "You can modify a number by searching for Name or Company Name." << std::endl;
                getchar();
                std::cin >> temp;
                this->rec.modify(temp);

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
    this->rec.configure("company.txt", "human.txt");
}
