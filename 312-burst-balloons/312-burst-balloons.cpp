class Solution {
    private:
    int solve(int i,int j,vector<int>&nums,int n,vector<vector<int>>&dp)
    {
        if(i>j)
            return 0; 
        int maxi=INT_MIN; 
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i;k<=j;++k){ 
       int sets=nums[i-1]*nums[k]*nums[j+1]+solve(i,k-1,nums,n,dp)+solve(k+1,j,nums,n,dp);
            maxi=max(maxi,sets);
        }
        return dp[i][j]=maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size(); 
        nums.push_back(1);
        nums.insert(nums.begin(),1);  
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return solve(1,n,nums,n,dp);
    }
};