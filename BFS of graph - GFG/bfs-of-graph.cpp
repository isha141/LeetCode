// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution { 
    private:
    void solve(int i,vector<int>&ans,int *visited,vector<int>adj[])
    {
        
    }
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        int visited[v+1]={0}; 
        queue<int>q;
        q.push(0); 
        visited[0]=1;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop(); 
            ans.push_back(temp);
            for(auto itr: adj[temp])
            {
                if(visited[itr]==0)
                {
                    q.push(itr);
                    visited[itr]=1;
                }
            }
        }
        // for(int i=0;i<=v;i++)
        // { 
        //     if(!visited[i])
        //     solve(i,ans,visited,adj);
        // }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends