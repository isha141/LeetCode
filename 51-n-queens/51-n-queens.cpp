class Solution {  
    private:
    bool issafe(int ind,int col,vector<string>&ds,int n)
    {
        int duprow=ind;
        int dupcol=col;
        while(dupcol>=0)
        {
            if(ds[duprow][dupcol]=='Q') return 0;
            dupcol--;
        }  
        duprow=ind;
        dupcol=col;
        while(duprow<n && dupcol>=0)
        {
            if(ds[duprow][dupcol]=='Q') return 0;
            duprow++;
            dupcol--;
        }
         duprow=ind;
        dupcol=col;
        while(duprow>=0 && dupcol>=0)
        {
            if(ds[duprow][dupcol]=='Q') return 0;
            duprow--;
            dupcol--;
        }
        return 1;
    }
    private:
  void solve(int col,int n,vector<string>&ds,vector<vector<string>>&ans)
    { 
        if(col==n) {
            ans.push_back(ds);
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(ds[i][col]=='.')
            {
                if(issafe(i,col,ds,n))
                {
                   ds[i][col]='Q';
                    (solve(col+1,n,ds,ans));
                    ds[i][col]='.';
                }
                
            } 
        }
      //  return 1;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string  s(n,'.');
        vector<string>ds(n);
        for(int i=0;i<n;i++)
        {
            ds[i]=s;
        } 
        solve(0,n,ds,ans); 
        return ans;
    }
};