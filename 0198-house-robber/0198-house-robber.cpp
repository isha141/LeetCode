class Solution { 
    private:
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i<0)
            return 0; 
        if(dp[i]!=-1)
            return dp[i];
        int pick=0;
        int not_pick=0;
        pick=nums[i]+solve(i-2,nums,dp);
        not_pick=solve(i-1,nums,dp);
        return dp[i]=max(pick,not_pick);
    }
public:
    int rob(vector<int>& nums) {
        int n= nums.size(); 
        vector<int>dp(n,0); 
        for(int i=0;i<n;++i){
            int pick=nums[i];
            int not_pick=0; 
            if(i-2>=0)
            pick+=dp[i-2];
             if(i-1>=0)
                not_pick=dp[i-1];
            dp[i]=max(pick,not_pick);  
        } 
        for(int i=0;i<n;++i)
            cout<<dp[i]<<" ";
        return dp[n-1];
    }
};