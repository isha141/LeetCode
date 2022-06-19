// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution { 
    private:
    bool dfs(int v,vector<int>&color,vector<int>adj[]){
        for(auto itr: adj[v]){
            if(color[itr]==-1){
                color[itr]=1^color[v];
                if(!dfs(itr,color,adj))
                return 0;
            }
            else if(color[itr]==color[v])
            return 0;
        }
        return 1;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here 
	    vector<int>color(V,-1);
	    for(int i=0;i<V;++i){
	        if(color[i]==-1)
	        if(!dfs(i,color,adj))
	          return 0;
	    } 
	    return 1;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends