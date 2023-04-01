//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& e) {
        // Code here 
        vector<pair<int,int>>adj[n+1];
        vector<int>dis(n+1,1e9);
        vector<int>parent(n+1,-1);
        for(int i=0;i<m;++i){
            adj[e[i][0]].push_back({e[i][1],e[i][2]});
            adj[e[i][1]].push_back({e[i][0],e[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        dis[1]=0;
        while(!pq.empty()){
              auto it=pq.top();
              pq.pop();
              int node=it.second;
              int val=it.first;
              for(auto itr: adj[node]){
                  if(dis[itr.first]>dis[node]+itr.second){
                       dis[itr.first]=dis[node]+itr.second;
                       pq.push({dis[itr.first],itr.first});
                       parent[itr.first]=node;
                  }
              }
        }
        vector<int>ans;
        // ans.push_back(n);
        int node=n;
        while(parent[node]!=-1){
              ans.push_back(node);  
              node=parent[node];
        }  
        if(ans.size()==0) return {-1};
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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