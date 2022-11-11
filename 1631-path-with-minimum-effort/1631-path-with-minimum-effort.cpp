class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size(); 
        int ans=0;
        int m=h[0].size();                                priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq; 
        pq.push({0,{0,0}});  
        vector<vector<int>>ds(n,vector<int>(m,INT_MAX));
        ds[0][0]=0;
         int dx[4]={-1,1,0,0};
         int dy[4]={0,0,-1,1};
        while(!pq.empty()){
            auto itr=pq.top(); 
            pq.pop(); 
             int x=itr.second.first;
             int y=itr.second.second;   
              int d=itr.first; 
            ans=max(ans,d);
            if(x==n-1 && y==m-1){
                return ans;
            } 
            for(int k=0;k<4;++k){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0 || ny<0 || nx>=n || ny>=m )
                    continue;
                if(ds[nx][ny]>(abs(h[x][y]-h[nx][ny]))){
                   ds[nx][ny]=abs(h[nx][ny]-h[x][y]); 
                    // cout<<ds[nx][ny]<<" ,"<<x<<" ,"<<y<<endl;
                    pq.push({ds[nx][ny],{nx,ny}});
                }
            }
        }
        return 0;
    }
};