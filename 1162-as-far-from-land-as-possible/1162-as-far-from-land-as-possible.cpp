class Solution { 
    int n,m;  
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    private:
    int solve(vector<vector<int>>&grid,queue<pair<int,int>>&q){
        int c=0;
        while(!q.empty()){
            int t=q.size();
            c++;
            while(t--){
                auto itr=q.front();
                q.pop();
                int x=itr.first;
                int y=itr.second; 
                grid[x][y]=1;
                for(int k=0;k<4;++k){
                    int nx=dx[k]+x;
                    int ny=dy[k]+y;
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==0){
                        q.push({nx,ny});
                        grid[nx][ny]=1;
                    }
                }
            } 
            // c++;
        }
        return c-1;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size(); 
        queue<pair<int,int>>q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
       int ans=solve(grid,q); 
        return ans==0?-1:ans;
        
    }
};