//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& r) {
        // code here  
        int m=r.size();
        vector<pair<int,int>>adj[n];
        for(int i=0;i<m;++i){
            adj[r[i][0]].push_back({r[i][1],r[i][2]});
            adj[r[i][1]].push_back({r[i][0],r[i][2]});
        }
        vector<int>ways(n,0);
        vector<int>dis(n,INT_MAX);
        dis[0]=0;
        ways[0]=1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto itr=pq.top();
            pq.pop();
            int node=itr.second;
            int ti=itr.first;
            for(auto it: adj[node]){
                int no=it.first;
                int w=it.second; 
                if(dis[no]>dis[node]+w){
                    dis[no]=dis[node]+w; 
                    ways[no]=ways[node]; 
                    pq.push({dis[no],no});
                }
                else if(dis[no]==(dis[node]+w)){
                    ways[no]+=ways[node];
                }
            }
        }
        return ways[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends