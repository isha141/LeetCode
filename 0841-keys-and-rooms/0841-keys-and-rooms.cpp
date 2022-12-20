class Solution { 
    void solve(int node,int c, vector<int>adj[],vector<int>&vis,set<int>&s){
        
        for(auto itr: adj[node]){
            if(vis[itr]==0){
                vis[itr]=1;
                solve(itr,c,adj,vis,s);
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
        vector<int>vis(n+1,0);
        int c=0; 
        set<int>s;
        vis[0]=1;
        solve(0,c,adj,vis,s);
        // for(int i=0;i<n;++i)
        //     cout<<vis[i]<<" ";
        for(auto i=0;i<n;++i)
            if(!vis[i]) return 0;
        
       return 1;
        
    }
};