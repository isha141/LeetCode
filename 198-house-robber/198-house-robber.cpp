class Solution { 
    int solve(int ind,vector<int>&nums,int n,vector<int>&dp)
    { 
        if(ind>=n)return 0;
        if(ind==n-1)
            return nums[ind]; 
        if(dp[ind]!=-1)
            return dp[ind];
        int left=nums[ind]+solve(ind+2,nums,n,dp);
        int right=0+solve(ind+1,nums,n,dp);
        return dp[ind]=max(left,right);
         
    }
public:
    int rob(vector<int>& nums) { 
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,nums,n,dp);
    }
};