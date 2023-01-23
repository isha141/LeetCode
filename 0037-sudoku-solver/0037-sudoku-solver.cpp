class Solution { 
    int n; 
    bool valid(int row,int col,vector<vector<char>>& board,char ch){
        int i=0; 
        int j=0;
        while(i<9){
            if(board[i][col]==ch) return 0;
           
            if(board[row][i]==ch) return 0;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch) 
                return 0;
            i++;
        }
        return 1;
    }
    private:
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;++i){ 
            for(int j=0;j<9;++j){
                if(board[i][j]=='.'){
                   for(char k='1';k<='9';++k){
                    if(valid(i,j,board,k)){
                       board[i][j]=k;
                     if(solve(board))
                      return 1;
                    else
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
        n=board.size(); 
        solve(board);
        return ;
    }
};