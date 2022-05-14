class Solution { 
    private:
    bool solve(vector<vector<char>>& board,string word,int i,int j,int temp,int m,int n)
    { 
        if(temp==word.size())
            return true;
        if(i<0 || j<0 || i>=m|| j>=n|| board[i][j]!=word[temp])
            return false;
        board[i][j]='0';
        bool status =solve(board,word,i+1,j,temp+1,m,n)|| 
            solve(board,word,i,j+1,temp+1,m,n)||
            solve(board,word,i-1,j,temp+1,m,n)||
            solve(board,word,i,j-1,temp+1,m,n);
        board[i][j]=word[temp];
        return status;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0] && solve(board,word,i,j,0,m,n))
                {
                    return true;
                }
            }
        }
        return false;
    }
};