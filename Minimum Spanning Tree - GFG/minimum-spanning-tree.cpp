// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#include<bits/stdc++.h> 
using namespace  std;  
#define  pl pair<int,int>
#define ss second
#define f first
class Solution
{ 
    private:
   int prism_algo(int src,vector<vector<int>> adj[],vector<int>&parent,vector<int>&key,vector<int>&mst,int n)
{
   key[src]=0; 
   int ans=0;
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
   pq.push({0,src});
   while(!pq.empty())
   {
      auto itr=pq.top();
      pq.pop();
      int w=itr.first;
      int u=itr.second;
      if(mst[u]==0)
      ans+=w;
      mst[u]=1;
      for(auto it: adj[u])
      { 
         int node=it[0];
         int weight=it[1];
        if(mst[node]==0 && key[node]>weight)
        {
           key[node]=weight;
           parent[node]=u;
            pq.push({weight,node});
        }
      }
   }
   return ans;
}

	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    { 
    // vector<pair<int,int>>adj(n+1); 
   vector<int>parent(n,-1);
   vector<int>key(n,INT_MAX);
   vector<int>mst(n,0);
    return prism_algo(0,adj,parent,key,mst,n);
//   for(int i=0;i<n;i++)
//   cout<<parent[i]<<" ";
        // code here
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends