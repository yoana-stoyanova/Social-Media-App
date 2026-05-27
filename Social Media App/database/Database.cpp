#include "Database.h"
#include <fstream>
#include <string>
#include <iostream>
#include "../utils/Utils.h"

//TODO: Add Logging

// Data loading functions
void Database::loadUserData() {
    std::ifstream file(USERS_FILE);
    std::string row;

    if(!file.is_open()) {
        //Log
        std::cout << "User file not open." << std::endl;
        return;
    }

    users.clear();

    while(std::getline(file, row)) {

        if(row.empty()) {
            //Log
            std::cout << "Skipping empty row" << std::endl;
            continue;
        }

        //Log
        std:: cout << "ROW:" << row << std::endl;

        std::vector<std::string> data = Utils::splitRow(row, DB_DELIMITER);

        //TODO: fix warnings
        if (data.size() < 3) {
            std::cout << "Warning: Skipping corrupted database row: " << row << std::endl;
            continue; 
        }

        std::string id = data[0];
        std::string username = data[1];
        std::string password = data[2];

        if(!id.empty() && !username.empty() && !password.empty()) {
            users.push_back(User(id, username, password)); 
        }

    }

    file.close();
}

void Database::loadPostData() {
    std::ifstream file(POSTS_FILE);
    std::string row;

    if(!file.is_open()) return;

    posts.clear();

    while(std::getline(file, row)) {

        if(row.empty()) continue;

        std::vector<std::string> data = Utils::splitRow(row, DB_DELIMITER);

        //TODO: fix warnings
        if (data.size() < 4) {
            std::cout << "Warning: Skipping corrupted database row: " << row << std::endl;
            continue; 
        }

        std::string id = data[0];
        std::string userId = data[1];
        std::string title = data[2];
        std::string content = data[3];

        if(!id.empty() && !userId.empty() && !title.empty() && !content.empty()) {
            posts.push_back(Post(id, userId, title, content)); 
        }
    }
    file.close();
}

void Database::loadCommentData() {
    std::ifstream file(COMMENTS_FILE);
    std::string row;

    if(!file.is_open()) return;

    comments.clear();

    while(std::getline(file, row)) {

        if(row.empty()) continue;

        std::vector<std::string> data = Utils::splitRow(row, DB_DELIMITER);

        //TODO: fix warnings
        if (data.size() < 4) {
            std::cout << "Warning: Skipping corrupted database row: " << row << std::endl;
            continue; 
        }

        std::string id = data[0];
        std::string userId = data[1];
        std::string postId = data[2];
        std::string content = data[3];

        if(!id.empty() && !userId.empty() && !postId.empty() && !content.empty()) {
            comments.push_back(Comment(id, userId, postId, content)); 
        }
    }
    file.close();
}

void Database::loadLikeData() {
    std::ifstream file(LIKES_FILE);
    std::string row;

    if(!file.is_open()) return;

    likes.clear();

    while(std::getline(file, row)) {

        if(row.empty()) continue;

        std::vector<std::string> data = Utils::splitRow(row, DB_DELIMITER);

        //TODO: fix warnings
        if (data.size() < 3) {
            std::cout << "Warning: Skipping corrupted database row: " << row << std::endl;
            continue; 
        }

        std::string id = data[0];
        std::string userId = data[1];
        std::string postId = data[2];

        if(!id.empty() && !userId.empty() && !postId.empty()) {
            likes.push_back(ThumbsUp(id, userId, postId)); 
        }
    }
    file.close();
}

void Database::loadDatabase() {
    loadUserData();
    loadPostData();
    loadCommentData();
    loadLikeData();
}

// Data saving functions
void Database::saveUserData(){
    std::ofstream file(USERS_FILE);

    if (!file.is_open()) {
        std::cout << "User file not open." << std::endl;
        return; 
    }

    int len = users.size();

    for (int i = 0; i < len; i++) {
        file << Utils::concatRow({users[i].getId(), users[i].getUsername(), users[i].getPassword()}, DB_DELIMITER);
    }

    file.close();
}

void Database::savePostData() {
    std::ofstream file(POSTS_FILE);

    if (!file.is_open()) {
        std::cout << "Post file not open." << std::endl;
        return; 
    }

    int len = posts.size();

    for (int i = 0; i < len; i++) {
        file << Utils::concatRow({posts[i].getId(), posts[i].getUserId(), posts[i].getTitle(), posts[i].getContent()}, DB_DELIMITER);
    }

    file.close();
}

void Database::saveLikeData() {
    std::ofstream file(LIKES_FILE);

    if (!file.is_open()) {
        std::cout << "Likes file not open." << std::endl;
        return; 
    }

    int len = likes.size();

    for (int i = 0; i < len; i++) {
        file << Utils::concatRow({likes[i].getId(), likes[i].getUserId(), likes[i].getPostId()}, DB_DELIMITER);
    }

    file.close();
}

void Database::saveCommentData(){
    std::ofstream file(COMMENTS_FILE);

    if (!file.is_open()) {
        std::cout << "Comments file not open." << std::endl;
        return; 
    }

    int len = comments.size();

    for (int i = 0; i < len; i++) {
        file << Utils::concatRow({comments[i].getId(), comments[i].getUserId(), comments[i].getPostId(), comments[i].getContent()}, DB_DELIMITER);
    }

    file.close();
}

void saveDatabase(){
    void saveUserData();
    void savePostData();
    void saveLikeData();
    void saveCommentData();
}

// User-related functions
bool Database::createUser(const std::string& username, const std::string& password){

    if(username.empty() || password.empty()) return false;

    int len = users.size();

    for (int i = 0; i < len; i++) {
        if (users[i].getUsername() == username) {
            //TODO: Log
            std::cout << "Error: Username '" << username << "' is already taken!" << std::endl;

            return false;
        }
    }

    std::string newId = Utils::generateId();

    User newUser(newId, username, password);
    users.push_back(newUser);

    saveUserData();

    return true;
}

bool Database::deleteUser(const std::string& userId){
    std::vector<Post> userPosts = getPostsByUserId(userId);
    size_t len = userPosts.size();

    for(int i = 0; i < len; i++){
        deletePost(userPosts[i].getId());
    }

    int idx = getUserById(userId);

    if(idx == -1) return false;

    users.erase(users.begin() + idx);

    std::cout << "User deleted." << std::endl;

    saveDatabase();

    return true;

}

const std::vector<User>& Database::getAllUsers() const {
    return users;
}

int Database::getUserById(const std::string& userId) {
    int len  = users.size();

    for(int i = 0; i < len; i++){
        if(users[i].getId() == userId){
            return i;
        }
    }

    return -1;
}

int Database::getUserByUsername(const std::string& username){
    int len  = users.size();

    for(int i = 0; i < len; i++){
        if(users[i].getUsername() == username){
            return i;
        }
    }

    return -1;
}


// Post-related functions
bool Database::createPost(const std::string& userId, const std::string& title, const std::string& content){
    if(userId.empty() || title.empty() || content.empty()) return false;

    std::string newId = Utils::generateId();

    Post newPost(newId, userId, title, content);
    posts.push_back(newPost);

    savePostData();

    return true;
}

bool Database::deletePost(const std::string& postId){
    std::vector<ThumbsUp> postLikes = getLikesByPostId(postId);
    size_t len1 = getLikeCountByPostId(postId);

    for(int i = 0; i < len1; i++){
        removeLike(postLikes[i].getId());
    }

    std::vector<Comment> postComments = getCommentsByPostId(postId);
    size_t len2 = getCommentCountByPostId(postId);

    for(int i = 0; i < len2; i++){
        deleteComment(postComments[i].getId());
    }

    int idx = getPostById(postId);

    if(idx == -1) return false;

    posts.erase(posts.begin() + idx);

    std::cout << "Post deleted." << std::endl;

    saveDatabase();

    return true;
}

const std::vector<Post>& Database::getAllPosts() const {
    return posts;
}

int Database::getPostById(const std::string& postId){
    int len  = posts.size();

    for(int i = 0; i < len; i++){
        if(posts[i].getId() == postId){
            return i;
        }
    }

    return -1;
}

std::vector<Post> Database::getPostsByUserId(const std::string& userId){
    std::vector<Post> userPosts;

    int len = posts.size();

    for(int i = 0; i < len; i++){
        if(posts[i].getId() == userId){
            userPosts.push_back(posts[i]);
        }
    }

    return userPosts;
}

// Like-related functions
std::vector<ThumbsUp> Database::getLikesByUserId(const std::string& userId) {
    std::vector <ThumbsUp> userLikes;

    int len = likes.size();

    for(int i = 0; i < len; i++){
        if(likes[i].getId() == userId){
            userLikes.push_back(likes[i]);
        }
    }

    return userLikes;
}

bool Database::createLike(const std::string& userId, const std::string& postId){
    if(userId.empty() || postId.empty()) return false;

    int len = likes.size();

    if(hasUserLiked(userId, postId)){
        std::cout << "User has already liked this post!" << std::endl;
        return false;
    }

    std::string newId = Utils::generateId();

    ThumbsUp newLike(newId, userId, postId);
    likes.push_back(newLike);

    saveLikeData();

    return true;
}

bool Database::removeLike(const std::string& likeId){
    int idx = getLikeById(likeId);

    if(idx == -1) return false;

    likes.erase(likes.begin() + idx);

    std::cout << "Like deleted." << std::endl;

    saveLikeData();

    return true;
}

const std::vector<ThumbsUp>& Database::getAllLikes() const {
    return likes;
}

std::vector<ThumbsUp> Database::getLikesByPostId(const std::string& postId){
    int len  = likes.size();

    std::vector<ThumbsUp> likesByPostId;

    for(int i = 0; i < len; i++){
        if(likes[i].getPostId() == postId){
            likesByPostId.push_back(likes[i]);
        }
    }

    return likesByPostId;
}

int Database::getLikeById(const std::string& likeId){
    int len  = likes.size();

    for(int i = 0; i < len; i++){
        if(likes[i].getId() == likeId){
            return i;
        }
    }

    return -1;
}

size_t Database::getLikeCountByPostId(const std::string& postId){
    return getLikesByPostId(postId).size();
}

//TODO: Better search logic?
bool Database::hasUserLiked(const std::string& userId, const std::string& postId){
    const std::vector<ThumbsUp> postLikes = getLikesByPostId(postId);
    
    int len = getLikeCountByPostId(postId);

    for(int i = 0; i < len; i++){
        if(postLikes[i].getUserId() == userId){
            return true;
        }
    }

    return false;
}

// Comment-related functions
bool Database::createComment(const std::string& userId, const std::string& postId, const std::string& content){
    if(userId.empty() || postId.empty() || content.empty()) return false;

    std::string newId = Utils::generateId();

    Comment newComment(newId, userId, postId, content);
    comments.push_back(newComment);

    saveCommentData();

    return true;
}

bool Database::deleteComment(const std::string& commentId) {
    int idx = getCommentById(commentId);

    if(idx == -1) return false;

    comments.erase(comments.begin() + idx);

    std::cout << "Comment deleted." << std::endl;

    saveCommentData();

    return true;
}

const std::vector<Comment>& Database::getAllComments() const {
    return comments;
}

std::vector<Comment> Database::getCommentsByPostId(const std::string& postId){
    int len  = comments.size();

    std::vector<Comment> commentsByPostId;

    for(int i = 0; i < len; i++){
        if(comments[i].getPostId() == postId){
            commentsByPostId.push_back(comments[i]);
        }
    }

    return commentsByPostId;
}

std::vector<Comment> Database::getCommentsByUserId(const std::string& userId){
    int len  = comments.size();

    std::vector<Comment> commentsByUserId;

    for(int i = 0; i < len; i++){
        if(comments[i].getPostId() == userId){
            commentsByUserId.push_back(comments[i]);
        }
    }

    return commentsByUserId;
}

int Database::getCommentById(const std::string& commentId){
    int len  = comments.size();

    for(int i = 0; i < len; i++){
        if(comments[i].getId() == commentId){
            return i;
        }
    }

    return -1;
}

size_t Database::getCommentCountByPostId(const std::string& postId){
    return getCommentsByPostId(postId).size();
}
