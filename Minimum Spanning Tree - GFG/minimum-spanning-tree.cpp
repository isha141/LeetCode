// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{ 
    private:
    void solve(int v , vector<vector<int>>adj[],vector<int>&par,vector<int>&key,vector<int>&mst){
        key[0]=0;
        for(int count=0;count<v-1;++count)
        {
            int mini=INT_MAX; 
            int node;
            for(int i=0;i<v;++i)
            {
                if(mst[i]==0 && key[i]<mini){
                    mini=key[i];
                    node=i;
                }
            }
            mst[node]=1;
            for(auto itr: adj[node])
            { 
                int n=itr[0];
                int weight=itr[1];
                if(mst[n]==0 && key[n]>weight){
                    key[n]=weight;
                    par[n]=node;
                }
            }
        }
    }
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here 
        int ans=0;
        vector<int>par(V,-1);
        vector<int>mst(V,0);
        vector<int>key(V,INT_MAX);
        solve(V,adj,par,key,mst); 
        for(int i=0;i<V;++i){
            ans+=key[i];
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