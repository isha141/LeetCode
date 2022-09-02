class Solution { 
    private:
    void dfs(int node,vector<int>&vis,vector<int>adj[])
    {
        vis[node]=1;
        for(auto itr: adj[node]){
            if(vis[itr]==0)
                dfs(itr,vis,adj);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& c) {
        vector<int>vis(n,0);
        vector<int>adj[n]; 
        if(c.size()<n-1)
            return -1;
        for(int i=0;i<c.size();++i){
            adj[c[i][0]].push_back(c[i][1]);
            adj[c[i][1]].push_back(c[i][0]);
        }
        int ans=0;
        for(int i=0;i<n;++i){
            if(vis[i]==0){
                dfs(i,vis,adj);
                    ans++;
            }
        }
        return ans-1;
    }
};