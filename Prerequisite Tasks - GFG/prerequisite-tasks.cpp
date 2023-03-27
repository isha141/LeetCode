//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution { 
    private:
    bool solve(int node,vector<int>&vis,vector<int>&dfsvis,vector<int>adj[]){
        vis[node]=1;
        dfsvis[node]=1;
        for(auto itr: adj[node]){
            if(!vis[itr]){
                if(solve(itr,vis,dfsvis,adj))
                  return 1;
            }
            else if(dfsvis[itr]) 
            return 1;
        } 
        dfsvis[node]=0;
        return 0;
    }
public:
	bool isPossible(int n, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int>adj[n];
	    for(auto itr: pre){
	        adj[itr.second].push_back(itr.first);
	    }
	    vector<int>vis(n,0);
	    vector<int>dfsvis(n,0);
	    for(int i=0;i<n;++i){
	        if(!vis[i]){
	            if(solve(i,vis,dfsvis,adj))
	              return 0;
	        }
	    }
	    return 1;
	}
	
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends