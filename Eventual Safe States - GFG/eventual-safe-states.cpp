//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution { 
    private:
     vector<int>ans;
    bool solve(int node,vector<int>adj[],vector<int>&vis,vector<int>&dfsvis,vector<int>&check){
        vis[node]=1; 
        dfsvis[node]=1; 
        for(auto itr : adj[node]){
            if(!vis[itr]){
                  if(solve(itr,adj,vis,dfsvis,check)){ 
                      check[node]=1;
                      return  1;
                  } 
            } 
            else if(dfsvis[itr]){
                check[node]=1;
            return 1;
            }
        } 
        dfsvis[node]=0;
        return 0;
    }
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        // code here  
        vector<int>vis(v+1,0); 
        vector<int>dfsvis(v+1,0); 
        vector<int>check(v+1,0);
        for(int i=0;i<v;++i){ 
             if(!vis[i]){
               solve(i,adj,vis,dfsvis,check);
        } 
        }
        for(int i=0;i<v;++i){
            if(!check[i]){
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