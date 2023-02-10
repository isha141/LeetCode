class Solution { 
    private:
    bool ok(char k,int i,int j,vector<vector<char>>&board){
        for(int ind=0;ind<9;++ind){
            if(board[i][ind]==k) return 0;
            if(board[ind][j]==k) return 0;
            if(board[3*(i/3)+ind/3][3*(j/3)+ind%3]==k) return 0;
        }
        return 1;
    }
    bool solve(vector<vector<char>>&board){
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
        return ;
    }
};