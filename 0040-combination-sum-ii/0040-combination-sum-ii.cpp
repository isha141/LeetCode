class Solution {
    int n; 
     vector<vector<int>>ans; 
    void solve(int i,vector<int>ds,vector<int>&can,int target){
        if(target==0){
            ans.push_back(ds);
            return ;
        } 
        if(i>=n) return ;
        if(target<0)
            return ;
        for(int j=i;j<n;++j){
            if(j>i && can[j]==can[j-1]) continue;
            ds.push_back(can[j]);
            solve(j+1,ds,can,target-can[j]);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        n=can.size();
        vector<int>ds;
        sort(can.begin(),can.end());
        solve(0,ds,can,target);
        return ans;
    }
};