class Solution {
    private:
    vector<vector<string>>ans; 
    int n;
    bool canPlace(int row,int col,vector<string>&ds){
        int column=col;
        int r=row;
        while(column>=0){
            if(ds[row][column]=='Q')
                  return 0;
            column--;
        }
         column=col;
        while(row>=0 && column>=0){
            if(ds[row][column]=='Q') 
                  return 0;
            row--;
            column--;
        }
        column=col;
        // r=row;
        while(r<n && column>=0){
            if(ds[r][column]=='Q')
                  return 0;
            r++;
            column--;
        }
        return 1;
    }
    void solve(int col,vector<string>&ds,int n){
          if(col>=n){
              ans.push_back(ds);
              return;
          }
          for(int i=0;i<n;++i){
              if(canPlace(i,col,ds)){
                  ds[i][col]='Q';
                  solve(col+1,ds,n);
                  ds[i][col]='.';
              }
          }
        return ;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
         this->n=n;
        string s(n,'.');
          vector<string>ds(n);
         for(int i=0;i<n;++i){
             ds[i]=s;
         }
         solve(0,ds,n);
         return ans;
    }
};