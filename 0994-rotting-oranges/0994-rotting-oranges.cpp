class Solution { 
    private:  
    int n,m;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    int solve(queue<pair<int,int>>&q,vector<vector<int>>& grid){
        int c=0;
        while(!q.empty()){
            int t=q.size();
            while(t--){
                auto itr=q.front();
                q.pop();
                int x=itr.first;
                int y=itr.second; 
                grid[x][y]=0; 
                for(int k=0;k<4;++k){
                    int nx=dx[k]+x;
                    int ny=dy[k]+y;
                    if(nx>=0 && ny>=0 && nx<n  && ny<m && grid[nx][ny]!=0){
                        q.push({nx,ny});
                          grid[nx][ny]=0;
                    }
                }
            }
            if(q.size())
            c++;
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1) return -1;
            }
        }
        return c;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j]=0;
                }
            }
        }
        return solve(q,grid);
    }
};