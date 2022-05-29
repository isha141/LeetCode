class Solution { 
    private:
    bool issafe(vector<vector<char>>& board,int n,int r,int c,char k)
    {
        for(int i=0;i<9;i++)
        {
         if(board[i][c]==k)
                  return false;
         if(board[r][i]==k)
                 return false; 
        if(board[3*(r/3)+(i/3)][3*(c/3)+(i%3)]==k)
            return false;
        }
        return true;
    }
    private:
   bool solve(vector<vector<char>>& board,int n)
    {
        for(int i=0;i<9;i++)
        { 
            for(int j=0;j<9;j++)
            {
              if(board[i][j]=='.')
              { 
               for(char k='1';k<='9';k++){
               if(issafe(board,n,i,j,k))
               {
                   board[i][j]=k;
                   if(solve(board,n)==true)
                       return true;
                   else
                       board[i][j]='.';
                }
                }
                  return false;
              }
                
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) { 
        int n=board.size();
        solve(board,n);
        return ;
    }
};