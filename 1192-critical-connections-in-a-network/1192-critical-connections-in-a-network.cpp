class Solution {
    private:
    int timer=0;
      vector<vector<int>>ans;
    void solve(int node,int parent,vector<int>adj[],vector<int>&vis,vector<int>&low,vector<int>&tim){
           vis[node]=1;
        low[node]=tim[node]=timer;
        timer++;
          for(auto itr: adj[node]){
              if(itr==parent) continue;
              if(!vis[itr]){
                  solve(itr,node,adj,vis,low,tim);
                  low[node]=min(low[itr],low[node]);
                  if(low[itr]> tim[node]){
                      ans.push_back({itr,node});
                  }
              }
              else{
                  low[node]=min(low[node],low[itr]);
              }
          }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
          vector<int>adj[n];
          for(auto it: conn){
              adj[it[0]].push_back(it[1]);
              adj[it[1]].push_back(it[0]);
          }
          vector<int>low(n,0);
          vector<int>tim(n,0); 
          vector<int>vis(n,0);
          solve(0,-1,adj,vis,low,tim);
          return ans;
    }
};