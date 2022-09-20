int dp[501][501];
class Solution { 
    int m,n;    
    bool solve(int i,int j,vector<vector<char>>& grid,char &prev,int len,int start,int end)
    {
        if(i==start && j==end)
            return 1;
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!=prev )
            return 0; 
        if(dp[i][j]==1) return 1;
        dp[i][j]=1; 
        bool l=0;
        bool r=0;
        bool u=0;
        bool d=0;  
        if(i+1!=start )
           if(solve(i+1,j,grid,prev,len+1,i,j))
               return 1;
        if(i-1!=start )
            if(solve(i-1,j,grid,prev,len+1,i,j))
                return 1;
        if(j+1!=end )
           if(solve(i,j+1,grid,prev,len+1,i,j))
               return 1;
        if(j-1!=end)
           if(solve(i,j-1,grid,prev,len+1,i,j))
               return 1;
        return 0;
        
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
         m=grid.size();
         n=grid[0].size(); 
        int len=0;
          memset(dp,0,sizeof(dp));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){ 
               if(dp[i][j]==0 && solve(i,j,grid,grid[i][j],1,-1,-1)){
                   return 1;
               } 
            }
        }
        return 0;
    }
};