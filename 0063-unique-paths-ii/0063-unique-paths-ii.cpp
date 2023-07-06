int dp[104][104];
class Solution { 
    private:
    int n,m;
    int solve(int i,int j,vector<vector<int>>&ob){
        if(i==n-1 && j==m-1)
             return 1;
        if(i>=n || j>=m || ob[i][j]==1 ) return 0; 
        if(dp[i][j]!=-1) return dp[i][j];
        int left=solve(i,j+1,ob);
        int down=solve(i+1,j,ob);
        // ob[i][j]=temp;
        return dp[i][j]=(left+ down);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
           n=ob.size();
           m=ob[0].size();  
          if(ob[n-1][m-1]==1) return 0;
           memset(dp,-1,sizeof(dp));
           return solve(0,0,ob);
    }
};