#include "Database.h"
#include <fstream>
#include <string>
#include <iostream>
#include "../utils/Utils.h"

void Database::loadUserData() {
    std::ifstream file(USERS_FILE);
    std::string row;

    if(!file.is_open()) {
        //Log
        std::cout << "User file not open." << std::endl;
        return;
    }

    users.clear();

    while(std::getline(file, row)) {

        if(row.empty()) {
            //Log
            std::cout << "Skipping empty row" << std::endl;
            continue;
        }

        //Log
        std:: cout << "ROW:" << row << std::endl;

        std::vector<std::string> data = Utils::splitRow(row, DB_DELIMITER);

        //TODO: fix warnings
        if (data.size() < 3) {
            std::cout << "Warning: Skipping corrupted database row: " << row << std::endl;
            continue; 
        }

        std::string id = data[0];
        std::string username = data[1];
        std::string password = data[2];

        if(!id.empty() && !username.empty() && !password.empty()) {
            users.push_back(User(id, username, password)); 
        }
    }
    file.close();
}

void Database::loadPostData() {
    std::ifstream file(POSTS_FILE);
    std::string row;

    if(!file.is_open()) return;

    posts.clear();

    while(std::getline(file, row)) {

        if(row.empty()) continue;

        std::vector<std::string> data = Utils::splitRow(row, DB_DELIMITER);

        //TODO: fix warnings
        if (data.size() < 4) {
            std::cout << "Warning: Skipping corrupted database row: " << row << std::endl;
            continue; 
        }

        std::string id = data[0];
        std::string userId = data[1];
        std::string title = data[2];
        std::string content = data[3];

        if(!id.empty() && !userId.empty() && !title.empty() && !content.empty()) {
            posts.push_back(Post(id, userId, title, content)); 
        }
    }
    file.close();
}