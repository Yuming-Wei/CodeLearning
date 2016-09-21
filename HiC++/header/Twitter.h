//
//  Twitter.h
//  HiC++
//
//  Created by My AD on 9/21/16.
//  Copyright © 2016 My AD. All rights reserved.
//

#ifndef Twitter_h
#define Twitter_h

class Twitter {
private:
    static int tweetNum;
    map<int, User> users;
public:
    /** Initialize your data structure here. */
    Twitter() {
        tweetNum = 0;
        //users = new vector<User>{};
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweetNum++;
        User newUser(userId);
        newUser.postTw[tweetNum] = tweetId;
        users[userId] = newUser;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> feedQue;
        vector<int> ans;
        if(users.find(userId) != users.end()) {
            for(auto p : users[userId].postTw) feedQue.push(make_pair(p.first, p.second));
            for(auto f : users[userId].followed) {
                for(auto fp : users[f].postTw) feedQue.push(make_pair(fp.first, fp.second));
            }
        }
        int count = 10;
        while(count && feedQue.size()) {
            ans.push_back(feedQue.top().second);
            feedQue.pop();
            count--;
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(users.find(followerId) != users.end() && users.find(followeeId) != users.end()) {
            users[followerId].followed.insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(users.find(followerId) != users.end() && users.find(followeeId) != users.end()) {
            if(users[followerId].followed.find(followeeId) != users[followerId].followed.end()) {
                users[followerId].followed.erase(followeeId);
            }
        }
    }
};

class User {
public:
    int userId;
    map<int,int> postTw; // order and tweetId
    set<int> followed;
    User(int Id) {
        userId = Id;
        //postTw = new map<int,int>();
        //followed = new set<int>();
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

#endif /* Twitter_h */
