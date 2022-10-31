class Solution { 
    private:
    int n,m;
    int solve(vector<vector<int>>& grid, int k)
    {
        queue<vector<int>>q;
        q.push({0,0,0,k});
        vector<vector<int>>vis(n,vector<int>(m,-1)); 
        while(!q.empty()){
            auto itr=q.front();
            q.pop();
            int x=itr[0];
            int y=itr[1]; 
            if(x==n-1 && y==m-1)
                return  itr[2];
            if(x<0|| y<0 || x>=n || y>=m)
                continue;
            if(grid[x][y]==1){
             if(itr[3]>=1)
                 itr[3]-=1;
            else
                continue;
           } 
            if(vis[x][y]!=-1 && vis[x][y]>=itr[3])
                continue;
            vis[x][y]=itr[3];
            q.push({x-1,y,itr[2]+1,itr[3]});
            q.push({x+1,y,itr[2]+1,itr[3]});            
            q.push({x,y-1,itr[2]+1,itr[3]});
            q.push({x,y+1,itr[2]+1,itr[3]});
        }
        return -1;
        
    }
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        return solve(grid,k);
    }
};