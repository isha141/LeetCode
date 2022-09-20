class Solution { 
    private:
    int n,m; 
    int ans=0;
    int solve(int i,int j,vector<int>&a,vector<int>&b, vector<vector<int>>&dp)
    {
        if(i>=n || j>=m) return 0; 
         int l=0;
         int r=0; 
        if(dp[i][j]!=-1) 
            return dp[i][j];
        if(a[i]==b[j]){
           l= solve(i+1,j+1,a,b,dp)+1; 
            ans=max(ans,l);
        }
        solve(i+1,j,a,b,dp);
        solve(i,j+1,a,b,dp);
        
        return dp[i][j]=l;
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