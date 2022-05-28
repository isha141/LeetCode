class Solution { 
    private:
    void solve(int ind,vector<int>& can,int target,int sum,vector<int>&ds,vector<vector<int>>&ans)
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
            if(i>ind && can[i]==can[i-1])
                 continue; 
            sum+=can[i];
            ds.push_back(can[i]);
            solve(i+1,can,target,sum,ds,ans);
            sum-=can[i];
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& can, int target) { 
        sort(can.begin(),can.end());
         vector<vector<int>>ans;
        vector<int>ds; 
        int sum=0;
        solve(0,can,target,sum,ds,ans);
        return ans;
    }
};