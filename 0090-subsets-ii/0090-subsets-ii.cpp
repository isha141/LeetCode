class Solution {  
    set<vector<int>>s;
    vector<vector<int>>ans; 
    int n; 
    void solve(int i,vector<int>&nums,vector<int>ds){
         if(i>=n){
              s.insert(ds);
            return ;
        }
        // ans.push_back(ds);
        ds.push_back(nums[i]);
        solve(i+1,nums,ds);
        ds.pop_back(); 
        // if(ds.size() && ds[ds.size()-1]!=nums[i])
        solve(i+1,nums,ds);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         n=nums.size(); 
        vector<int>ds; 
        sort(nums.begin(),nums.end());
        solve(0,nums,ds);  
        for(auto itr=s.begin();itr!=s.end();++itr){
            ans.push_back(*itr);
        }
       // sort(ans.begin(),ans.end());
        return ans;   
    }
};