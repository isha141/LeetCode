class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j=0;j<m;++j)
            dp[0][j]=mat[0][j];
        for(int i=1;i<n;++i){
            for(int j=0;j<m;++j){
                int l=INT_MAX;
                int r=INT_MAX;
                int d=INT_MAX;
                if(j+1<m && i-1>=0){
                    l=dp[i-1][j+1];
                }
                if(i-1>=0)
                    r=dp[i-1][j];
                if(i-1>=0 && j-1>=0)
                    d=dp[i-1][j-1];
                dp[i][j]=mat[i][j]+min(l,min(r,d));
            }
       }
    int ans=1e9;
        for(int j=0;j<n;++j)
            ans=min(ans,dp[n-1][j]);
        return ans;
    }
};