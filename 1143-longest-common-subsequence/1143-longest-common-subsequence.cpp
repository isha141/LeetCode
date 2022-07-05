class Solution { 
    private:
    int solve(int i,int j,string &a,string &b,vector<vector<int>>&dp)
    {
        if(i<0 || j<0)
            return 0; 
        int left=0;
        int right=0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j])
            left=1+solve(i-1,j-1,a,b,dp);
        else
            right= max(solve(i-1,j,a,b,dp),solve(i,j-1,a,b,dp));
        return dp[i][j]= max(left,right);
    }
public:
    int longestCommonSubsequence(string t1, string t2) {
        int m=t1.size();
        int n=t2.size(); 
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,t1,t2,dp);
    }
};