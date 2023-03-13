
class Twitter { 
  map<int,set<int>>foll;
 map<int,vector<pair<int,int>>>mp; 
    int time;
    
public:
    Twitter() {
         time=0;
    }
    void postTweet(int userid, int tweetid) {
       mp[userid].push_back({time++,tweetid});
    }
    
    vector<int> getNewsFeed(int userId) {
      priority_queue<pair<int,int>>pq;
        for(auto itr=mp[userId].begin();itr!=mp[userId].end();++itr){
            pq.push(*itr);
        }
        for(auto itr=foll[userId].begin();itr!=foll[userId].end();itr++){
            auto temp=*itr;
            for(auto it=mp[temp].begin();it!=mp[temp].end();++it){
                pq.push(*it);
            }
        }
        vector<int>ans;
        while(!pq.empty() && ans.size()!=10){
            auto it=pq.top();
            ans.push_back(it.second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int f, int fol) {
        foll[f].insert(fol);
    }
    
    void unfollow(int f, int fol) {
         foll[f].erase(fol);
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