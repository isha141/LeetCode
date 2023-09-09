class Solution { 
    private:
    int count=0;
    int solve(int i,vector<int>&nums,int &sum,int &target,vector<vector<int>>&dp)
    { 
        if(sum==target){
            count++;
            return 1;
        }
        if(sum>target)
            return 0; 
        if(dp[i][sum]!=-1)
            return dp[i][sum]; 
        int count=0;
        for(int k=0;k<nums.size();++k){
            sum+=nums[k];
             count+=solve(k,nums,sum,target,dp);
            sum-=nums[k];
        }
        return dp[i][sum]=count;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0; 
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(0,nums,sum,target,dp);
    }
};