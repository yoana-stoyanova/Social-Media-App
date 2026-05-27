#pragma once

#include <iostream>
#include <vector>
#include <string>

const std::string ID_CHARSET = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const size_t ID_LENGTH = 10;

class Utils {
public:
	static std::vector<std::string> splitRow(const std::string& row, char sep);
	static std::string concatRow(const std::vector<std::string>& data, char sep);

	static std::string generateId();

};