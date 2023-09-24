//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution { 
    private:
    bool solve(int node,vector<int>&vis,vector<int>&bfsvis,vector<int>adj[]){
        vis[node]=1;
        bfsvis[node]=1;
        for(auto itt: adj[node]){
            if(!vis[itt]){
                if(solve(itt,vis,bfsvis,adj))
                 return 1;
            }
            else if(bfsvis[itt]){
                return 1;
            }
        }
        bfsvis[node]=0;
         return 0;
    }
public:
	bool isPossible(int n,int P, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int>adj[n];
	    for(auto itt: pre){
	        adj[itt.first].push_back(itt.second);
	    }
	    vector<int>vis(n,0);
	     vector<int>bfsvis(n,0);
	    for(int i=0;i<n;++i){
	        if(!vis[i]){
	            if(solve(i,vis,bfsvis,adj))
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
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends