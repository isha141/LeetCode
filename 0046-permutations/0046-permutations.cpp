class Solution { 
    private:
    vector<vector<int>>ans;
    int n;
    void solve(int i,vector<int>&nums){
        if(i>=n){
            ans.push_back(nums);
             return;
        }
         for(int j=i;j<n;++j){
             swap(nums[i],nums[j]);
             solve(i+1,nums);
             swap(nums[i],nums[j]);
         }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
         n=nums.size();
        solve(0,nums);
         return ans;
    }
};