class Solution { 
    private:
    int n,m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int solve(int i,int j,vector<vector<int>>&grid){
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}}); 
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[0][0]=1;
        while(!pq.empty()){
            auto itr=pq.top();
            pq.pop();
            int time=itr.first;
            int x=itr.second.first;
            int y=itr.second.second;
            if(x==n-1 && y==m-1)
                  return time;
            for(int k=0;k<4;++k){
                int nx=dx[k]+x;
                int ny=dy[k]+y;
                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] ){  
                    int temp=0;
                    if(grid[nx][ny]>time)
                        temp=grid[nx][ny]-time; 
                   else
                       temp++;
                    if(temp%2==0) // if the distance is even then we can go to original postion to avoid this we increment by 1;
                        temp++;
                    pq.push({time+temp,{nx,ny}});
                    vis[nx][ny]=1;
                }
            }
        }
        return -1;
    }
public:
    int minimumTime(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        if(grid[0][1]>1  && grid[1][0]>1)
            return -1;
        return solve(0,0,grid);
    }
};