class Solution { 
    private:
     vector<vector<int>>ans;
    int n; 
    map<int,int>mp;
    void solve(int i,vector<int>&nums,vector<int>&ds){
        if(mp.size()==n){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<n;++i){
            if(mp.find(i)==mp.end()){
                  mp[i]++;
                ds.push_back(nums[i]);
                solve(i,nums,ds);
                ds.pop_back();
                mp.erase(i);
            }
        }
        return ;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<int>ds;
        solve(0,nums,ds);
        return ans;
    }
};