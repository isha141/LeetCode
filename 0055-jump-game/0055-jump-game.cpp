class Solution { 
    private: 
    int n;
    bool solve(int i,vector<int>&nums,vector<int>&dp){
        if(i==n-1)
            return 1;
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        bool take=0;
        bool not_take=0;
        for(int k=1;k<=nums[i];++k){
           take=solve(i+k,nums,dp);
            if(take)
                break;
    }
        return dp[i]=take;
    }
public:
    bool canJump(vector<int>& nums) {
        n=nums.size(); 
        vector<int>dp(n,-1);
        return solve(0,nums,dp); 
    }
};