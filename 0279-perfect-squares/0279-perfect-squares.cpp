class Solution { 
    private:
    int solve(int n,int sum,vector<int>&dp){
        if(n==0){
            return 0;
        }
        if(n<0){
            return 1e9;
        }
        if(dp[n]!=-1)
            return dp[n];
        int ans=1e9;
        for(int i=1;i*i<=n;++i){
            int temp=1+solve(n-(i*i),sum,dp);
            ans=min(ans,temp);
        }
        return dp[n]=ans;
    }
public:
    int numSquares(int n) {
        if(n==0 || n==1) return n;
        int ans=1e9;
        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        for(int i=1;i<=n;++i){
            int temp=1e9;
        for(int j=1;j*j<=i;++j){
            int ans=1e9;
            if(i-(j*j)>=0)
            ans=1+dp[i-(j*j)];
            temp=min(temp,ans);
        }
            dp[i]=temp;
        }
         return dp[n];
    }
};