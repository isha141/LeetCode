class Solution { 
    private:
    int solve(int ind,vector<int>&nums,int n,vector<int>&dp)
    {
        if(ind==n-1)
            return 1;
        if(ind>=n)
            return 0; 
        if(dp[ind]!=-1)
            return dp[ind];
        int steps=nums[ind];
        for(int i=1;i<=steps;++i){
           if(solve(i+ind,nums,n,dp))
               return  dp[ind]=1;
      }
    return dp[ind]=0;
    }
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,n,dp);
    }
};