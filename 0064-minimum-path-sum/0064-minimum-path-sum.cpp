class Solution {
    private:
public:
    int minPathSum(vector<vector<int>>& grid) {
         int n=grid.size();
         int m=grid[0].size(); 
          vector<int>prev(m,0);
          prev[0]=grid[0][0];
          for(int i=0;i<n;++i){
               vector<int>curr(m,0);
              for(int j=0;j<m;++j){
                  if(i==0 && j==0){
                     curr[0]=grid[0][0]; 
                      continue;
                  }
                  int left=INT_MAX;
                  int right=INT_MAX;
                  if(j>0){
                      left=curr[j-1]+grid[i][j];
                  }
                  if(i>0){
                      right=prev[j]+grid[i][j];
                  }
                  curr[j]=min(left,right);
              }
              prev=curr;
          }
        return prev[m-1];
    }
};