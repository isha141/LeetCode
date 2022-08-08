class Solution {
    private:
    int solve(int i,vector<int>&nums,int n,int prev,vector<vector<int>>&dp)
    {
        if(i>=n || prev>=n)
            return 0;  
        if( dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take=0;
        if(prev==-1 || nums[prev]<nums[i])
            take=1+solve(i+1,nums,n,i,dp);
        int not_take=solve(i+1,nums,n,prev,dp); 
        return  dp[i][prev+1]= max(take,not_take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // int prev=-1;
       vector<int>prev(n+1,0);
        vector<int>curr(n+1,0);
        for(int i=n-1;i>=0;--i){
            for(int j=i-1;j>=-1;--j){
                int take=0;
                int not_take=0;
                if(j==-1 || nums[j]<nums[i]){
                    take=prev[i+1]+1;
                }
                not_take=prev[j+1]; 
                curr[j+1]=max(take,not_take);
            }
            prev=curr;
        } 
        return prev[0];
    }
};