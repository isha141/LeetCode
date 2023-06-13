class Solution { 
    private:
    void transpose(vector<vector<int>>&grid){
         int n=grid.size();
         int m=grid[0].size();
         for(int i=0;i<n;++i){
             for(int j=0;j<i;++j){
                 swap(grid[i][j],grid[j][i]);
             }
         }
        return ;
    }
public:
    int equalPairs(vector<vector<int>>& grid) {
           int n=grid.size();
           int m=grid[0].size();
          map<vector<int>,int>mp1,mp2;
          for(auto itr: grid){
              mp1[itr]++;
          }
          vector<vector<int>>grid1;
           grid1=grid;
           transpose(grid1); 
           for(auto itr: grid1){
               mp2[itr]++;
           }
           int count=0;
           for(auto itr: grid){
               count+=mp2[itr];
           }
         return count;
    }
};