class Solution {
    private:
    void solve(int ind,int k, vector<int>&ds, vector<vector<int>>&ans,int &sum,int n)
    {  
        if(ind>9)
         {
        if(sum==n && k==ds.size())
        {
                ans.push_back(ds);
                return ;
         } 
            return ;
        } 
        if(sum==n && ds.size()==k)
        {
            ans.push_back(ds);
            return ;
        }
        if(sum>n)
            return ;
        for(int i=ind;i<=9;i++)
        {
            ds.push_back(i);
            sum+=i;  
            solve(i+1,k,ds,ans,sum,n);
            ds.pop_back();
            sum-=i;
        }
        }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ds;
        // for(int i=1;i<=n;i++)
        //     ds.push_back(i); 
        int sum=0;
        vector<vector<int>> ans;
        solve(1,k,ds,ans,sum,n);
        return ans;
    }
};