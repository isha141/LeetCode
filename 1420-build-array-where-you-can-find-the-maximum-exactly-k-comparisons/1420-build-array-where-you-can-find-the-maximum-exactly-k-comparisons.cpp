int dp[101][52][101];
class Solution {
    private:
    int mod=1e9+7;
    int solve(int i,int n,int m,int k,int maxi){
        if(k<0)
            return 0;
        if(i>=n){
            if(k==0)
                 return 1;
            return 0;
        }
        if(dp[i][k][maxi]!=-1)
              return dp[i][k][maxi];
        int ans=0;
        for(int j=1;j<=m;++j){
            if(maxi<j){
                ans=(ans%mod+solve(i+1,n,m,k-1,j)%mod)%mod;
            }
            else{
                ans=(ans%mod+solve(i+1,n,m,k,maxi)%mod)%mod;
            }
        }
        return dp[i][k][maxi]=ans%mod;
    }
public:
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,n,m,k,0);
    }
};