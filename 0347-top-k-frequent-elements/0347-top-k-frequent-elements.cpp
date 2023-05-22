class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         vector<int>ans;
         int n=nums.size();
        priority_queue<pair<int,int>>pq;
        map<int,int>mp;
        for(auto itr: nums)
            mp[itr]++;
        for(auto itr: mp){
            pq.push({itr.second,itr.first}); 
            cout<<itr.first<<",,"<<itr.second<<endl;
        }
        while(k--){
            auto itr=pq.top();
             pq.pop();
            ans.push_back(itr.second);
        }
        return ans;
    }
};