class Solution { 
    private:
    int solve(int ind,vector<int>&nums,vector<int>&dp)
    {
        if(ind==nums.size()-1)
            return nums[ind];
        if(ind>=nums.size())
            return 0; 
        if(dp[ind]!=-1)
            return dp[ind];
        int pick=nums[ind]+solve(ind+2,nums,dp);
        // if(ind+2>n)
        //     pick+=nums[ind+2];
        int non_pick=0+solve(ind+1,nums,dp);
        return dp[ind]=max(pick,non_pick);
    }
public: 
    int rob(vector<int>& nums) {  
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,dp);
        
    }
};