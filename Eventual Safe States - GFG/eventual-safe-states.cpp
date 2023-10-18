//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution { 
  private:
  bool ok(int node,vector<int>&vis,vector<int>&dfsvis,vector<int>adj[]){
       vis[node]=1;
       dfsvis[node]=1;
       for(auto iit: adj[node]){
           if(vis[iit]==0){
              if(ok(iit,vis,dfsvis,adj))
              return 1;
           }
           else if(dfsvis[iit]==1){
               return 1;
           }
       }
       dfsvis[node]=0;
       return 0;
  }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here 
        vector<int>ans;
        map<int,int>mp;
        vector<int>vis(V,0);
        vector<int>dfsvis(V,0);
        for(int i=0;i<V;++i){
           if(ok(i,vis,dfsvis,adj)){
               mp[i]++;
           }
        }
        for(int i=0;i<V;++i){
            if(mp.find(i)==mp.end()){
                ans.push_back(i);
            }
        }
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