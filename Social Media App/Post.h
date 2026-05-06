#pragma once
#include <iostream>
#include <vector>

#include "ThumbsUp.h"
#include "Comment.h"

class Post {
	std::string id;
	std::string userId;

	std::string title;
	std::string content;

	std::vector<ThumbsUp> likes;
	std::vector<Comment> comments;
};
