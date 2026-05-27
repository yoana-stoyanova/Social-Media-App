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

//UUID to ensure unique ids
std::string generateId() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 15);

        std::string randomId = "";

        for (int i = 0; i < 8; ++i) randomId += ID_CHARSET[dis(gen)];
        randomId += "-";

        for (int i = 0; i < 4; ++i) randomId += ID_CHARSET[dis(gen)];
        randomId += "-";

        for (int i = 0; i < 4; ++i) randomId += ID_CHARSET[dis(gen)];
        randomId += "-";

        for (int i = 0; i < 4; ++i) randomId += ID_CHARSET[dis(gen)];
        randomId += "-";

        for (int i = 0; i < 12; ++i) randomId += ID_CHARSET[dis(gen)];

        return randomId;
    }