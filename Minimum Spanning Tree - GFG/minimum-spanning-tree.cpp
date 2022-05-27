// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{ 
     private:  
     int findparent(int u,vector<int>&parent)
     {
         if(parent[u]==u)
          return u;
          return parent[u]=findparent(parent[u],parent);
     }
     int union1(int u,int v,vector<int>&rank, vector<int>&parent)
     {
         u=findparent(u,parent);
         v=findparent(v,parent);
         if(rank[u]<rank[v])
         parent[u]=v;
         else if(rank[v]<rank[u])
         parent[v]=u;
         else{
             parent[u]=v;
             v++;
         }
     }
    int solve(int V,vector<vector<int>> adj[], vector<int>&rank, vector<int>&parent)
    {
        for(int i=0;i<V;i++)
        {
            rank[i]=0;
            parent[i]=i;
        }
      //  int ans=0; 
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<V;i++)
        { 
            for(auto itr: adj[i])
            {
              pq.push({itr[1],{itr[0],i}});   
            }
        } 
        int ans=0;
        while(!pq.empty())
        {
            auto itr= pq.top();
            pq.pop();
            int u=itr.second.first;
            int v=itr.second.second;
            int w=itr.first;
            if(findparent(u,parent)!=findparent(v,parent))
            {
                union1(u,v,rank,parent);
                ans+=w;
            }
        }
        return ans;
    }
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    { 
        // n=V;
         // code here    
         vector<int>rank(V);
         vector<int>parent(V);
         return solve(V,adj,rank,parent);
          
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