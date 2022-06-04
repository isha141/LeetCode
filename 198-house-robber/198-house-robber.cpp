class Solution { 
    private:
    int solve(int ind,vector<int>&nums,vector<int>&dp)
    { 
        dp[0]=nums[0]; 
        int n=nums.size();
        for(int i=1;i<n;i++) 
        {    
        int pick=nums[i];
            if(i>1)
                pick+=dp[i-2];
        int non_pick=dp[i-1];
         dp[i]=max(pick,non_pick);
        } 
        return dp[n-1];
    }
public: 
    int rob(vector<int>& nums) {  
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,nums,dp);
        
    }
};