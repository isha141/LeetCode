class Solution { 
    long long mod=1e9+7; 
//     int solve(int n,bool flag){
        
//     }
public:
    int numTilings(int n) {
        if(n==0)
            return 0;
        if(n==1) 
            return 1;
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;++i){
          int temp=(dp[i-1]*2)%mod;
            if(i-3>=0)
                temp+=dp[i-3];
            dp[i]=temp%mod;
        }
        return dp[n];
    }
};