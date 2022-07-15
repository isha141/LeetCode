class Solution { 
    private:
    int solve(int ind,vector<int>&nums,int prev,int n,vector<vector<int>>&dp){
        if(ind>=n || prev>=n+1)
            return 0; 
        if( dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int not_take=0;
        int take=0;
        not_take=solve(ind+1,nums,prev,n,dp);
        if(prev!=-1 &&  nums[prev]<nums[ind] || (prev==-1))
        take=1+solve(ind+1,nums,ind,n,dp); 
        return dp[ind][prev+1]=max(take,not_take); 
        // else
            // return 0;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans=0;
        int prev=-1; 
        int n=nums.size(); 
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,nums,prev,n,dp);
    }
};