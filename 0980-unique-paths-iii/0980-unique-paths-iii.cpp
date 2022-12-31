class Solution { 
    int n,m; 
    int ans=0;
    int  solve(int i,int j,vector<vector<int>>&grid,int zero){ 
          if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==-1)
              return 0; 
       
        if(grid[i][j]==2){
            if(zero==-1) return 1;
            return 0;
        }
          int val=grid[i][j];
          grid[i][j]=-1;
        zero--;
          int temp=solve(i+1,j,grid,zero)+
              solve(i-1,j,grid,zero) +
              solve(i,j+1,grid,zero) +
              solve(i,j-1,grid,zero);
        grid[i][j]=val;
        zero++;
        return temp;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int zero=0;
        int x,y;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1){
                  x=i; y=j;   
                }
                else if(grid[i][j]==0){
                    zero++;
                }
            }
        }
        return solve(x,y,grid,zero);
    }
    
};