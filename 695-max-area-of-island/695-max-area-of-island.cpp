class Solution {  
    int m,n;
    private:
    void solve(int i,int j,vector<vector<int>>& grid,int &temp)
    {
        int dx[4]={1,0,-1,0};
        int dy[4]={0,-1,0,1};
        for(int k=0;k<4;++k){
            int xx=dx[k]+i;
            int yy=dy[k]+j;
            if(xx>=0 && xx<m && yy>=0 && yy<n && grid[xx][yy]==1){ 
                grid[xx][yy]=0;
                temp++;
                solve(xx,yy,grid,temp);
            } 
        }
        return ;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size(); 
        this->m=m;
        this->n=n;
        int ans=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1){ 
                    int temp=1;  
                    grid[i][j]=0;
                    solve(i,j,grid,temp);
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};