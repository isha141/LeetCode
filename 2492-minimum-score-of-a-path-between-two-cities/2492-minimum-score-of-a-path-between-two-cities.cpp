class Solution { 
    int ans=(int)1e9;
    void solve(int node,vector<pair<int,int>>adj[],vector<int>&vis){
        vis[node]=1;
        for(auto [itr,val]: adj[node]){
             ans=min(ans,val);
            if(vis[itr]==-1){
                solve(itr,adj,vis);
            }
        }
    }
public:
    int minScore(int n, vector<vector<int>>& r) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<r.size();++i){
            adj[r[i][0]].push_back({r[i][1],r[i][2]});
             adj[r[i][1]].push_back({r[i][0],r[i][2]});
        }
        vector<int>vis(n+1,-1);
        solve(1,adj,vis);
        return ans;
    }
};