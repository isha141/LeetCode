class Solution { 
    private:
    int solve(int i,int j,string &a,string &b,vector<vector<int>>&dp)
    { 
        if(i<0|| j<0) return 0;
        if(i==0 && j==0){
            if(a[i]==b[j])
                return 1;
        } 
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j])
            return dp[i][j]=1+solve(i-1,j-1,a,b,dp);
        else 
            return dp[i][j]= max(solve(i-1,j,a,b,dp),solve(i,j-1,a,b,dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(s.begin(),s.end()); 
        int i=s.size(); 
        vector<vector<int>>dp(i+1,vector<int>(i+1,-1));
        return solve(i-1,i-1,s,t,dp);
    }
};