class Twitter {
private:
unordered_map<int, set<int> > adj;
vector<pair<int, int> > posts;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
        
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        for(int i = posts.size() - 1; i >= 0 && res.size() < 10; i--){
            if(posts[i].first == userId || adj[userId].find(posts[i].first) != adj[userId].end()){
                res.push_back(posts[i].second);
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        adj[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        adj[followerId].erase(followeeId);
    }
};
