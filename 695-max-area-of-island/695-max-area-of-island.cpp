class Solution { 
    private:
    void solve(int i,int j,vector<vector<int>>&grid,int &area){
        int m=grid.size();
        int n=grid[0].size(); 
        grid[i][j]=0;
        queue<pair<int,int>>q;
        q.push({i,j}); 
        while(!q.empty()){
                auto temp=q.front();
                q.pop();
                int x=temp.first;
                int y=temp.second;
                int dx[4]={1,0,0,-1};
                int dy[4]={0,1,-1,0};
                for(int i=0;i<4;++i){
                 int xx=dx[i]+x;
                 int yy=dy[i]+y; 
                if(xx>=0 && xx<m && yy>=0 && yy<n && grid[xx][yy]==1)
                { 
                    area++; 
                    grid[xx][yy]=0;
                    q.push({xx,yy});
                }
            }
            }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1){ 
                    int temp=1;
                    solve(i,j,grid,temp);
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};