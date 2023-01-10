class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n=nums.size(); 
        map<int,int>mp,mp1;
        for(auto itr: nums)
            mp[itr]++;
        for(int i=0;i<n;++i){
            if(mp[nums[i]]==0) continue;
            mp[nums[i]]--;
            if(mp1[nums[i]-1]>0){
                mp1[nums[i]]++;
                mp1[nums[i]-1]--;
            }
            else if(mp[nums[i]+1]>0 && mp[nums[i]+2]>0){
                mp[nums[i]+1]--;
                mp[nums[i]+2]--;
                mp1[nums[i]+2]++;
            }
            else
                return 0;
        }
        return 1;
    }
};