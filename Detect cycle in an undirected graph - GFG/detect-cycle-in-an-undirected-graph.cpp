// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution { 
    private:
    bool iscycle(int i, vector<int>&visited,vector<int>adj[])
    {
        queue<pair<int,int>>q;
        q.push({i,-1}); 
        visited[i]=1;
        while(!q.empty())
        {
                auto itr=q.front();
                int node=itr.first;
                int prev=itr.second; 
                q.pop();
                for(auto &it: adj[node])
                {
                    if(!visited[it] )
                    {
                        visited[it]=1;
                        q.push({it,node});
                    }
                    else if(it!=prev)
                    {
                         return true;
                    }
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
            if(!visited[i])
            {
                if(iscycle(i,visited,adj))
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