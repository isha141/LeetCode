struct cmp{
bool operator () (const pair<int,string>&a, const pair<int,string>&b){
    if(a.first!=b.first){
        return a.first>b.first;
    }
    else{
        return a.second<b.second;
    }
    };
};
class Solution { 
    private:
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        map<string,int>mp;
        for(auto itr: words)
            mp[itr]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        for(auto [x,y]: mp){
            pq.push({y,x}); 
            if(pq.size()>k)
               pq.pop();
            }
        while(!pq.empty()){
            auto itr=pq.top(); 
            pq.pop();
           ans.insert(ans.begin(),itr.second);
        }
        return ans;
    }
};