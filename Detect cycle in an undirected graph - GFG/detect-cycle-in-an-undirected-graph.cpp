// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution { 
    private:
    bool iscycle(int node,vector<int>adj[],int par,vector<int>&visited){
        for(auto itr: adj[node])
        {
            if(visited[itr]==0)
            { 
                visited[itr]=1;
                if(iscycle(itr,adj,node,visited))
                return 1;
            }
            else if(itr!=par)
            return 1;
        }
        return 0;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here 
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0){ 
                visited[i]=1;
                if(iscycle(i,adj,-1,visited))
                  return 1;
            }
        }
        return 0;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends