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

	std::vector<ThumbsUp> likes;
	std::vector<Comment> comments;

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

    const std::vector<ThumbsUp>& getLikes() const {
        return likes;
    }

    const std::vector<Comment>& getComments() const {
        return comments;
    }

    void addLike(const ThumbsUp& like);
    void addComment(const Comment& comment);
};
