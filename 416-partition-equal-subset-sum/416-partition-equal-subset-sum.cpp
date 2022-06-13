class Solution { 
    bool solve(int ind ,int s1,vector<int>& nums,int &sum,vector<vector<int>>&dp){  
        if(s1>sum) return 0;
        if(s1==sum) return 1;
        if(ind>=nums.size())  return 0; 
        if(dp[ind][s1]!=-1) return dp[ind][s1];
        int left=solve(ind+1,s1+nums[ind],nums,sum,dp);
        int right=solve(ind+1,s1,nums,sum,dp);
        return  dp[ind][s1]=(left|| right);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(); 
        int sum=0;
        for(auto itr: nums) sum+=itr;
        if(sum%2) return 0;
        sum=sum/2;  
        vector<vector<int>>dp(n+1,vector<int>(sum,-1));
        return solve(0,0,nums,sum,dp);
    }
};