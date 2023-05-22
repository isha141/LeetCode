class Solution { 
    private:
    queue<pair<int,int>>q;
    int n,m; 
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid){
        if(i>=n || i<0 || j>=m || j<0 || vis[i][j]==1|| grid[i][j]==0){
            return;
        }
        vis[i][j]=1;
        q.push({i,j});
         dfs(i-1,j,vis,grid);
          dfs(i,j+1,vis,grid);
         dfs(i+1,j,vis,grid);
         dfs(i,j-1,vis,grid);
    } 
    int bfs(vector<vector<int>>&vis,vector<vector<int>>&grid){
        int c=0;
        while(!q.empty()){
            int t=q.size();
            while(t--){
                auto itr=q.front(); 
                // cout<<itr.first<<",.l"<<itr.second<<endl;
                 q.pop(); 
                for(int k=0;k<4;++k){
                    int nx=dx[k]+itr.first;
                    int ny=dy[k]+itr.second;
                    if(nx<0 || nx>=n || ny<0 || ny>=m){
                        continue;
                    }
                    if(vis[nx][ny]==1){
                        continue;
                    } 
                    if(grid[nx][ny]==1){
                        return c;
                    }
                     vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
            c+=1;
        }
        return c;
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size(); 
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1){
                    dfs(i,j,vis,grid);
                    int ans=bfs(vis,grid);
                    return ans;
                }
            }
        }
        return -1;
    }
};