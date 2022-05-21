class Solution { 
    private:
    void solve(vector<vector<char>>& grid,int x,int y,int m,int n)
    {
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1}; 
        grid[x][y]='0';
        for(int i=0;i<4;i++)
        {
            int cx=x+dx[i];
            int cy=y+dy[i];
            if(cx>=0 && cx<m && cy>=0 && cy<n)
            { 
                if(grid[cx][cy]=='1')
                solve(grid,cx,cy,m,n);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
       int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    solve(grid,i,j,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};