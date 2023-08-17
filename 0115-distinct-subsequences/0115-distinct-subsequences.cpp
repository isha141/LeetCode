int dp[1001][1001];
class Solution { 
    int n;
    int m;
    int solve(int i,int j,string &s,string &t){
        if(j>=m)
              return 1;
        if(i>=n)
              return 0; 
        if(dp[i][j]!=-1)
             return dp[i][j];
        int take=0;
        int not_take=0;
        if(s[i]==t[j])
             take=solve(i+1,j+1,s,t);
        not_take=solve(i+1,j,s,t);
        return dp[i][j]=take+not_take;
    }
public:
    int numDistinct(string s, string t) {
         n=s.size();
         m=t.size(); 
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t);
    }
};