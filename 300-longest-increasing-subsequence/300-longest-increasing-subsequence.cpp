class Solution {
    private:
    int solve(int i,vector<int>&nums,int n,int prev,vector<vector<int>>&dp)
    {
        if(i>=n || prev>=n+1)
            return 0;  
        if( dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take=0;
        if(prev==-1 || nums[prev]<nums[i])
            take=1+solve(i+1,nums,n,i,dp);
        int not_take=solve(i+1,nums,n,prev,dp); 
        return  dp[i][prev+1]= max(take,not_take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int prev=-1; 
        int maxi=0;
        for(auto itr:nums)
            maxi=max(maxi,itr);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,nums,n,prev,dp);
    }
};