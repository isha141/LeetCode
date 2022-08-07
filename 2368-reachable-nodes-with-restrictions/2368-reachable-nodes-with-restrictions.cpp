class Solution { 
    private:
    int solve(int node,vector<int>adj[],vector<int>&vis)
    {
        vis[node]=1;
        for(auto itr: adj[node])
        {
            if(vis[itr]!=1 && vis[itr]!=-1)
                solve(itr,adj,vis);
        } 
        return 0;
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restric) {
        vector<int>adj[n];
        for(auto itr: edges){
            adj[itr[0]].push_back(itr[1]);
           adj[itr[1]].push_back(itr[0]);
        }
        vector<int>vis(n,0);
        for(auto itr: restric)
            vis[itr]=-1;
        int count=0;
        solve(0,adj,vis); 
        for(auto itr: vis)
            if(itr==1)
                count++;
        return count;
    }
};