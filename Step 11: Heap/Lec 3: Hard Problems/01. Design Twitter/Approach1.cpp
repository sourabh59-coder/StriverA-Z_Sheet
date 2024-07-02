class Twitter {
public:
    map<int,set<int>> friends;
    int curr;
    priority_queue<vector<int>> qe;
    Twitter() {
        curr = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        qe.push({curr++,tweetId,userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<vector<int>> copy = qe;
        int n =0;
        while(!copy.empty() && n<10)
        {
            auto it = copy.top();
            copy.pop();

            if(it[2]==userId || friends[userId].count(it[2]))
            {
                ans.push_back(it[1]);
                n++;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
