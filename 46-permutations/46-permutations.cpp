class Solution { 
    private:
    void solve(int ind,vector<int>& nums,vector<int>&ds,vector<vector<int>>&ans)
    {
          if(ind==nums.size()){
              ans.push_back(nums);
             return ; 
          }
        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[i],nums[ind]);
            solve(ind+1,nums,ds,ans);
            swap(nums[i],nums[ind]);
        }
}
public: 
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>ds;
        solve(0,nums,ds,ans);
        return ans;
    }
};