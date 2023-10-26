class Solution {
    private:
    bool ok(char val,int r,int c,vector<vector<char>>&board){
          for(int i=0;i<9;++i){
              if(board[i][c]==val)
                   return 0;
              if(board[r][i]==val)
                    return 0;
              if(board[3*(r/3)+i/3][3*(c/3)+i%3]==val)
                   return 0;
          }
        return 1;
    }
    bool  solve(vector<vector<char>>&board){
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                    if(board[i][j]=='.'){
                         for(char k='1';k<='9';++k){
                            if(ok(k,i,j,board)){
                                board[i][j]=k;
                                if(solve(board))
                                      return 1;
                                board[i][j]='.';
                            }
                      }
                     return 0;
                }
            }
        }
        return 1;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};