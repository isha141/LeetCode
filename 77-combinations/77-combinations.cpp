class Solution { 
    void solve(int ind,vector<int>&a, vector<int>&ds, vector<vector<int>>&ans,int k)
    { 
        if(ind==a.size())
        {
            if(ds.size()==k)
                ans.push_back(ds);
            return ;
        }
        if(ds.size()==k){
            ans.push_back(ds);
            return ;
        }
        ds.push_back(a[ind]);
        solve(ind+1,a,ds,ans,k);
        ds.pop_back();
        solve(ind+1,a,ds,ans,k);
    }
public:
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>> ans;
        vector<int>ds;
        vector<int>a;
        for(int i=1;i<=n;i++)
            a.push_back(i);
        solve(0,a,ds,ans,k);
        return ans;
    }
};