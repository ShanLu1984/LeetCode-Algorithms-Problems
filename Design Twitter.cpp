// Time complexity: 
// postTweet: O(1); 
// getNewsFeed: log(10 * log(n)), n is the average number of followers per user;
// follow: (unordered_set) average O(1), worst O(n)
// unfollow: average O(1)

class Twitter {
public:
    /** Initialize your data structure here. */
    struct Tweet {
        int time;
        int id;
        Tweet(int time, int id) : time(time), id(id) {}
    };
    
    unordered_map<int, unordered_set<int>> followees; // userid -> vector of followees
    unordered_map<int, vector<Tweet>> tweets; // userid -> vector of Tweet
    int time_stemp;
        
    Twitter() {
        time_stemp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(time_stemp++, tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        map<int, vector<int>, greater<int>> mp; // [time] -> {tweetId, userId, pos in user’s tweets vector}
        unordered_set<int> fl = followees[userId];
        fl.insert(userId);
        for (auto c : fl) {
            if (tweets.find(c) != tweets.end()) {
                vector<Tweet> toc = tweets[c];
                int tailtime = toc.back().time;
                int tailid = toc.back().id;
                mp[tailtime] = {tailid, c, toc.size() - 1};
            }
        }
        vector<int> tids;
        for (int i=0; i<10; ++i) {
            if (!mp.empty()) {
                int key = mp.begin()->first; 
                vector<int> info = mp.begin()->second;
                int tweetId = info[0]; int userid = info[1]; int pos = info[2];
                tids.push_back(tweetId);
                mp.erase(key);
                if(pos > 0) {
                    mp[tweets[userid][pos-1].time] = {tweets[userid][pos-1].id, userid, pos-1};
                }
            } else {
                break;
            }
        }
        return tids;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */