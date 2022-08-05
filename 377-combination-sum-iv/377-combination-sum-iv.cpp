class Solution {
    private: 

    int solve(int i,vector<int>&nums,int sum,int target,vector<int>&dp)
    {
        if(sum>target)
            return 0;
        if(sum==target)
            return 1;
        if(dp[sum]!=-1)
            return dp[sum]; 
            int res=0;
        for(int k=0;k<nums.size();++k)
          res+=solve(k,nums,sum+nums[k],target,dp);
       return dp[sum]=res;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(target+1,-1);
        return solve(0,nums,0,target,dp);
    }
};