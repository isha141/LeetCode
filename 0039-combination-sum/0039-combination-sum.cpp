class Solution {
    private: 
    int n;
    void solve(int i,vector<int>&can,vector<int>&ds,int target,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        if(target<0)
              return ;
        if(i>=n)
              return ;
        ds.push_back(can[i]);
        solve(i,can,ds,target-can[i],ans);
        ds.pop_back();
        solve(i+1,can,ds,target,ans);
        return ;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
          n=can.size();
         vector<vector<int>>ans;
         vector<int>ds;
         solve(0,can,ds,target,ans);
         return ans;
    }
};