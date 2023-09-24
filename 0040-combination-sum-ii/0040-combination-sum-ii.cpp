class Solution { 
    private:
    int n; 
    void solve(int i,vector<int>&can,int target,vector<int>&curr,vector<vector<int>>&ans){ 
           if(target==0){
               ans.push_back(curr);
                return;
           }
          if(target<0)
                return ;
        for(int j=i;j<n;++j){
            if(j>i && can[j]==can[j-1])
                  continue;
             curr.push_back(can[j]);
              solve(j+1,can,target-can[j],curr,ans);
             curr.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
           n=can.size();
          sort(can.begin(),can.end());
          vector<vector<int>>ans;
          vector<int>curr;
          solve(0,can,target,curr,ans);
          return ans;
    }
};