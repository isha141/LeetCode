int dp[72][72][72];
class Solution {
    private:
    int n,m;
    int solve(int row,int c1,int c2,vector<vector<int>>&grid){
        if(c1<0 || c1>=m || row>=n || c2<0 || c2>=m)
              return 0;
        int take=0; 
        if(dp[row][c1][c2]!=-1)
              return dp[row][c1][c2];
        if(c1==c2){
            take=grid[row][c1];
        }
        else{
            take=grid[row][c1];
            take+=grid[row][c2];
        } 
        int ans=0;
        for(int col=-1;col<=1;++col){
             for(int col1=-1;col1<=1;++col1){
              int nc1=col+c1;
              int nc2=col1+c2;
              int res=take+solve(row+1,nc1,nc2,grid);
              ans=max(ans,res); 
         }
        }
        return dp[row][c1][c2]=ans;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size(); 
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m-1,grid);
    }
};