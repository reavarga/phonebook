#include <iostream>
void CreateNumberMenu();
void menu(){
    std::cout<<"Welcome to your phonebook. Please choose from the following:"<<std::endl;
    std::cout<<"1.New phone number."<<'\n'<<"2.Search a number."<<'\n'<<"3. Delete number."<<'\n'<<"4.List numbers"
    <<'\n'<<"5.Modify number."<<'\n'<<"6.Exit."<<std::endl;
    int i;
    std::cin>>i;
    if(i<1|| i>=7) {std::cout<<"No matching task. try again."<<std::endl; std::cin>>i;}
    switch(i){
        case 1: CreateNumberMenu();
            break;
        case 2: std::cout<<"You can search for the number by Name or Company Name."<<std::endl;
        //ide search fgv
            break;
        case 3: std::cout<<"You can delete the number by typing the Name or Company Name."<<std::endl;
        //ide delete fgv
            break;
        case 4: std::cout<<"You can list numbers by typing three digits from it or by Name or Company Name."<<std::endl;
            break;
        case 5: std::cout<<"You can modify a number by searching for Name or Company Name."<<std::endl;
            break;
        case 6: std::cout<<"Goodbye."<<std::endl;
        //mento es bezaro fgv
            break;

    }

}
void CreateNumberMenu() {
    std::cout << "PLease choose what kind of number you would like to add:" << '\n' <<
              "1.Personal number." << '\t' << "2.Company number." << std::endl;
    int i;
    std::cin >> i;
    if (i < 0 || i >= 3) {
        std::cout << "No matching task. try again." << std::endl;
        std::cin >> i;
    }
    if (i == 1)
    if(i==2);
    }


