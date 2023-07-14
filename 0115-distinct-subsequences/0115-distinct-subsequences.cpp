int dp[1003][1003];
class Solution { 
    int n;
    int m;
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
          memset(dp,-1,sizeof(dp));
         return solve(0,0,s,t);
    }
};