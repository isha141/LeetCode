class Solution { 
    private: 
    int n;
     vector<vector<string>>ans; 
    bool solve(int ind,vector<string>&ds,vector<int>&left,vector<int>&lower,vector<int>&right){
        if(ind>=n){
            ans.push_back(ds);
            return 1;
        } 
        for(int i=0;i<n;++i){    
            if(ds[i][ind]=='.'){
        if(!left[i] && !lower[i+ind] && !right[n-1+ind-i] ){
              left[i]=1;
            lower[i+ind]=1;
            right[n-1+ind-i]=1;
            ds[i][ind]='Q'; 
            solve(ind+1,ds,left,lower,right);
            left[i]=0;
            lower[i+ind]=0;
            right[n-1+ind-i]=0;
            ds[i][ind]='.'; 
        }
        }
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
        vector<int>left(n,0);
        vector<int>lower(2*n+1,0);
        vector<int>right(2*n+1,0);
        solve(0,ds,left,lower,right);
        return ans;
    }
};