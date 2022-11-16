class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n=nums.size();
        map<int,int>mp; 
        int maxi=0; 
        int count=0;
        int ans=1e9;
        for(auto itr: nums){
            mp[itr%space]++;
            count=max(count,mp[itr%space]);
        }
        for(auto itr: nums){
            if(count==mp[itr%space])
                ans=min(ans,itr);
            
        }
        return ans;
             
    }
};