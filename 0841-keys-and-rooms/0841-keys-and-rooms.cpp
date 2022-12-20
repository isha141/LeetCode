class Solution { 
    void solve(int node, vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        for(auto itr: adj[node]){
            if(vis[itr]==0){
                // vis[itr]=1;
                solve(itr,adj,vis);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& r) {
        int n=r.size();
        vector<int>adj[n+1];
        for(int i=0;i<n;++i){
            vector<int>ds=r[i];
            for(auto itr: ds){
                adj[i].push_back(itr);
            }
        }
        vector<int>vis(n,0);
        int c=0; 
        solve(0,adj,vis);
        for(auto i=0;i<n;++i)
            if(!vis[i]) return 0;
        
       return 1;
        
    }
};