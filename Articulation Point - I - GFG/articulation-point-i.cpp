// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution { 
    private:
    void solve(int node ,int parent,vector<int>adj[], vector<int>&vis,vector<int>&tim1,vector<int>&low,int &timer,vector<int>&ans)
    {
        vis[node]=1;
        tim1[node]=low[node]=timer++; 
        int child=0;
        for (auto itr: adj[node])
        { 
            if(itr==parent) continue;
            if(vis[itr]==0)
            {
            solve(itr,node,adj,vis,tim1,low,timer,ans);
            low[node]=min(low[node],low[itr]);
            if(low[itr]>=tim1[node] && parent!=-1)
            {
                ans[node]=1;
            } 
            child++;
            }
            else
            {
                low[node]=min(low[node],tim1[itr]);
            }
        } 
        if(child>1 && parent==-1)
            ans[node]=1;
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here 
        vector<int>ans(V,0);
        vector<int>vis(V,0);
        vector<int>tim1(V,0);
        vector<int>low(V,0); 
        int timer=0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                solve(i,-1,adj,vis,tim1,low,timer,ans);
            }
        } 
        //(ans.begin(),ans.end()); sort 
        vector<int>res;
        for(int i=0;i<V;i++){
        if(ans[i]==1)
        res.push_back(i); 
        }
        if(res.size()==0) return {-1};
        return res;
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
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends