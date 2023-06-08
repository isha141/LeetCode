class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        int ans=0;
         for(int i=0;i<n;++i){
             int c=0;
             int j=m-1;
             while(j>=0 && grid[i][j]<0){
                    c+=1;
                 j--;
             }
             ans+=c;
         }
        return ans;
    }
};