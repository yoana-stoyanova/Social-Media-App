#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Post.h"
#include "ThumbsUp.h"
#include "Comment.h"

class User {
	std::string id;

	std::string username;
	std::string password;

	std::vector<Post> posts;
	std::vector<ThumbsUp> likes;
	std::vector<Comment> comments;
};

