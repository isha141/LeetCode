class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>adj[n+1];
        map<int,int>mp; 
        vector<int>ans;
        for(auto itr: nums){
            mp[itr]++;
        }
        for(auto itr: mp){
            adj[itr.second].push_back(itr.first);
        }
        int ind=n;
        while(ind>=0){ 
             while(ind>=0 && adj[ind].size()==0)
                 ind--;
             for(auto itr: adj[ind]){
                 ans.push_back(itr);
                 k--;
                 if(k<=0)
                     return ans;
             }
            ind--;
        }
        return ans;
    }
};