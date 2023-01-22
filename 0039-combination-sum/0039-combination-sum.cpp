class Solution { 
    int n;
    vector<vector<int>>ans; 
    void solve(int ind,vector<int>&ds,vector<int>&can,int target){ 
        if(target==0){
            ans.push_back(ds);
            return ;
        }
         if(ind>=n){
             return ;
         }
          if(target<0) return ;
          ds.push_back(can[ind]);
        solve(ind,ds,can,target-can[ind]);
          ds.pop_back();
        solve(ind+1,ds,can,target);
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& can, int target) { 
        n =can.size();
        vector<int>ds; 
        sort(can.begin(),can.end());
        solve(0,ds,can,target);
        return ans;
    }
};