class Solution { 
    private: 
    bool issafe(int row,int col,char ch,vector<vector<char>>&board){
        for(int i=0;i<9;++i){
            if(board[row][i]==ch)
                return 0;
            if(board[i][col]==ch)
                return 0;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch)
                return 0;
        }
        return 1;
    }
    bool solve(vector<vector<char>>&board){
        
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';++ch){
                        if(issafe(i,j,ch,board)){
                            board[i][j]=ch;
                            if(solve(board)==1){
                                return 1;
                            }
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
        int n=board.size();
        solve(board);
        return ;
    }
};