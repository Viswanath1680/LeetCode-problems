using pi = pair<int, int>;
class Twitter {
private:
    int time;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pi>> tweetsByUser;

public:
    Twitter() { // this is just a constructor, to define and initialize variables
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetsByUser[userId].push_back( {time, tweetId} );
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pi, vector<pi>, greater<pi>> minHeap;
        // adding userId temporarily
        follows[userId].insert(userId);

        for (int followeeId : follows[userId]) {
            auto tweets = tweetsByUser[followeeId];
            for (int i = tweets.size() - 1; i >= 0; --i) {
                minHeap.push(tweets[i]);
                if (minHeap.size() > 10)    minHeap.pop();
            }
        }
        follows[userId].erase(userId);

        vector<int> ans;
        while( minHeap.size() ){
            auto [time, tweetId] = minHeap.top();
            ans.emplace_back(tweetId);
            minHeap.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if( followerId == followeeId )  return;
        follows[followerId].insert( followeeId );
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase( followeeId );
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