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

	std::vector<Post> posts;
	std::vector<ThumbsUp> likes;
	std::vector<Comment> comments;

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

	const std::vector<Post>& getPosts() const {
		return posts;
	}

	const std::vector<ThumbsUp>& getLikes() const {
		return likes;
	}

	const std::vector<Comment>& getComments() const {
		return comments;
	}

	void addPost(const Post& post);
	void addLike(const ThumbsUp& like);
	void addComment(const Comment& comment);
};

