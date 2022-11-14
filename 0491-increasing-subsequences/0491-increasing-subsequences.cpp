class Solution { 
    private:
    void solve(int i,vector<int>&nums,vector<int>&ds,set<vector<int>>&s,int prev){
        if(ds.size()>1)
            s.insert(ds);
        if(i>=nums.size()){
            return ;
        }
        for(int j=i;j<nums.size();++j){
            if(prev==-1 || nums[prev]<=nums[j]){
               ds.push_back(nums[j]);
               solve(j+1,nums,ds,s,j);
                ds.pop_back();
              }
           // solve(j+1,nums,ds,s,prev);
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        vector<int>ds; 
        set<vector<int>>s;
        int prev=-1;
        solve(0,nums,ds,s,prev); 
        for(auto itr: s)
            ans.push_back(itr);
        return ans;
    }
};