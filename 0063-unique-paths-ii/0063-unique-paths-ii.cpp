int dp[101][101];
class Solution {
    private:
    int n,m;
    int solve(int i,int j,vector<vector<int>>& ob){
        if(i==n-1 && j==m-1){
             return 1;
        }
        if(i<0 || j<0 || i>=n || j>=m)
             return 0;
        if(ob[i][j]==1)
              return 0;  
        if(dp[i][j]!=-1)
             return dp[i][j];
        int right=solve(i+1,j,ob);
        int down=solve(i,j+1,ob);
        return dp[i][j]=(down + right);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        n=ob.size();
        m=ob[0].size(); 
        if(ob[0][0]==1 || ob[n-1][m-1]==1)
             return 0;
        vector<vector<int>>dp(n,vector<int>(m,0)); 
        dp[0][0]=1;
        for(int i=0;i<m;++i){
             if(ob[0][i]!=1){
                  dp[0][i]=1;
             } 
            else  
                break;
        }
        for(int i=0;i<n;++i){
             if(ob[i][0]!=1){
                  dp[i][0]=1;
             } 
            else 
                break;
        }
        for(int i=1;i<n;++i){
            for(int j=1;j<m;j++){
                if(ob[i][j]==1)
                    continue; 
                int right=dp[i][j-1];
                int left=dp[i-1][j];
                dp[i][j]=(left +right);
            }
        }
        return dp[n-1][m-1];
    }
};