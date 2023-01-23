class Solution { 
    private:
    int n;
    vector<vector<string>>ans;
    void solve(int col,vector<string>&ds,vector<int>&left,vector<int>&right, vector<int>&up){
        if(col>=n){
            ans.push_back(ds);
            return ;
        }
        for(int i=0;i<n;++i){
            if(left[i]==0 && up[i+col]==0 && right[n-1+col-i]==0){
                ds[i][col]='Q'; 
                left[i]=1;
                up[i+col]=1;
                right[n-1+col-i]=1;
                solve(col+1,ds,left,right,up);
                ds[i][col]='.';
                left[i]=0;
                up[i+col]=0;
                right[n-1+col-i]=0;
            }
        }
        return ;
    }
public:
    vector<vector<string>> solveNQueens(int n) { 
        this->n=n;
        vector<string>ds(n);
        string s(n,'.');
        for(int i=0;i<n;++i){
            ds[i]=s;
        }
        vector<int>left(n,0);
        vector<int>up(2*n+1,0);
        vector<int>right(2*n+1,0);
        solve(0,ds,left,right,up); 
        return ans;
    }
};