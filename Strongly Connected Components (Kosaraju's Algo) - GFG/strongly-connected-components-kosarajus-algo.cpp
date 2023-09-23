//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{ 
    private: 
    void topo(int node,vector<vector<int>>&adj,stack<int>&s,vector<int>&vis){
          vis[node]=1;
          for(auto iit: adj[node]){
              if(!vis[iit]){
                  topo(iit,adj,s,vis);
              }
          }
        s.push(node);
    }
    void reversedfs(int node,vector<int>adj[],vector<int>&vis){
         vis[node]=1;
         for(auto iit: adj[node]){
             if(!vis[iit]){
                 reversedfs(iit,adj,vis);
             }
         }
    }
    int Kosaraju(vector<int>&vis,vector<int>adj[],int V,stack<int>&s){
        int ans=0;
         while(!s.empty()){
             auto itr=s.top();
             s.pop();
             if(!vis[itr]){
                 ans+=1;
                 reversedfs(itr,adj,vis);
             }
         }
        return ans;
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int>vis(V,0);
        stack<int>s;
        for(int i=0;i<V;++i){
            if(!vis[i]){
                topo(i,adj,s,vis);
            }
        }
        vector<int>adj1[V];
        for(int i=0;i<V;++i){
            for(auto iit: adj[i]){
                adj1[iit].push_back(i);
            }
            vis[i]=0;
        }
        return Kosaraju(vis,adj1,V,s);
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends