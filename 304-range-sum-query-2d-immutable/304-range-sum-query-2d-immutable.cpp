class NumMatrix { 
    private:
    int dp[1000][1000];
public:
    NumMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        // vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                    continue;
                }
                dp[i][j]=dp[i-1][j]+dp[i][j-1]+mat[i-1][j-1]-dp[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) { 
        row1++;
        col1++;
        row2++;
        col2++;
        return dp[row2][col2]-dp[row1-1][col2]-dp[row2][col1-1]+dp[row1-1][col1-1];
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */