class Solution {  
     vector<vector<string>>ans;
    int n;
    private: 
    bool isvalid(vector<string>&ds,int row,int col){
         int i=row;
         int j=col;
        while(j>=0){
            if(ds[i][j]=='Q')
                 return 0;
            j--;
        }
        i=row;
        j=col;
        while(i>=0 && j>=0){
            if(ds[i][j]=='Q') 
                return 0;
            i--; 
            j--;
        } 
        i=row;
        j=col;
        while(i<n && j>=0){
            if(ds[i][j]=='Q') 
                return 0;
            i++;
            j--;
        }
        return 1;
    }
    
    void solve(int col,vector<string>&ds){
        if(col==n){
            ans.push_back(ds);
            return ;
        }
        for(int i=0;i<n;++i){
            if(isvalid(ds,i,col)){
                ds[i][col]='Q';
                solve(col+1,ds);
                ds[i][col]='.';
            }
        }
        return ;
    }
public:
    vector<vector<string>> solveNQueens(int n) { 
        this->n=n;
        vector<string>ds(n);
        string ss(n,'.');
        for(int i=0;i<n;++i){
             ds[i]=ss;
        }
        solve(0,ds);
        return ans;
    }
};