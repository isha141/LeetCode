class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int ans=0;
        map<int,int>mp;
        for(auto &itr: nums){
            mp[itr]=1;
           int temp=(sqrt(itr));
            if((1ll*temp*temp)==itr){
            if(mp.find(temp)!=mp.end()){
                mp[itr]=mp[temp]+1;
            }
            }
            ans=max(ans,mp[itr]);
        } 
        if(ans==1)
            return -1;
        return ans;
    }
};