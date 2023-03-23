//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution { 
    private:
    bool solve(int node,vector<int>adj[],vector<int>&vis,vector<int>&dfsvis){
        vis[node]=1; 
        dfsvis[node]=1;
        for(auto itr : adj[node]){
            if(!vis[itr]){
                  if(solve(itr,adj,vis,dfsvis))
                  return 1;
            }
            else if(dfsvis[itr])
            return 1;
        } 
        vis[node]=0;
        dfsvis[node]=0;
        return 0;
    }
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        // code here  
        vector<int>vis(v+1,0); 
        vector<int>dfsvis(v+1,0);
        vector<int>ans;
        for(int i=0;i<v;++i){
            if(!vis[i]){
                  vis[i]=1;
                if(!solve(i,adj,vis,dfsvis)){
                    ans.push_back(i);
                }
            
            }
            }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends