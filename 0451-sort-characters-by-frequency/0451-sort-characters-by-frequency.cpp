class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        map<char,int>mp;
        for(auto itr: s){
            mp[itr]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto itr: mp){
            pq.push({itr.second,itr.first});
        }
        string ans="";
        while(!pq.empty()){
            auto itr=pq.top();
            pq.pop();
            while((itr.first)--){
                ans+=itr.second;
            }
        }
        return ans;
    }
};