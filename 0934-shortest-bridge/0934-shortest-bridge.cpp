class Solution { 
    private:  
     queue<pair<int,int>>q; 
    int m,n; 
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
        if(i>=m ||  j>=n||i<0 || j<0 || grid[i][j]==0 || vis[i][j]==1)
            return ; 
        q.push({i,j});
        vis[i][j]=1;
        dfs(i+1,j,grid,vis);
        dfs(i,j+1,grid,vis);
        dfs(i-1,j,grid,vis);
        dfs(i,j-1,grid,vis);
    }  
    
    int bfs(vector<vector<int>>&grid,vector<vector<int>>&vis)
    { 
       int c=0;
        while(!q.empty()){
            int t=q.size();
            while(t--){
                auto itr=q.front();
                q.pop();
                int x=itr.first;
                int y=itr.second; 
                // cout<<x<<" "<<y<<endl;
                int dx[4]={-1,1,0,0};
                int dy[4]={0,0,1,-1};
                for(int k=0;k<4;++k){
                    int nexti=x+dx[k];
                    int nextj=y+dy[k];  
                    if(nexti<0 ||  nexti>=m || nextj<0 || nextj>=n ){  
                        // cout<<"hiilo isha "<<" ";
                       // cout<<nexti<<" "<<nextj<<endl;
                        continue;
                    }
                     if(vis[nexti][nextj]==1){ 
                         // cout<<"hy1"<<" ";
                          // cout<<nexti<<" "<<nextj<<endl;
                         continue;  
                     }
                        
                    if(grid[nexti][nextj]==1)
                        return c;
                    vis[nexti][nextj]=1;
                        q.push({nexti,nextj});
                }
            } 
            c++;
        }
        return -1;
    } 
public:
    int shortestBridge(vector<vector<int>>& grid) {
         m=grid.size();
         n=grid[0].size(); 
        int ans=0; 
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
             if(grid[i][j]==1){ 
                 dfs(i,j,grid,vis);  
                 ans=bfs(grid,vis); 
                 return ans;
             }   
            }
        }
        return ans;
    }
};