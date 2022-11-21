class Solution { 
    private:
    int solve(int i,int j,int n,int m,vector<vector<char>>& maze){
        int ans=0;
        queue<pair<int,int>>q;
        q.push({i,j}); 
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[i][j]=1;
        while(!q.empty()){
            int t=q.size();
            while(t--){
                auto itr=q.front();
                q.pop();
                int x=itr.first;
                int y=itr.second;
                if((x==0 || y==0 || x==n-1 || y==m-1 ) && (x!=i  || y!=j))
                    return ans;
                int dx[4]={-1,0,1,0};
                int dy[4]={0,1,0,-1};
                for(int k=0;k<4;++k){
                    int nx=dx[k]+x;
                    int ny=dy[k]+y;
                 if(nx<0 || nx>=n || ny<0 || ny>=m || maze[nx][ny]=='+' || vis[nx][ny])
                     continue; 
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
            ans++;
        }
        return -1;
        
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int n=maze.size();
        int m=maze[0].size();
        int i=e[0];
        int j=e[1];
        return solve(i,j,n,m,maze);
    }
};