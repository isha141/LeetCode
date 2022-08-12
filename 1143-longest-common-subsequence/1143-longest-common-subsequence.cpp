  class Solution { 
      private:
      int solve(int i,int j,string &t1,string &t2, vector<vector<int>>&dp)
      {
          if(i<0 || j<0)
              return 0;
          int take=0;
          int not_take=0;
          if(dp[i][j]!=-1)
              return dp[i][j];
          if(t1[i]==t2[j])
            take=1+solve(i-1,j-1,t1,t2,dp); 
          else
              not_take=max(solve(i-1,j,t1,t2,dp),solve(i,j-1,t1,t2,dp));
          return dp[i][j]=max(take,not_take);
      }
public:
    int longestCommonSubsequence(string t1, string t2) {
        int m=t1.size();
        int n=t2.size(); 
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(m-1,n-1,t1,t2,dp);
    }
};