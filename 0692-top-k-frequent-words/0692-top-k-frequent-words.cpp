class Solution {  
    struct cmp{
    bool operator()(pair<int,string>a , pair<int,string>b){
        if(a.first==b.first)
            return a.second<b.second;
        return a.first>b.first;
    }
    };
        
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
          vector<string>ans(k);  
        map<string,int>mp;
        for(auto itr: words){
            mp[itr]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        for(auto itr: mp){
            pq.push({itr.second,itr.first});  
            if(pq.size()>k)
                pq.pop();
        } 
        while(k--){
            auto itr= pq.top();
            pq.pop();
            ans[k]=itr.second;
        } 
        // sort(ans.begin(),ans.end());
        return ans;
        
    }
};