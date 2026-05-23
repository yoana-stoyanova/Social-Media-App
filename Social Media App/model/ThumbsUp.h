#pragma once
#include <string>

class ThumbsUp {
private:
	std::string id;

	std::string userId;
	std::string postId;

public:
    ThumbsUp(std::string userId, std::string postId);
    ThumbsUp(std::string id, std::string userId, std::string postId);

    std::string getId() const {
        return id;
    }

    std::string getUserId() const {
        return userId;
    }

    std::string getPostId() const {
        return postId;
    }
};