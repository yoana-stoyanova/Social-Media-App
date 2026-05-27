#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Post.h"
#include "ThumbsUp.h"
#include "Comment.h"

class User {
private:
	std::string id;

	std::string username;
	std::string password;

public:
	User(std::string username, std::string password);
	User(std::string id, std::string username, std::string password);

	const std::string getId() const {
		return id;
	}

	const std::string getUsername() const {
		return username; 
	}

	const std::string getPassword() const {
		return password; 
	}
};

