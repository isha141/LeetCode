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
         vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
         for(int j=0;j<m;++j){
             for(int k=0;k<m;++k){
                 if(j==k){
                     dp[n-1][j][k]=grid[n-1][j];
                 }
                 else{
                     dp[n-1][j][k]=grid[n-1][j]+grid[n-1][k];
                 }
             }
         }
        for(int i=n-2;i>=0;--i){
            for(int j=0;j<m;++j){
                for(int k=0;k<m;++k){
                    int ans=0;
                    for(int c1=-1;c1<=1;++c1){
                        for(int c2=-1;c2<=1;c2++){
                            int nc=j+c1;
                            int nc2=k+c2;
                            int take=0;
                                // take=dp[i+1][nc][nc2];
                                if(j!=k){
                                    take+=grid[i][j];
                                    take+=grid[i][k];
                                }
                                else{
                                    take+=grid[i][j];
                                }
                            if(nc>=0 && nc<m && nc2>=0 && nc2<m){
                                take+=dp[i+1][nc][nc2];
                                ans=max(ans,take);
                            }
                            else{
                                // int take=INT_MIN;
                                  ans=max(ans,take);
                            }
                        }
                    }
                    dp[i][j][k]=ans;
                }
            }
        } 
        // for(int i=0;i<n;++i){
            // for(int j=0;j<m;++j){
                // for(int k=0;k<m;++k){
                    // cout<<dp[i][j][k]<<" ";
                // }
                // cout<<endl;
            // }
            // cout<<"*****"<<endl;
        // }
      return dp[0][0][m-1];
         
    }
};