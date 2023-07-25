class Solution { 
    private:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,1,-1,0}; 
    int n;
    int c;
    int ok(int mid,vector<vector<int>>&cells){
        vector<vector<int>>mat(n,vector<int>(c,0));
        for(int i=0;i<mid;++i){
            mat[cells[i][0]-1][cells[i][1]-1]=1;
        }
         queue<pair<int,int>>q;
         for(int i=0;i<c;++i){
                 if(mat[0][i]==0){
                     q.push({0,i});
                 }
         }
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
                 if(nx==n-1 && mat[nx][ny]==0)
                      return 1;
                 if(nx>=0 && ny>=0 && nx<n && ny<c && mat[nx][ny]==0){
                     mat[nx][ny]=1;
                     q.push({nx,ny});
                 }
             }
             }
         }
        return 0;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
          int low=0;
          int high=cells.size(); 
          int ans=0; 
          n=row;
          c=col;
          while(low<=high){
              int mid=(low+high)>>1;
              if(ok(mid,cells)){
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