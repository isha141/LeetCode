// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution { 
    private:
    bool dfs(int i,vector<int> adj[],vector<int>&vis, vector<int>&dfsvis)
    {
        vis[i]=1;
        dfsvis[i]=1;
        for(auto itr: adj[i])
        {
           if(!vis[itr]){
            if(dfs(itr,adj,vis,dfsvis))
                return  true;
            } 
            else if(dfsvis[itr])
            return true; 
        }  
        dfsvis[i]=0;
        return  false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here 
        vector<int>vis(V+1,0);
         vector<int>dfsvis(V+1,0);
        for(int i=0;i<V;i++)
        {
         if(vis[i]==0)
         {
            
             if(dfs(i,adj,vis,dfsvis))
             return true; 
           // memset(dfsvis,0,sizeof(dfsvis));
         }
        }
    return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends