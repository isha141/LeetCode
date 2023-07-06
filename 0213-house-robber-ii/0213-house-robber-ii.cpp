class Solution { 
    private:
    int n;
    private:
    int solve(int i,int n,vector<int>&nums,vector<int>&dp){
        if(i>n) return 0;
        if(dp[i]!=-1)
              return dp[i];
        int take=0;
        int not_take=0;
        take=nums[i]+solve(i+2,n,nums,dp);
        not_take=solve(i+1,n,nums,dp);
        return dp[i]=max(take,not_take);
    }
public:
    int rob(vector<int>& nums) {
        n=nums.size(); 
        if(n==1) 
            return nums[0]; 
        vector<int>dp(n,-1);
        int ans1=solve(0,n-2,nums,dp);  
        for(int i=0;i<n;++i) dp[i]=-1;
        // memset(dp,-1,sizeof(dp));
        int ans2=solve(1,n-1,nums,dp);
        return max(ans1,ans2);
    }
};