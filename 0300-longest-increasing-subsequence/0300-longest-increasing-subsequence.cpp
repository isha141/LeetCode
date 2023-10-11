
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
           vector<vector<int>>dp(n+1,vector<int>(n+1,0));
           for(int i=n-1;i>=0;--i){
               for(int prev=i-1;prev>=-1;--prev){
                   int take=0;
                   if(prev==-1 || nums[prev]<nums[i]){
                       take=1+dp[i+1][i+1];
                   }
                   int not_take=dp[i+1][prev+1];
                   dp[i][prev+1]=max(take,not_take);
               }
           }
          return dp[0][0];
    }
};