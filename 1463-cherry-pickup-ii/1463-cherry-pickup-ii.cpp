int dp[71][71][71];
class Solution { 
    private:
    int n,m;
    int solve(int i,int j,int k,vector<vector<int>>&grid){
        if(i<0 || j<0 || i>=n || j>=m || k<0 || k>=m )
              return 0;
        if(i==n-1){ 
             if(j==k)
            return grid[i][j]; 
            return grid[i][j]+grid[i][k];
        } 
        if(dp[i][j][k]!=-1) 
            return dp[i][j][k];
        int temp=grid[i][j];
        if(j!=k){
            temp+=grid[i][k];
        }
        int left=temp+max(solve(i+1,j,k,grid),max(solve(i+1,j,k+1,grid),solve(i+1,j,k-1,grid)));
        int right=temp+max(solve(i+1,j+1,k+1,grid),max(solve(i+1,j+1,k,grid),solve(i+1,j+1,k-1,grid)));
        int down=temp+max(solve(i+1,j-1,k-1,grid),max(solve(i+1,j-1,k,grid),solve(i+1,j-1,k+1,grid)));
        return dp[i][j][k]=max(left,max(down,right));
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
          n=grid.size();
          m=grid[0].size(); 
          int ans=0; 
           memset(dp,-1,sizeof(dp));
           ans=solve(0,0,m-1,grid);
           return ans;
    }
};