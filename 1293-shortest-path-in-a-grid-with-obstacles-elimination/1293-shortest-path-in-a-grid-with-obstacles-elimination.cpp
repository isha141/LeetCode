class Solution {
    private:
    int n,m;  
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    int solve(vector<vector<int>>& grid, int l){
       queue<vector<int>>q; 
        // if(grid[0][0]==1)
        //     l-=1;
         q.push({0,0,l});
        vector<vector<int>>vis(n,vector<int>(m,INT_MIN)); 
        int count=0; 
        vis[0][0]=l;
        while(!q.empty()){
            int t=q.size(); 
            bool flag=0;
            while(t--){
                auto itr= q.front();
                q.pop(); 
                int x=itr[0];
                int y=itr[1];
                int l=itr[2];
                // vis[x][y]=1;
                if(x==n-1 && y==m-1)
                    return count; 
                for(int k=0;k<4;++k){
                    int nx=x+dx[k];
                    int ny=y+dy[k]; 
                    // cout<<nx<<" "<<ny<<endl;
                if(nx<0 || ny<0 || nx>=n || ny>=m )
                       continue;  
                int remain=l-grid[nx][ny];
                    if(remain>=0 && vis[nx][ny]<remain){
                        q.push({nx,ny,remain});
                    vis[nx][ny]=remain;
                    }
                }
            } 
            count++; 
        }
        return -1;
    }
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
         n=grid.size();
         m=grid[0].size(); 
   
        // cout<<"hy";
        return solve(grid,k);
    }
};