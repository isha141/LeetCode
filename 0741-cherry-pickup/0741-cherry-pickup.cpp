int dp[52][52][52];
class Solution {
    private:
    int n,m;
    int ans=0;
    int solve(int r1,int c1,int r2,int sum,vector<vector<int>>&grid){
        if(r1>=n || c1>=m || r2>=n || (r1+c1)-r2 >=n || grid[r1][c1]==-1 || grid[r2][(r1+c1)-r2]==-1)
               return -1e9;
        if((r1==n-1 && c1==m-1)){
            return grid[r1][c1];
        } 
        // if((r2==n-1 && c2==m-1)){
            // return grid[r2][c2];
        // } 
        int ch=0;
        if((r1==r2) && (c1==(r1+c1)-r2)){
            ch+=grid[r1][c1];
        }
        else {
            ch+=grid[r1][c1]+grid[r2][(r1+c1)-r2];
        }
        if(dp[r1][c1][r2]!=-1)
            return dp[r1][c1][r2];
        int l=solve(r1+1,c1,r2+1,ch,grid); // vv
        int r=solve(r1,c1+1,r2,ch,grid); // hh
        int u=solve(r1,c1+1,r2+1,ch,grid); // hv
        int d=solve(r1+1,c1,r2,ch,grid); // vh
        ch+=max(l,max(r,max(u,d)));
        return dp[r1][c1][r2]=ch;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size(); 
        if(n==1 && m==1)
            return grid[0][0]; 
        memset(dp,-1,sizeof(dp));
       int ans= solve(0,0,0,0,grid);
        return ans<=0?0:ans;
        // return ans;
    }
};