// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{ 
     private:  
    int solve(int V,vector<vector<int>> adj[], vector<int>&mst, vector<int>&parent, vector<int>&key)
    {
        key[0]=0; 
        int total=0;
        for(int count=0;count<V-1;count++){
            int mini=INT_MAX; 
            int u;
            for(int i=0;i<V;i++)
            {
               if(mini>key[i] && !mst[i])
               {
                   mini=key[i];
                   u=i;
               }
            }  
            mst[u]=1;
            for(auto itr: adj[u])
            { 
                
              //  auto temp=itr.top();
                int node=itr[0];
                int weight=itr[1]; 
                ///if(key[node]!=INT_MAX){
                     if(!mst[node] && key[node]>weight)
                     {
                         key[node]=weight;
                         parent[node]=u;
                     }
               // }               
            }
        }
            //return total;
            return 0;
        }
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    { 
        // n=V;
         // code here   
          vector<int>mst(V,0);
        vector<int>parent(V,-1);
        vector<int>key(V,INT_MAX);
         solve(V,adj,mst,parent,key);  
        int ans=0;
        for(int i=0;i<V;i++)
        {
            if(key[i]!=INT_MAX)
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