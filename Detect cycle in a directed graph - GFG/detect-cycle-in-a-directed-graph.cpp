// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here 
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(auto itr: adj[i])
            {
                indegree[itr]++;
            }
        }
        int count=0;
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            count++;
            for(auto itr: adj[temp]){
            indegree[itr]--;
            if(indegree[itr]==0)
             q.push(itr);
            }
        }
        if(count==V)
        return 0;
        else
        return 1;
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