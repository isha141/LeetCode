class Solution { 
    private:
    bool solve(int i,int n,vector<int>&nums,vector<int>&dp)
    {
        if(i>=n)
            return 1; 
        bool res=0; 
        if(dp[i]!=-1) return dp[i];
        if(i+1<n && nums[i]==nums[i+1]){
             res|=solve(i+2,n,nums,dp);
            if(i+2<n && nums[i]==nums[i+1] && nums[i+1]==nums[i+2])
                res|=solve(i+3,n,nums,dp);
        }
        else if( i+2<n && (nums[i]==nums[i+1]-1) && (nums[i+1]==nums[i+2]-1))
        {
            res|=solve(i+3,n,nums,dp);
        }
        return dp[i]=res;
            
    }
public:
    bool validPartition(vector<int>& nums) { 
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,n,nums,dp);
    }
};