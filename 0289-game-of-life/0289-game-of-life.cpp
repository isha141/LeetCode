class Solution { 
    int m,n; 
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={0,-1,1,1,-1,0,1,-1};
    int  ok(int i,int j,vector<vector<int>>&b){
        int count=0;
        for(int k=0;k<8;++k){
            int nx=dx[k]+i;
            int ny=dy[k]+j;
            if(nx>=0 && ny>=0 && nx<m && ny<n && (b[nx][ny]==1 || b[nx][ny]==-1)){
                count+=1;
            }
        }
        return count;
    } 
    // 1-->0== -1
    // 0-->1  // -2
public:
    void gameOfLife(vector<vector<int>>& b) {
          m=b.size();
          n=b[0].size();
          for(int i=0;i<m;++i){
              for(int j=0;j<n;++j){
                  if(b[i][j]==0){
                      if(ok(i,j,b)==3){
                          b[i][j]=-2;
                      }
                  }
                  else {
                      int temp=ok(i,j,b);
                      if(temp<2){
                          b[i][j]=-1;
                      }
                      else if(temp>3){
                          b[i][j]=-1;
                      }
                  }
              }
          } 
          // cout<<"hyyd;p"<<endl;
          for(int i=0;i<m;++i){
              for(int j=0;j<n;++j){
                  if(b[i][j]==-1){
                      b[i][j]=0;
                  }
                  else if(b[i][j]==-2){
                      b[i][j]=1;
                  }
              }
          }
          return ;
    }
};