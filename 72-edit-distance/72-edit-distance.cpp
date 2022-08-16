class Solution { 
    private:
    int solve(int i,int j,string &a,string &b,vector<vector<int>>&dp)
    { 
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;
        int l=0;
        int r=0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(a[i]==b[j])
            return dp[i][j]=solve(i-1,j-1,a,b,dp);
        else
            return dp[i][j]=1+min(solve(i-1,j-1,a,b,dp),min(solve(i,j-1,a,b,dp),solve(i-1,j,a,b,dp)));
    }
public:
    int minDistance(string w1, string w2) {
        int m=w1.size()-1;
        int n=w2.size()-1;  
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(m,n,w1,w2,dp);
    }
};