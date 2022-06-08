class Solution { 
    private:
    int solve(int i,int j,int m,vector<vector<int>>& t,vector<vector<int>>&dp){
        if(i==m-1)
            return t[i][j]; 
       if(i>=m || j>=t[i].size()+1) return INT_MAX; 
        if(dp[i][j]!=-1) return dp[i][j];
        int left=t[i][j]+solve(i+1,j,m,t,dp);
        int right=t[i][j]+solve(i+1,j+1,m,t,dp);
        return dp[i][j]=min(left,right);
        
    }
public:
    int minimumTotal(vector<vector<int>>& t) {
       int n =t.size();
       vector<vector<int>>dp(n,vector<int>(n,0)); 
        dp[0][0]=t[0][0]; 
        for(int j=0;j<n;j++){
            dp[n-1][j]=t[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                long left=INT_MAX;
                 long  right=INT_MAX;
            left=t[i][j]+ dp[i+1][j]; 
            // if(j>0 && i>0)
           right=t[i][j]+dp[i+1][j+1];
                dp[i][j]=min(left,right);
            }
        }
        return dp[0][0];
    }
};