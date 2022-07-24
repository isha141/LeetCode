class Solution {
    private:
    int fact(int n,vector<int>&dp)
    { 
        if(n<0) return 0;
        if(n==0 || n==1) return 1;
        int res=0;
        if(dp[n]!=-1) return dp[n];
        for(int i=0;i<n;++i)
             res+=fact(i,dp)*fact(n-i-1,dp);  
        return dp[n]=res;
        // return res;
    }
public:
    int numTrees(int n) { 
        vector<int>dp(n+1,-1);
     return fact(n,dp);
    }
};