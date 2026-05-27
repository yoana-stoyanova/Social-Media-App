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

    //TODO: private!!
public:
    std::vector<User> users;
    std::vector<Post> posts;
    std::vector<ThumbsUp> likes;
    std::vector<Comment> comments;

    // Data loading functions
    void loadUserData();
    void loadPostData();
    void loadLikeData();
    void loadCommentData();

    void loadDatabase();
    void saveDatabase();

public:
    
    //TODO: create and delete func params

    // User-related functions
    bool createUser(const std::string& username, const std::string& password);
    bool deleteUser(const std::string& userId);
    std::vector<User> getAllUsers();
    User* getUserById(const std::string& userId);
    User* getUserByUsername(const std::string& username);

    // Post-related functions
    bool createPost(const std::string& userId, const std::string& title, const std::string& content);
    bool deletePost(const std::string& postId);
    std::vector<Post> getAllPosts();
    int getPostById(const std::string& postId);
    std::vector<Post> getPostsByUserId(const std::string& userId);

    // Like-related functions
    bool createLike(const std::string& userId, const std::string& postId);
    bool removeLike(const std::string& likeId);
    std::vector<ThumbsUp> getAllLikes();
    std::vector<ThumbsUp> getLikesByPostId(const std::string& postId);
    std::vector<ThumbsUp> getLikesByUserId(const std::string& userId);
    int getLikeById(const std::string& likeId);
    size_t getLikeCountByPostId(const std::string& postId);
    bool hasUserLiked(const std::string& userId, const std::string& postId);

    // Comment-related functions
    bool createComment(const std::string& userId, const std::string& postId, const std::string& content);
    bool deleteComment(const std::string& commentId);
    std::vector<Comment> getAllComments();
    std::vector<Comment> getCommentsByPostId(const std::string& postId);
    std::vector<Comment> getCommentsByUserId(const std::string& userId);
    int getCommentById(const std::string& commentId);
    size_t getCommentCountByPostId(const std::string& postId);
};
