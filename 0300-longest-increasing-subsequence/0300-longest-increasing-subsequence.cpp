
class Solution { 
    private:
    int n;
    int solve(int i,vector<int>&nums,int prev,vector<vector<int>>&dp){
          if(i>=n)
                return 0; 
         int take=0;
        int not_take=0;
        if(dp[i][prev+1]!=-1)
              return dp[i][prev+1];
        if(prev==-1 || nums[prev]<nums[i]){
            take=1+solve(i+1,nums,i,dp);
        }
        not_take=solve(i+1,nums,prev,dp);
        return dp[i][prev+1]=max(take,not_take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
           n=nums.size();
           vector<vector<int>>dp(n,vector<int>(n,-1));
          return solve(0,nums,-1,dp);
    }
};