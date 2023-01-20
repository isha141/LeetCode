class Solution { 
    private:
   vector<vector<int>>ans; 
    set<vector<int>>s;
    int n;
    void solve(int i,int prev,vector<int>&nums,vector<int>&ds){
        if(i>=n){ 
            if(ds.size()>1){
                s.insert(ds);
          // ans.push_back(ds); 
            }
            return ;
        }
        if(prev==-1 || nums[prev]<=nums[i]){
            ds.push_back(nums[i]);
            solve(i+1,i,nums,ds);
            ds.pop_back();
        }
            solve(i+1,prev,nums,ds);
        return ;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
         n=nums.size(); 
           int prev=-1;
        vector<int>ds;
         solve(0,prev,nums,ds); 
        for(auto itr=s.begin();itr!=s.end();++itr){
            ans.push_back(*itr);
        }
         return ans;
    }
};