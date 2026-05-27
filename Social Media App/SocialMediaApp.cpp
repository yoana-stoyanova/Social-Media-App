#include <iostream>
#include "./database/Database.h"

int main()
{
    std:: cout << "start" << std::endl;

    Database db = Database();
    db.loadUserData();

    std::cout << db.users[0].getUsername() << "-" <<db.users[0].getId()<<"-"<<db.users[0].getPassword();

    db.users.push_back(User{"0-0-0", "Pesho", "pass000"});

    db.saveUserData();
}
