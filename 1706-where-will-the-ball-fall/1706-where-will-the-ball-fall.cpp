class Solution { 
private:
    int n,m; 
   int solve(int i,int j,vector<vector<int>>& grid,vector<int>&ds){  
       if(i>=n){
           return j;
       }
       if(grid[i][j]==1 && j+1<m && grid[i][j+1]==1){
          return solve(i+1,j+1,grid,ds);
               // return j;
       }
       else if(grid[i][j]==-1 && j-1>=0 && grid[i][j-1]==-1){
           return solve(i+1,j-1,grid,ds);
               // return j;
       }
       else
           return -1; 
       return -1;
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
         n=grid.size(); 
         m=grid[0].size();
         vector<int>ds; 
          for(int k=0;k<m;++k){ 
            int t=solve(0,k,grid,ds); 
              // if(t==-1)
              //     ds.push_back(-1);
              // else
                 ds.push_back(t);
         }
         return ds;
    }
};