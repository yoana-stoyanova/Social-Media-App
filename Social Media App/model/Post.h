#pragma once
#include <iostream>
#include <vector>

#include "ThumbsUp.h"
#include "Comment.h"

class Post {
private:
	std::string id;
	std::string userId;

	std::string title;
	std::string content;

public:
    Post(std::string userId, std::string title, std::string content);
    Post(std::string id, std::string userId, std::string title, std::string content);

    std::string getId() const {
        return id;
    }

    std::string getUserId() const {
        return userId;
    }
    std::string getTitle() const {
        return title;
    }

    std::string getContent() const {
        return content;
    }
};
