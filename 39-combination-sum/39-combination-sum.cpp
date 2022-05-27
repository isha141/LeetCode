class Solution { 
    private:
    void solve(int ind,vector<int>& can,int target, vector<int>ds, vector<vector<int>>&ans,int &sum)
    {
         if(ind==can.size())
         {
             if(sum==target)
                 ans.push_back(ds);
             return ;
         }
        if(sum==target)
        {
            ans.push_back(ds);
            return ;
        }
        for(int i=ind;i<can.size();i++)
        {
            if(sum>target)
                return ;
            sum+=can[i]; 
            ds.push_back(can[i]);
            solve(i,can,target,ds,ans,sum);
                sum-=can[i];
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<vector<int>> ans;
        vector<int>ds; 
        int sum=0;
        solve(0,can,target,ds,ans,sum);
        return ans;
    }
};