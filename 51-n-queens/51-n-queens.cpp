class Solution {  
    private:
    void solve(int ind,vector<string>&ds,vector<vector<string>>&ans,int n,vector<int>&left,vector<int>&low, vector<int>&upp)
    {
        if(ind==n)
        {
            ans.push_back(ds);
            return ;
        }
        for(int i=0;i<n;i++)
        {
            if(ds[i][ind]=='.'&& !left[i] && low[i+ind]==0 && !upp[n-1+ind-i])
            {
                ds[i][ind]='Q';
                //ds[i][ind]='.';
                left[i]=1;
                low[i+ind]=1;
                upp[n-1+ind-i]=1;
                solve(ind+1,ds,ans,n,left,low,upp);
                ds[i][ind]='.';
                left[i]=0;
                low[i+ind]=0;
                upp[n-1+ind-i]=0;
                
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string>ds(n); 
        vector<int>low(2*n-1,0);
        vector<int>upp(2*n-1,0);
        vector<int>left(n,0);
        string s(n,'.');
        for(int i=0;i<n;i++)
            ds[i]=s;
        solve(0,ds,ans,n,left,low,upp);
        return ans;
    }
};