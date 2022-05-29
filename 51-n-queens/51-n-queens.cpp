class Solution {  
    private:
    bool issafe(int i,int j,vector<string>&ds,int n)
    {
        int r=i;
        int c=j;
        while(r<n && c>=0)
        {
            if(ds[r][c]=='Q') return false;
            r++;
            c--;
        }
        r=i;
        c=j;
        while(c>=0)
        {
            if(ds[i][c]=='Q') return false;
            c--;
        }
        r=i;
        c=j;
        while(r>=0 && c>=0)
        {
            if(ds[r][c]=='Q') return 0;
                r--;
            c--;
        }
        return 1;
    }
    private:
    void solve(int ind,vector<string>&ds,vector<vector<string>>&ans,int n)
    {
        if(ind==n)
        {
            ans.push_back(ds);
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(issafe(i,ind,ds,n))
            {
                ds[i][ind]='Q';
                solve(ind+1,ds,ans,n);
                ds[i][ind]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>ds(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            ds[i]=s;
        solve(0,ds,ans,n);
        return ans;
    }
};