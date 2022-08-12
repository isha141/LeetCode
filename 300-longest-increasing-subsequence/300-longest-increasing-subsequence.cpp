class Solution { 
    private:
    int solve(int i,vector<int>&nums,int n,int prev,vector<vector<int>>&dp)
    {
        if(i>=n)
            return 0;
        int pick=0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
       int not_pick=solve(i+1,nums,n,prev,dp);
        if(prev==-1 || nums[prev]<nums[i])
          pick=1+solve(i+1,nums,n,i,dp);
        return dp[i][prev+1]=max(pick,not_pick);
    }
public:
    int lengthOfLIS(vector<int>& nums) { 
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,nums,n,-1,dp);
    }
};