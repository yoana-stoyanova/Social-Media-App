#include "User.h"
#include "Post.h"
#include "ThumbsUp.h"
#include "Comment.h"
#include "../utils/Utils.h"

User::User(std::string username, std::string password)
    : id(Utils::generateId()), username(username), password(password) {
}

User::User(std::string id, std::string username, std::string password)
    : id(id), username(username), password(password) {
}

void User::addPost(const Post& post) {
    posts.push_back(post);
}

void User::addLike(const ThumbsUp& like) {
    likes.push_back(like);
}

void User::addComment(const Comment& comment) {
    comments.push_back(comment); 
}