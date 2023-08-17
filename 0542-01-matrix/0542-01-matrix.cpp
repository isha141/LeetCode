class Solution { 
    private:
    int n,m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
     void solve(queue<pair<int,int>>&q,vector<vector<int>>&ds){
         while(!q.empty()){
             int t=q.size();
             while(t--){
                 auto itr=q.front();
                 q.pop();
                 int x=itr.first;
                 int y=itr.second;
                 for(int k=0;k<4;++k){
                     int nx=dx[k]+x;
                     int ny=dy[k]+y;
                     if(nx>=0 && nx<n && ny>=0 && ny<m){
                         int dis=ds[x][y]+1;
                         if(ds[nx][ny]>dis){
                         ds[nx][ny]=dis;
                         q.push({nx,ny});
                         }
                     }
                 }
             }
         }
     }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
          n=mat.size();
          m=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>ds(n,vector<int>(m,1e9));
         for(int i=0;i<n;++i){
             for(int j=0;j<m;++j){ 
                 if(mat[i][j]==0){
                   q.push({i,j});
                     ds[i][j]=0;
                 }
             }
         }
        solve(q,ds);
         return ds;
    }
};