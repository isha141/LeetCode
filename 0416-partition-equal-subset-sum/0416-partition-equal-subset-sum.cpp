
class Solution {
    private:
    int solve(int i,vector<int>&nums,int target,vector<vector<int>>&dp){
        if(target==0) 
            return 1;
        if(i<0)
             return 0;
        if(target<0) return 0;
        if(dp[i][target]!=-1)
              return dp[i][target];
        int take=0;
        int not_take=0;
        take=solve(i-1,nums,target-nums[i],dp);
        not_take=solve(i-1,nums,target,dp);
        return dp[i][target]=(take | not_take);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2) return 0;
        vector<vector<int>>dp(n+1,vector<int>((sum)/2+1,0));
        for(int i=0;i<n;++i){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;++i){
            for(int j=0;j<=(sum/2);++j){
                int take=0;
                int not_take=0;
                if(j>=nums[i-1]){
                    take=dp[i-1][j-nums[i-1]];
                }
                not_take=dp[i-1][j];
                dp[i][j]=(take|not_take);
            }
        }
        return dp[n][sum/2];
    }
};