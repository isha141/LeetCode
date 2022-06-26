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
    int longestCommonSubsequence(string a, string b) { 
        int m=a.size();
        int n=b.size(); 
       vector<vector<int>>dp(m+1,vector<int>(n+1,0));  
        for(int i=0;i<=n;++i){
            dp[0][i]=0;
        }
        for(int i=0;i<m;++i){
            dp[i][0]=0;
        }
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        } 
        // for(int i=0;i<=m;++i){
        //     for(int j=0;j<=n;++j)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return dp[m][n];
        
    }
};