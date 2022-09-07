class Solution { 
    private:
    int solve(int i,vector<int>&nums,int &target,int sum,vector<vector<int>>&dp)
    {
        if(i>=nums.size()){
            return sum==target;
        } 
        if(dp[i][sum+1000]!=-1)
            return dp[i][sum+1000];
        int l=solve(i+1,nums,target,sum+nums[i],dp);
        int r=solve(i+1,nums,target,sum-nums[i],dp);
        return dp[i][sum+1000]=l+r;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(); 
        int sum=0; 
        vector<vector<int>>dp(n,vector<int>(target+10000,-1));
        return solve(0,nums,target,sum,dp);
    }
};