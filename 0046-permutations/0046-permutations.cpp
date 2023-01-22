class Solution { 
    private:
     vector<vector<int>>ans;
     int n;
    void solve(int ind,vector<int>&nums,vector<int>&ds){
          if(ind>=n){
            ans.push_back(nums);
            return;
        } 
        for(int i=ind;i<n;++i){
         swap(nums[i],nums[ind]);       
         solve(ind+1,nums,ds);
         swap(nums[ind],nums[i]); 
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<int>ds;
        solve(0,nums,ds);
        return ans;
    }
};