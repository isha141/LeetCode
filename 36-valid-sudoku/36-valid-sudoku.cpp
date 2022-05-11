class Solution { 
    private:
    bool issafe(vector<vector<char>>& board,int row,int col,char ch)
    {
        for(int i=0;i<9;i++)
        {
            if(row!=i){
                if(board[i][col]==ch)
                    return false;
            }
            if(col!=i){
                if(board[row][i]==ch)
                    return false;
            }
            int x=3*(row/3)+ i/3;
            int y=3*(col/3)+i%3;
            if(x!=row && y!=col)
                if(board[x][y]==ch)
                    return false;
            }
        return true;
        }
    private:
    bool solve(vector<vector<char>>& board,vector<vector<int>>&vis)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]!='.' && vis[i][j]==false)
                {
                    vis[i][j]=true;
                    if(issafe(board,i,j,board[i][j]))
                 {
                      if(solve(board,vis)) 
                          return true;
                     else
                         return false;
                }
                else
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]!='.')
                    vis[i][j]=false;
                else
                    vis[i][j]=true;
            }
        }
        return solve(board,vis);
    }
};