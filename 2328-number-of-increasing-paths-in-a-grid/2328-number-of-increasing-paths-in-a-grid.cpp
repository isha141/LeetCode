#define mod 1000000007
class Solution { 
    private:
     int dx[4]={-1,0,0,1};
      int dy[4]={0,-1,1,0};
    private:
    int solve(int m,int n,vector<vector<int>>&grid,vector<vector<int>>&vis){ 
        long ans=1; 
        if(vis[m][n]!=-1) return vis[m][n];
       for(int i=0;i<4;++i){ 
             int x=m+dx[i];
               int y=n+dy[i];
               if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]>grid[m][n]){
                   ans=(ans%mod+(solve(x,y,grid,vis))%mod)%mod; 
               }
       }
        return vis[m][n]=ans%mod;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size(); 
        vector<vector<int>>vis(m+1,vector<int>(n+1,-1));
        long long  ans=0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){ 
               ans=(ans%mod+ (solve(i,j,grid,vis))%mod)%mod; 
                // cout<<i<<" "<<j<< " "<<temp<<endl; 
            }
        }
        return (int)ans%mod;
    }
};