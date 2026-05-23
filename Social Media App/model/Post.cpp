#include "Post.h"
#include "../utils/Utils.h"

Post::Post(std::string userId, std::string title, std::string content)
    : id(Utils::generateId()), userId(userId), title(title), content(content) {
}

Post::Post(std::string id, std::string userId, std::string title, std::string content)
    : id(id), userId(userId), title(title), content(content) {
}

void Post::addLike(const ThumbsUp& like) {
    likes.push_back(like);
}

void Post::addComment(const Comment& comment) {
    comments.push_back(comment);
}