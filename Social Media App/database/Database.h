#pragma once

#include "../model/User.h"
#include "../model/Post.h"
#include "../model/ThumbsUp.h"
#include "../model/Comment.h"

constexpr char DB_DELIMITER = '|';

const std::string USERS_FILE = "data/users.txt";
const std::string POSTS_FILE = "data/posts.txt";
const std::string LIKES_FILE = "data/likes.txt";
const std::string COMMENTS_FILE = "data/comments.txt";

class Database {

public:
    std::vector<User> users;
    std::vector<Post> posts;
    std::vector<ThumbsUp> likes;
    std::vector<Comment> comments;

    void loadUserData();
    void loadPostData();
    void loadLikeData();
    void loadCommentData();

    void loadDatabase();
    void saveDatabase();

public:
    
    void createUser(const User& user);
    bool deleteUser(int userId);
    User* getUserById(int userId);
    User* getUserByUsername(std::string username);


    void createPost(const Post& post);
    bool deletePost(int postId);
    Post* getPostById(int postId);
    std::vector<Post> getAllPosts();
    std::vector<Post> getPostsByUserId(int userId);

    void addLike(const ThumbsUp& like);
    void removeLike(int userId, int postId);
    int getLikeCount(int postId);
    bool hasUserLiked(int userId, int postId);

    void addComment(const Comment& comment);
    bool deleteComment(int commentId);
    std::vector<Comment> getCommentsByPost(int postId);
};
