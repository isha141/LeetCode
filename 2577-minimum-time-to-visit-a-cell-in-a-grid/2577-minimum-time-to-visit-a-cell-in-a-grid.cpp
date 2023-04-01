class Solution { 
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
public:
    int minimumTime(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        if(grid[1][0]>1 && grid[0][1]>1) 
            return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq; 
        pq.push({0,{0,0}}); 
        vector<vector<int>>vis(n,vector<int>(m,0));
        while(!pq.empty()){
            int time=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second; 
            vis[x][y]=1;
            pq.pop();
            if(x==n-1 && y==m-1){
                return time;
            }
            for(int k=0;k<4;++k){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0 || ny<0 || nx>=n || ny>=m || vis[nx][ny])
                      continue; 
                vis[nx][ny]=1;
                long long dis=0; 
                if(grid[nx][ny]>time)
                dis=grid[nx][ny]-time; 
                else dis++;
                if(dis%2==0) dis++;
               pq.push({dis+time,{nx,ny}});
            }
        }
        return -1;
    }
};