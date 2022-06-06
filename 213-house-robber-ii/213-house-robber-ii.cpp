class Solution { 
    private:
    int solve(int ind,vector<int>&nums,int n,vector<int>&dp)
    {
        if(ind==n-1)
            return nums[ind]; 
        if(dp[ind]!=-1)
            return dp[ind];
        if(ind>=n) return 0;
        int pick=nums[ind]+solve(ind+2,nums,n,dp);
        int non_pick=0+solve(ind+1,nums,n,dp);
        return dp[ind]=max(pick,non_pick);
    }
public:
    int rob(vector<int>& nums) { 
        int n=nums.size();
         if(n==1) return nums[0];
        vector<int>dp(n+1,-1); 
       int ans1=solve(0,nums,n-1,dp);
        for(int i=0;i<n;i++)
            dp[i]=-1;
       int ans2= solve(1,nums,n,dp);
        
        return max(ans1,ans2);
    }
};