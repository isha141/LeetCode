int dp[1003][1003];
class Solution { 
    int n;
    int m; 
    int mod=1e9+7;
    int solve(int i,int j,string &s,string &t){
        if(j==m)
             return 1;
        if(j>=m || i>=n)
             return 0;
        if(dp[i][j]!=-1)
             return dp[i][j];
        int pick=0;
        int not_pick=0;
        if(s[i]==t[j]){
            pick=solve(i+1,j+1,s,t);
        }
        not_pick=solve(i+1,j,s,t);
        return dp[i][j]=pick+not_pick;
    }
public:
    int numDistinct(string s, string t) {
          n=s.size();
          m=t.size();
          vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
          long ans=0; 
        for(int i=0;i<n;++i){
            dp[i][0]=1;
        }
          for(int i=1;i<=n;++i){
              for(int j=1;j<=m;++j){ 
                  int take=0;
                  int not_take=0;
                  if(s[i-1]==t[j-1]){
                     dp[i][j]=1ll*(1ll*dp[i-1][j-1]+1ll*dp[i-1][j])%mod;
                  }
                  else{
                      dp[i][j]=dp[i-1][j];
                  }
              }
          }
        return dp[n][m];
    }
};