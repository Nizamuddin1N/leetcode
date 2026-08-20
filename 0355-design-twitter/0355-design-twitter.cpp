class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int time=0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int, int>>pq;
        if(!tweets[userId].empty()){
            int index = tweets[userId].size()-1;
            auto [timestamp, tweetId] = tweets[userId][index];
            pq.push({timestamp, tweetId, userId, index});
        }
        for(int followee:following[userId]){
            if(!tweets[followee].empty()){
                int index = tweets[followee].size()-1;
                auto [timestamp, tweetId] = tweets[followee][index];
                pq.push({timestamp, tweetId, followee, index});
            }
        }
        vector<int>ans;
        while(!pq.empty() && ans.size() < 10){
            auto[timestamp, tweetId, user, index] = pq.top();
            pq.pop();
            ans.push_back(tweetId);
            if(index>0){
                index--;
                auto [newTime, newTweetId] = tweets[user][index];
                pq.push({newTime,newTweetId,user,index});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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