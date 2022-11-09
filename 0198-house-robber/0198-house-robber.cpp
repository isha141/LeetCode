class Solution { 
    private:
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i<0)
            return 0; 
        if(dp[i]!=-1)
            return dp[i];
        int pick=0;
        int not_pick=0;
        pick=nums[i]+solve(i-2,nums,dp);
        not_pick=solve(i-1,nums,dp);
        return dp[i]=max(pick,not_pick);
    }
public:
    int rob(vector<int>& nums) {
        int n= nums.size(); 
        vector<int>dp(n,-1);
        return solve(n-1,nums,dp);
    }
};