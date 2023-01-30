class Solution { 
  private: 
    int n;
    vector<vector<string>>ans;  
    bool safe(int row,int col,vector<string>&ds){
        int duprow=row;
        int dupcol=col;
        while(row>=0 && col>=0){
             if(ds[row][col]=='Q')
                 return 0;
            row--;
            col--;
        } 
        row=duprow;
        col=dupcol;
        while(row<n && col>=0){
            if(ds[row][col]=='Q')
                return 0;
            row++;
            col--;
        }
        row=duprow;
        col=dupcol;
        while(col>=0){
            if(ds[row][col]=='Q')
                return 0;
            col--;
        }
        return 1;
    }
    bool solve(int col,vector<string>&ds,int n){
        if(col==n){
            ans.push_back(ds);
            return 1;
        }
        for(int i=0;i<n;++i){ 
             // if(ds[i][col]=='Q'){     
              if(safe(i,col,ds)){ 
                  ds[i][col]='Q';
                solve(col+1,ds,n);
                   ds[i][col]='.';
            }
           // }
        }
            return 0;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n=n;
        vector<string>ds(n);
        string s(n,'.');
       for(int i=0;i<n;++i)
            ds[i]=s;
        solve(0,ds,n);
        return ans;
    }
};