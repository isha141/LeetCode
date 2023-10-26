class Solution {
    private:
     vector<vector<int>>ans;
    int n;
    void solve(int i,vector<int>&can,int target,vector<int>&ds){
         if(target==0){
             ans.push_back(ds);
              return ;
         }
         if(i>=n)  return ;
          if(target<0)
                return ;
         ds.push_back(can[i]);
        solve(i,can,target-can[i],ds);
          ds.pop_back();
        solve(i+1,can,target,ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
             vector<int>ds;
             n=can.size();
             solve(0,can,target,ds);
              return ans;
    }
};