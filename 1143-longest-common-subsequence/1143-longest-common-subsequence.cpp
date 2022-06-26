class Solution { 
    private:
    int solve(int i,int j,string &a,string &b,vector<vector<int>>&dp){
        if(i<0 || j<0) return 0;
        if(i==0 && j==0){
            if(a[i]==b[j])
                return 1;
            return 0;
        } 
        if(dp[i][j]!=-1) return dp[i][j];
        int match=0;
        int notmatch=0;
        if(a[i]==b[j])
            match=1+solve(i-1,j-1,a,b,dp);
        else {
            notmatch=0+max(solve(i-1,j,a,b,dp),solve(i,j-1,a,b,dp));
        }
        return dp[i][j]=max(match,notmatch);
    }
public:
    int longestCommonSubsequence(string text1, string text2) { 
        int i=text1.size()-1;
        int j=text2.size()-1; 
       vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
        return solve(i,j,text1,text2,dp);
    }
};