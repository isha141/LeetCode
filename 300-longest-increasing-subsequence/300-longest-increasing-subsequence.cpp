class Solution { 
    private:
    int solve(int i,vector<int>&nums,int n,int prev,vector<vector<int>>&dp)
    {
        if(i>=n)
            return 0;
        int pick=0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
       int not_pick=solve(i+1,nums,n,prev,dp);
        if(prev==-1 || nums[prev]<nums[i])
          pick=1+solve(i+1,nums,n,i,dp);
        return dp[i][prev+1]=max(pick,not_pick);
    }
public:
    int lengthOfLIS(vector<int>& nums) { 
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;--i){  
            for(int prev=i-1;prev>=-1;--prev)
            { 
                int pick=0;
                int not_pick=0;
                if(prev==-1 || nums[prev]<nums[i]){
                    pick=1+dp[i+1][i+1];
                }
                    not_pick=dp[i+1][prev+1];
            dp[i][prev+1]=max(pick,not_pick);
        }
        
        }
        return dp[0][0];
    }
    
};