class Solution {
    private:
    int ok(int node,vector<int>adj[],vector<int>&vis,vector<int>&dfsvis){
          vis[node]=1;
          dfsvis[node]=1;
          
          for(auto iit: adj[node]){
              if(!vis[iit]){
                  if(ok(iit,adj,vis,dfsvis))
                        return 1;
              }
              else if(dfsvis[iit])
                    return 1;
          }
          dfsvis[node]=0;
         return 0;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
          int n=graph.size();
          vector<int>adj[n];
          for(int i=0;i<n;++i){
              vector<int>ds=graph[i];
              for(auto iit:ds){
                  adj[i].push_back(iit);
              }
          }
          map<int,int>mp;
          vector<int>vis(n,0);
          vector<int>dfsvis(n,0);
          vector<int>ans;
          for(int i=0;i<n;++i){
              if(ok(i,adj,vis,dfsvis)){
                 mp[i]++;
              }
          }
          for(int i=0;i<n;++i){
              if(mp.find(i)==mp.end())
                  ans.push_back(i);
          }
         return ans;
    }
};