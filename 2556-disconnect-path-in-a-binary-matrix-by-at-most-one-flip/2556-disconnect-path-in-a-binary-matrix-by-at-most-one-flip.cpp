class Solution { 
    private: 
    int n,m;
    bool solve(int i,int j,vector<vector<int>>&grid){
        if(i==n-1 && j==m-1)
             return 1;
        if(i<0 || j<0 || i>=n || j>=m || !grid[i][j])
            return 0;
        grid[i][j]=0;
         bool left =solve(i+1,j,grid); 
        if(left) return 1;
        bool right=solve(i,j+1,grid); 
        if(right) return 1;
        return 0;
    }
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        if(solve(0,0,grid)==0)
              return 1; 
        grid[0][0]=1;
        grid[n-1][m-1]=1; 
        if(solve(0,0,grid)==1)
              return 0;
        return 1;
    }
};