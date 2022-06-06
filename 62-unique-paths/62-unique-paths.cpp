 class Solution { 
     private:
     int f(int m,int n,vector<vector<int>>&dp)
     {
        if(m==1 && n==1)
            return 1; 
        if(m<1 || n<1) return 0; 
         if(dp[m][n]!=-1)
             return dp[m][n];
        int l=f(m-1,n,dp);
        int r=f(m,n-1,dp);
        return dp[m][n]=l+r;
     }
public:
    int uniquePaths(int m, int n) {
     vector<vector<int>>v(m+1,vector<int>(n+1,-1));
        return f(m,n,v);
    }
};