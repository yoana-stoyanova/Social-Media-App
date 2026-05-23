#include "ThumbsUp.h"
#include "../utils/Utils.h"
#include <string>

ThumbsUp::ThumbsUp(std::string userId, std::string postId)
    : id(Utils::generateId()), userId(userId), postId(postId) {
}

ThumbsUp::ThumbsUp(std::string id, std::string userId, std::string postId)
    : id(id), userId(userId), postId(postId) {
}