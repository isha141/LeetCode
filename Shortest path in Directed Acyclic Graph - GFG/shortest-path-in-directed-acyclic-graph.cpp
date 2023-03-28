//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    void solve(int node,vector<pair<int,int>>adj[],vector<int>&dis){
          queue<pair<int,int>>q;
          q.push({0,0});
          while(!q.empty()){
              auto itr=q.front();
              q.pop();
              int node=itr.first;
              int val=itr.second;
              for(auto it: adj[node]){
                  if(dis[it.first]>dis[node]+it.second){
                      dis[it.first]=dis[node]+it.second;
                      q.push({it.first,dis[it.first]});
                  }
              }
         }
    }
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& e){
        vector<pair<int,int>>adj[n];
        for(int i=0;i<m;++i){
            adj[e[i][0]].push_back({e[i][1],e[i][2]});
        }
        vector<int>dis(n,1e9);
        dis[0]=0;
        solve(0,adj,dis); 
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