int dp[504][504];
class Solution {
    private:
    int n,m;
    int solve(int i,int j,string &a,string &b){
          if(i<0 && j<0)
                return 0;
          if(i<0) return j+1;
          if(j<0) return i+1;
         if(dp[i][j]!=-1)
               return dp[i][j];
         int take=INT_MAX;
         int not_take=INT_MAX;
         if(a[i]==b[j])
          take=solve(i-1,j-1,a,b);
        not_take=1+min(solve(i-1,j,a,b),min(solve(i,j-1,a,b),solve(i-1,j-1,a,b)));
         return dp[i][j]=min(take,not_take);
    }
public:
    int minDistance(string a, string b) {
         n=a.size();
         m=b.size();
         memset(dp,-1,sizeof(dp));
         return solve(n-1,m-1,a,b);
    }
};