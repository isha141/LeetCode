//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution { 
    private:
    void solve(int node,vector<int>ad[],vector<int>&vis){
        vis[node]=1;
        for(auto it: ad[node]){
            if(!vis[it]){
                solve(it,ad,vis);
            }
        }
        return;
    }
  public:
    int numProvinces(vector<vector<int>> adj, int v) {
        // code here 
        vector<int>ad[v+1];
        for(int i=0;i<adj.size();++i){
            for(int j=0;j<adj[i].size();++j){
                if(adj[i][j]){
                    ad[i+1].push_back(j+1);
                    ad[j+1].push_back(i+1);
                }
            }
        }
        int ans=0;
        vector<int>vis(v+1,0);
        for(int i=1;i<=v;++i){
            if(!vis[i]){
                // cout<<i<<"::"<<endl;
                ans+=1;
                solve(i,ad,vis);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends