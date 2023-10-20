class Solution { 
    private:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    int c=0;
    int n,m;
    void solve(vector<vector<int>>&grid,queue<pair<int,int>>&q){
          // queue<pair<int,int>>q;
          // q.push({i,j});
          while(!q.empty()){
              int t=q.size();
              bool flag=0;
              while(t--){
                  auto itr=q.front();
                  q.pop();
                  int x=itr.first;
                  int y=itr.second;
                  grid[x][y]=0;
                  for(int k=0;k<4;++k){
                      int nx=dx[k]+x;
                      int ny=dy[k]+y;
                      if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                          grid[nx][ny]=0;
                          flag=1;
                          q.push({nx,ny});
                      }
                  }
              }
              if(flag)
              c+=1;
          }
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
                 }
             }
         }
         solve(grid,q);
         for(int i=0;i<n;++i){
             for(int j=0;j<m;++j){
                 if(grid[i][j]==1){
                     return -1;
                 }
             }
         }
        return max(0,c);
    }
};