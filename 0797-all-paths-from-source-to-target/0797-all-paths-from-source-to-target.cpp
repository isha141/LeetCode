class Solution { 
    vector<vector<int>>adj;
    vector<vector<int>>ans; 
    void solve(int i,vector<int>&ds,int n,vector<int>&vis){
        if(i==n-1){
            // cout<<"ishii";
            ans.push_back(ds);
            return ;
        } 
        // cout<<i<<",,";
        for(auto itr: adj[i]){
            if(vis[itr]==0){
                vis[itr]=1;
                ds.push_back(itr);
                solve(itr,ds,n,vis);
                vis[itr]=0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        int n=g.size();
        adj.resize(n,vector<int>());
        for(int i=0;i<n;++i){  
            for(auto itr: g[i]){
                adj[i].push_back(itr);
            }
        } 
        vector<int>ds; 
        ds.push_back(0);
        vector<int>vis(n,0);
        vis[0]=1;
        // cout<<n<<",,";
        solve(0,ds,n,vis);
        return ans;
    }
};