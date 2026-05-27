#include "Post.h"
#include "../utils/Utils.h"

Post::Post(std::string userId, std::string title, std::string content)
    : id(Utils::generateId()), userId(userId), title(title), content(content) {
}

Post::Post(std::string id, std::string userId, std::string title, std::string content)
    : id(id), userId(userId), title(title), content(content) {
}