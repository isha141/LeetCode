//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    void topo(int node,vector<int>&vis,vector<pair<int,int>>adj[],stack<int>&s){
          vis[node]=1;
          for(auto itr: adj[node]){
              if(!vis[itr.first]){
                  topo(itr.first,vis,adj,s);
              }
          }
          s.push(node);
    }
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& e){
        // code here 
        vector<pair<int,int>>adj[n];
        for(int i=0;i<m;++i){
            adj[e[i][0]].push_back({e[i][1],e[i][2]});
        }
        vector<int>vis(n,0);
        stack<int>s;
        for(int i=0;i<n;++i){
            if(!vis[i]){
                topo(i,vis,adj,s);
            }
        }
        vector<int>dis(n,1e9);
        dis[0]=0;
        while(!s.empty()){
            auto itr=s.top();
            s.pop(); 
            if(dis[itr]!=1e9){
            for(auto it: adj[itr]){
                 if(dis[it.first]>dis[itr]+it.second){
                     dis[it.first]=dis[itr]+it.second;
                 }  
            }
         } 
       }
       for(int i=0;i<n;++i){
            if(dis[i]==1e9)
               dis[i]=-1;
        }
        return dis;
     }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends