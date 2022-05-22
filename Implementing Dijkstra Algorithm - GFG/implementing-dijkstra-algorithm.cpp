// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{    private:
    void solve(priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>&pq,int V,vector<vector<int>> adj[],vector<int>&dis)
    {  
        while(!pq.empty())
        { 
            int d=pq.top().first; //distance 
            int node=pq.top().second;  //modee;
            pq.pop();
            for(auto itr: adj[node])
            {
                int e=itr[0]; //node
                int w=itr[1]; //weight
                if(dis[node]+w<dis[e])
                {
                    dis[e]=dis[node]+w;
                    pq.push({dis[node]+w,e});
                }
            }
        }
    }
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here 
        vector<int>dis(V,INT_MAX);
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,S}); 
        dis[S]=0;
        solve(pq,V,adj,dis);
        return dis;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends