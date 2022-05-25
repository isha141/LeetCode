// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

int findparent(int u,vector<int> &parent)
{
    if(parent[u]==u)
     return u;
   return parent[u]=findparent(parent[u],parent);  
}
void union1(int u,int v,vector<int> &parent,vector<int>&rank)
{
    u=findparent(u,parent);
    v=findparent(v,parent); 
    if(rank[u]<rank[v])
    {
        parent[u]=v;
    }
    else if(rank[v]<rank[u])
    {
        parent[v]=u;
    }
    else
    {
        parent[v]=u;
        rank[u]++;
    }
    
}

class Solution
{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here 
        vector<int>rank(V);
        vector<int>parent(V);
        for(int i=0;i<V;i++)
        {
            rank[i]=0; 
            parent[i]=i;
        }
        int ans=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<V;i++) 
        {
        for(auto itr: adj[i])
       {
          //vector<int>ds=itr;
          pq.push({itr[1],{itr[0],i}});
       }
        }
       while(!pq.empty())
      {
             auto itr=pq.top();
             pq.pop();
             int wt=itr.first;
             int u=itr.second.first;
             int v=itr.second.second; 
             if(findparent(u,parent)!=findparent(v,parent))
             { 
                 union1(u,v,parent,rank);
                 ans+=wt;
             }
      }
      return ans;
        
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