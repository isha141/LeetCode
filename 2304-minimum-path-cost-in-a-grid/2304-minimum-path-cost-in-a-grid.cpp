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
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX)); 
        for(int i=0;i<n;i++)
            dp[0][i]=grid[0][i];
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){ 
                for(int k=0;k<n;k++){ 
                dp[i][j]=min(dp[i][j],(grid[i][j]+move[grid[i-1][k]][j]+dp[i-1][k]));
            } 
        }
        } 
        for(int i=0;i<n;i++)
            ans=min(ans,dp[m-1][i]);
        return ans;
    }
};