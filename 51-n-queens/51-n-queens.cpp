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
  void solve(int col,int n,vector<string>&ds,vector<vector<string>>&ans,vector<int>&left,vector<int>&lower,vector<int>&upper)
    { 
        if(col==n) {
            ans.push_back(ds);
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(ds[i][col]=='.')
            {
                if(left[i]==0 && lower[i+col]==0 && upper[n-1 + (col-i)]==0)
                {
                   ds[i][col]='Q';
                    left[i]=1;
                     lower[i+col]=1;
                     upper[n-1 + (col-i)]=1;
                    solve(col+1,n,ds,ans,left,lower,upper);
                    ds[i][col]='.';
                    left[i]=0;
                     lower[i+col]=0;
                     upper[n-1 + (col-i)]=0;
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
        vector<int>left(n,0);
        vector<int>lower(2*n-1,0);
        vector<int>upper(2*n-1,0);
        solve(0,n,ds,ans,left,lower,upper); 
        return ans;
    }
};