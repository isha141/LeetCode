class Solution {
    private:
    int n;
//     void solve(int i,vector<int>adj,vector<int>&ds,vector<vector<int>>&ans,int count){
        
//     }
public:
    vector<vector<int>> groupThePeople(vector<int>& grp) {
         n=grp.size();
         vector<vector<int>>ans;
         vector<int>ds;
          vector<int>adj[n+1];
         for(int i=0;i<n;++i){
             adj[grp[i]].push_back(i);
         }
         for(int i=1;i<=n;++i){
             if(adj[i].size()){
                 vector<int>ds;
                 for(auto itt: adj[i]){
                     ds.push_back(itt);
                     if(ds.size()==i){
                         ans.push_back(ds);
                         ds.clear();
                     }
                 }
             }
         }
        return ans;
    }
};