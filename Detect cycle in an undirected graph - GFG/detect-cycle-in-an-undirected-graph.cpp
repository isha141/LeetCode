// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution { 
    private:
    bool solve(int i,int prev,vector<int>&visited,vector<int>adj[])
    { 
         visited[i]=1;
         for(auto itr: adj[i])
        {
            if(!visited[itr]){
            if(solve(itr,i,visited,adj))
            return true; 
            }
            else if(itr!=prev)
            {
                return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>visited(V+1,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i]){
            if(solve(i,-1,visited,adj))
            return true;
            }
        }
        return false;
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