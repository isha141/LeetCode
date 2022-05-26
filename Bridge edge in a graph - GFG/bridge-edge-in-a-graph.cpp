// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{ 
    private: 
int solve(int node,int parent,vector<int> adj[],int c,int d,vector<int>&lowest,vector<int>&time1,vector<int>&vis,int &timer)
{ 
    
    vis[node]=1;
   // lowest[node]++; 
    time1[node]=lowest[node]=timer++;
     for(auto itr: adj[node])
     { 
         if(itr==parent)
         continue;
         if(vis[itr]==0){
         if(solve(itr,node,adj,c,d,lowest,time1,vis,timer))
             return 1;
         lowest[node]=min(lowest[itr],lowest[node]);
         if(lowest[itr]>time1[node])
        {
            if((itr==c && node==d )|| (itr==d && node==c)) 
            return 1;
        }
         }
        else{
            lowest[node]=min(lowest[node],time1[itr]);
        }
     }
     return 0;
}
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here 
        vector<int>lowest(V,0);
        vector<int>time1(V,0);
        vector<int>vis(V,0); 
        int timeer=0;
        for(int i=0;i<V;i++)
    {
        if(!vis[i])
        { 
            
            if(solve(i,-1,adj,c,d,lowest,time1,vis,timeer))
                return 1;
        }
    } 
    return 0;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends