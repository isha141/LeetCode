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
          if(ob[0][0]==1) return 0;
           memset(dp,0,sizeof(dp));
           for(int i=0;i<n;++i){
                if(ob[i][0]==1) break;
               dp[i][0]=1;
           }
           for(int i=0;i<m;++i){ 
               if(ob[0][i]==1) break;
               dp[0][i]=1;
           }
          for(int i=1;i<n;++i){ 
              for(int j=1;j<m;++j){
                  if(ob[i][j]==1) continue;
                  int left=dp[i][j-1];
                  int up=dp[i-1][j];
                  dp[i][j]=(left+up);
              }
          }
        return dp[n-1][m-1];
    }
};