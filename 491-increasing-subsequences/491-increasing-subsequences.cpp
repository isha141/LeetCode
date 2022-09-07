class Solution { 
    private:
    void solve(int i,vector<int>&nums,int prev,vector<int>&ds,vector<vector<int>>&ans)
    {
        if(i>=nums.size()){
            if(ds.size()>=2){
                ans.push_back(ds);
            }
            return ;
        }
        if(prev==INT_MIN || ds[ds.size()-1]<=nums[i]){
            ds.push_back(nums[i]);
            solve(i+1,nums,nums[i],ds,ans);
            ds.pop_back();
        }   
        //this is basically used to avoid duplicacy 
        if(ds.size()==0 || ds[ds.size()-1]!=nums[i])
        solve(i+1,nums,prev,ds,ans);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        vector<int>ds;
        solve(0,nums,INT_MIN,ds,ans); 
        // vector<vector<int>>res;
        // for(auto itr: ans)
            // res.push_back(itr);
        return ans;
    }
};