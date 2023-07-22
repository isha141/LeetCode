
class Solution { 
    private:
    int n;
    long solve(int i,vector<int>&nums,int odd,int x,vector<vector<long>>&dp){
          if(i>=n) 
              return 0;
         if(dp[i][odd]!=-1)
              return dp[i][odd];
        long not_pick=solve(i+1,nums,odd,x,dp); 
         long pick=0;
        if(odd){
             if(nums[i]%2)
                   pick=nums[i]+solve(i+1,nums,odd,x,dp); 
            else  
                pick=nums[i]-x+solve(i+1,nums,!odd,x,dp);
        }
        else{
            if(nums[i]%2==0)
                   pick=nums[i]+solve(i+1,nums,odd,x,dp); 
            else  
                pick=nums[i]-x+solve(i+1,nums,!odd,x,dp); 
        } 
         return dp[i][odd]=max(pick,not_pick);
    }
public:
    long long maxScore(vector<int>& nums, int x) {
        n=nums.size();
        vector<vector<long>>dp(n,vector<long>(2,-1));
        return nums[0] + solve(1,nums,(nums[0] &1),x,dp);
    } 
};