class Solution { 
    private:
        vector<vector<int>>ans;
        vector<int>ds;   
    void solve(int i,int sum,int k,int n){
        if(sum==n && ds.size()==k){
            ans.push_back(ds);
        }
        if(sum>=n)
            return ;
        if(ds.size()>=k) return ;
        for(int j=i;j<=9;++j){
            ds.push_back(j);
            solve(j+1,sum+j,k,n);
            ds.pop_back();
        }
    }
    
public: 
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(1,0,k,n);
        return ans;
    }
};