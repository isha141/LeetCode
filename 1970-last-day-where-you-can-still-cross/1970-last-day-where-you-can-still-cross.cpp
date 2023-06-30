class Solution {  
    private:
    int n,m;  
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    bool ok(int days,vector<vector<int>>&c){
          vector<vector<int>>mat(n,vector<int>(m,0)); 
          for(int i=0;i<days;++i){
              mat[c[i][0]-1][c[i][1]-1]=1;
          }
          queue<pair<int,int>>q;
           for(int i=0;i<m;++i){
               if(mat[0][i]==0){
                   q.push({0,i}); 
                   mat[0][i]=1;
               }
           }
          while(!q.empty()){
              int t=q.size();
               while(t--){
                   auto itr=q.front();
                    q.pop();
                   int x=itr.first;
                   int y=itr.second;
                   if(x==n-1)
                        return 1;
                   for(int k=0;k<4;++k){
                       int nx=dx[k]+x;
                       int ny=dy[k]+y;
                       if(nx>=0 && nx<n && ny>=0 && ny<m && mat[nx][ny]==0){
                           q.push({nx,ny});
                           mat[nx][ny]=1;
                       }
                   }
               }
          }
        return 0;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& c) {
        int low=0;
        int high=c.size(); 
        n=row;
        m=col; 
        int ans=0;
         while(low<=high){
             int mid=(low+high)>>1;
             if(ok(mid,c)){
                 ans=mid;
                 low=mid+1;
             }
             else{
                 high=mid-1;
             }
         }
        return ans;
    }
};