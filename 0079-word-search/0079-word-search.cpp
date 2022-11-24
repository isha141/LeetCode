int vis[15][15];
class Solution { 
    int n,m;
    bool solve(int i,int j,vector<vector<char>>& board, string word,int k){
        if(k>=word.size())
            return 1;
        if(i<0 | i>=n || j<0 || j>=m || board[i][j]!=word[k] || vis[i][j]==1 )
            return 0;
        // vis[i][j]=1; 
        char ch=board[i][j];
        board[i][j]='.';
        bool down=solve(i+1,j,board,word,k+1);
        bool right=solve(i,j+1,board,word,k+1);
        bool left=solve(i,j-1,board,word,k+1);
        bool up=solve(i-1,j,board,word,k+1);
        board[i][j]=ch;
        return (left || right || up|| down);   
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
         n=board.size();
        m=board[0].size(); 
        for(int i=0;i<n;++i){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){ 
                    memset(vis,0,sizeof(vis));
                    if(solve(i,j,board,word,0))
                        return 1;
                }
            }
        }
        return 0;
    }
};