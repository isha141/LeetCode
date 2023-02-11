class Solution { 
    int n,m;  
    int ans=0;
    private:
    int solve(int i,int j,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp){
        if(i>=n || j>=m)
            return 0; 
        if(dp[i][j]!=-1) 
            return dp[i][j];
        int take=0;
        int not_take=0;
        if(nums1[i]==nums2[j]){
            take=1+solve(i+1,j+1,nums1,nums2,dp); 
            ans=max(ans,take);
        }
        (solve(i+1,j,nums1,nums2,dp),solve(i,j+1,nums1,nums2,dp));
        return dp[i][j]=take;
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        m=nums2.size(); 
        vector<vector<int>>dp(n,vector<int>(m,-1));
         solve(0,0,nums1,nums2,dp);
        return ans;
    }
};