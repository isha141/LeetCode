long long dp[4000][1002]; 
int mod=1e9+7;
class Solution { 
    private:
    int solve(int start,int end,int k)
    {
        if(start==end && k==0)
            return 1;
        if(k==0)
            return 0;
        if(dp[start+1000][k]!=-1)
            return dp[start+1000][k];
        int l=solve(start-1,end,k-1);
        int r=solve(start+1,end,k-1);
        return dp[start+1000][k]=(l+r)%mod;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(startPos,endPos,k);
    }
};