#include "Comment.h"
#include "../utils/Utils.h"

Comment::Comment(std::string userId, std::string postId, std::string content)
: id(Utils::generateId()), userId(userId), postId(postId), content(content) {
}

Comment::Comment(std::string id, std::string userId, std::string postId, std::string content) 
    : id(id), userId(userId), postId(postId), content(content) {
}