class Solution { 
    private: 
    int n,m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1}; 
    void solve(int i,int j,vector<vector<int>>&grid){
        queue<pair<int,int>>q;
        q.push({i,j});  
        grid[i][j]=1;
        while(!q.empty()){
            auto itr=q.front();
            q.pop();
            int x=itr.first;
            int y=itr.second;
            for(int k=0;k<4;++k){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==0){
                    grid[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        
    }
public:
    int closedIsland(vector<vector<int>>& grid) { 
        n=grid.size();
        m=grid[0].size();
        for(int j=0;j<m;++j){
               if(grid[0][j]==0){
                    solve(0,j,grid);
            }
            if(grid[n-1][j]==0)
                solve(n-1,j,grid);
        }
        for(int i=0;i<n;++i){
            if(grid[i][0]==0)
                solve(i,0,grid);
            if(grid[i][m-1]==0)
                solve(i,m-1,grid);
        }  
        int count=0; 
        // for(int i=0;i<n;++i){
        //     for(int j=0;j<m;++j)
        //         cout<<grid[i][j]<<" ";
        //     cout<<endl;
        // }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==0){
                    solve(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};