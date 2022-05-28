// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{ 
    private:
    int solve(int i,int parent ,vector<int> adj[],int c,int d,vector<int>&low,vector<int>&time1,int &timer,vector<int>&vis)
    { 
        vis[i]=1; 
         low[i]=time1[i]=timer++;  
        for(auto itr: adj[i])
        { 
            if(itr== parent) continue;
            if(!vis[itr])
            {
              if(solve(itr, i,adj,c,d,low,time1,timer,vis))
              return true;
              low[i]=min(low[i],low[itr]); 
              if(low[itr]>time1[i]) 
              {
                  if((itr==c  && i==d)|| (itr==d && i==c))
                  return true; 
              }
            }
            else{
                low[i]=min(low[i],low[itr]);
            }
        }
        return false;
        
    }
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here 
        vector<int>low(V,0);
        vector<int>time1(V,0);
        vector<int>vis(V,0);
         int timer=0;
        for(int i=0;i<V;i++)
        { 
            if(!vis[i])
            {
             if(solve(i,-1,adj,c,d,low,time1,timer,vis))
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