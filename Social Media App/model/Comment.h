#pragma once
#include <iostream>

class Comment {
private:
	std::string id;

	std::string userId;
	std::string postId;

	std::string content;

public:
    Comment(std::string userId, std::string postId, std::string content);
    Comment(std::string id, std::string userId, std::string postId, std::string content);

    std::string getId() const {
        return id;
    }

    std::string getUserId() const {
        return userId;
    }

    std::string getPostId() const {
        return postId;
    }

    std::string getContent() const {
        return content;
    }

    //TODO need it?
    void setContent(const std::string newContent) { 
        content = newContent; 
    }
};