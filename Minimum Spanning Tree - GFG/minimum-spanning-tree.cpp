// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{ 
    private:
    int solve(vector<int>&parent,vector<int>&key,vector<int>&mst,vector<vector<int>> adj[],int V)
    {
        key[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0}); 
        int ans=0;
        while(!pq.empty())
        {
        auto itr=pq.top();
        pq.pop();
        int temp=itr.second;
        if(!mst[temp])
        ans+=itr.first;
        mst[temp]=1;
        for(auto itt: adj[temp])
        {
            int node=itt[0];
            int weight=itt[1];
            if(mst[node]==false && key[node]>weight)
            {
                key[node]=weight;
                parent[node]=temp;
                pq.push({key[node],node});
            }
        }
        }
        return ans;
    }
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       vector<int>parent(V,-1);
       vector<int>mst(V,0);
       vector<int>key(V,INT_MAX);
       return solve(parent,key,mst,adj,V);
 
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