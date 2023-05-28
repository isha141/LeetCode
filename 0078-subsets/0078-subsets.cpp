class Solution { 
    private:
    vector<vector<int>>ans;  
    int n;
    void solve(int i,vector<int>&nums,vector<int>&ds){
        if(i>=n){
             ans.push_back(ds);
             return ; 
        }
        ds.push_back(nums[i]);
        solve(i+1,nums,ds);
        ds.pop_back();
        solve(i+1,nums,ds);
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
           n=nums.size();
          vector<int>ds;
          solve(0,nums,ds);
         return ans;
    }
};