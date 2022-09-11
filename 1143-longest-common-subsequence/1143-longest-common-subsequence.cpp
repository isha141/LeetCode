class Solution { 
    private:
    int solve(int i,int j,string &a,string &b,vector<vector<int>>&dp)
    {
        if(i<0 || j<0)
            return 0;
         if(i==0 && j==0)
             return a[0]==b[0];
        int l=0;
        int r=0; 
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(a[i]==b[j])
            l=1+solve(i-1,j-1,a,b,dp);
        else{
            r=max(solve(i-1,j,a,b,dp),solve(i,j-1,a,b,dp));
        }
        return dp[i][j]=max(l,r);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size(); 
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,text1,text2,dp);
    }
};