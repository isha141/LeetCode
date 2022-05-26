// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

int findparent(int u,vector<int>&parent)
{
    if(parent[u]==u)
    return u;
    return parent[u]=findparent(parent[u],parent);
}
void union1(int u,int v,vector<int>&parent,vector<int>&rank)
{ 
    u=findparent(u,parent);
    v=findparent(v,parent);
    if(rank[u]<rank[v])
    {
        parent[u]=v;
    }
    else if(rank[v]<rank[u])
    parent[v]=u;
    else{
        parent[u]=v;
        rank[v]++;
    }
}
class Solution
{ 
    private:
    int kruskals(vector<int>&rank,vector<int>&parent,vector<vector<int>> adj[],int V)
    { 
        int ans=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<V;i++)
        {
            for(auto itr: adj[i])
            {
                int n=itr[0];
                int w=itr[1];
                pq.push({w,{i,n}});
            }
        }
        while(!pq.empty())
        {
            auto itr=pq.top();
            int w=itr.first;
            int n1=itr.second.first;
            int n2=itr.second.second; 
            pq.pop();
            if(findparent(n1,parent)!=findparent(n2,parent))
            {
                union1(n1,n2,parent,rank);
                ans+=w;
            }
        }
        return ans;
    }
 	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here 
        vector<int>rank(V,0);
        vector<int>parent(V);
        for(int i=0;i<V;i++){
        rank[i]=0;
        parent[i]=i;
         } 
         return kruskals(rank,parent,adj,V);
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