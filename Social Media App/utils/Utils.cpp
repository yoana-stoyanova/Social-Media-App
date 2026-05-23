#include "Utils.h"
#include <random>

std::vector<std::string> Utils::splitRow(const std::string& row, char sep) {
    std::vector<std::string>  data;

    size_t start = 0;
    size_t end = row.find(sep);

    while(end != std::string::npos) {
        data.push_back(row.substr(start, end - start));
        start = end + 1;
        end = row.find(sep, start);
    }

    data.push_back(row.substr(start));

    return data;
}

//TODO: check
std::string Utils::generateId() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, ID_CHARSET.length() - 1);

    std::string randomID = "";

    for(int i = 0; i < ID_LENGTH; i++) {
        randomID += ID_CHARSET[dis(gen)];
    }

    return randomID;
}