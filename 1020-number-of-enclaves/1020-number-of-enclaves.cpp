class Solution { 
    private:
    int n,m;  
    void solve(int i,int j,vector<vector<int>>&grid){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0)
             return ;
        grid[i][j]=0;
        solve(i+1,j,grid);
        solve(i-1,j,grid);
        solve(i,j+1,grid);
        solve(i,j-1,grid);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
         n=grid.size();
        m=grid[0].size();
       for(int i=0;i<m;++i){
           if(grid[0][i]==1) 
               solve(0,i,grid);
           if(grid[n-1][i]==1)
               solve(n-1,i,grid);
       } 
        for(int i=0;i<n;++i){
            if(grid[i][0]==1)
                solve(i,0,grid);
            if(grid[i][m-1]==1)
                solve(i,m-1,grid);
        }
        int count =0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1)
                    count++;
            }
        }
        return count;
        
    }
};