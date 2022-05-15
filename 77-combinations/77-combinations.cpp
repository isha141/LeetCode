class Solution { 
private:
    void solve(int ind,vector<int>&ds,int k, vector<vector<int>>&ans,int n)
    {   
        if(ind==n)
        {
            if(ds.size()==k)
                ans.push_back(ds);
            return ;
        }
            if(ds.size()==k){
            ans.push_back(ds);
            return ;
        }
            ds.push_back(ind);
            solve(ind+1,ds,k,ans,n); 
            ds.pop_back();
             solve(ind+1,ds,k,ans,n);
        }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>a;
        vector<int>ds; 
         vector<vector<int>>ans;
        solve(1,ds,k,ans,n+1);
        return ans;
    }
};