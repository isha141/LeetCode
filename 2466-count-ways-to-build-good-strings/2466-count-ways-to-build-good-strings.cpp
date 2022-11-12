class Solution { 
    private:
    int mod=1000000007;
    int solve(int target,int zero,int one,vector<long long>&dp){
        if(target==0)
            return 1;
        if(target<0)
            return 0;
        if(dp[target]!=-1)
            return dp[target]; 
        long long ans=0;
        ans=(solve(target-zero,zero,one,dp)+solve(target-one,zero,one,dp));
        return dp[target]=ans%mod;
        
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long>dp(100001,-1);
        long long ans=0;
        for(int i=low;i<=high;++i){
            ans=(ans%mod+ solve(i,zero,one,dp)%mod)%mod;
        }
        return ans;
    }
};