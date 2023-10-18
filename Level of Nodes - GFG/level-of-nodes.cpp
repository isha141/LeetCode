//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here 
	    queue<int>q;
	    q.push(0);
	    int level=0;
	    vector<int>vis(V,0);
	    while(!q.empty()){
	        int t=q.size();
	        while(t--){
	            auto itr=q.front();
	            q.pop();
	            vis[itr]=1;
	            if(itr==X)
	            return level;
	            for(auto iit: adj[itr]){
	                if(!vis[iit]){
	                    vis[iit]=1;
	                    q.push(iit);
	                }
	            }
	        }
	        level+=1;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends