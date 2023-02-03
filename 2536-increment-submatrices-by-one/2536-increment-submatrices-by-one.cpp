class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>>ans(n+1,vector<int>(n+1,0));
        int m=q.size(); 
        for(auto itr: q){
            int row1=itr[0];
            int col1=itr[1];
            int row2=itr[2];
            int col2=itr[3];
            ans[row1][col1]++;
            ans[row1][col2+1]--;
            ans[row2+1][col1]--;
            ans[row2+1][col2+1]++;
        } 
        for(int i=0;i<=n;++i){
              for(int j=1;j<=n;++j){
                  ans[i][j]+=ans[i][j-1];
              }
        }
        for(int i=1;i<=n;++i){
            for(int j=0;j<=n;++j){
                ans[i][j]+=ans[i-1][j];
            }
        }
        vector<vector<int>>res(n,vector<int>(n,0));
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                res[i][j]=ans[i][j];
            }
        }
        return res;
       
    }
};