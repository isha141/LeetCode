 class Solution { 
     private:
     int solve(int i,int j,vector<vector<int>>& grid, vector<vector<int>>& move,vector<vector<int>>&dp){
         if(i==grid.size()-1) return grid[i][j];
        if(j<0 || j>=grid[0].size()) return INT_MAX/2;
             if(dp[i][j]!=-1)
                 return dp[i][j];
         int ans=INT_MAX/2;
         for(int k=0;k<grid[0].size();k++){
            ans =min(ans,(grid[i][j]+move[grid[i][j]][k] + solve(i+1,k,grid,move,dp)));
         }
               return dp[i][j]=ans;
     }
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& move) { 
        int ans=INT_MAX; 
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(100,vector<int>(100,-1));
        for(int i=0;i<grid[0].size();i++)
        {
            ans=min(ans,solve(0,i,grid,move,dp));
        }
        return ans;
    }
};