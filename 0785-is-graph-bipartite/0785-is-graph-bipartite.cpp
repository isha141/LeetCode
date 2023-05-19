class Solution {
    private:
    bool solve(int node,vector<vector<int>>&graph,vector<int>&vis){
          for(auto itr : graph[node]){
               if(vis[itr]==-1){
                   vis[itr]=1^vis[node];
                   if(solve(itr,graph,vis))
                         return 1;
               }
              else if(vis[itr]==vis[node]){
                   return 1;
              }
          }
        return 0;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
            int n=graph.size();
             vector<int>vis(n,-1);
           for(int i=0;i<n;++i){
               if(vis[i]==-1){ 
                    vis[i]=1;
                   if(solve(i,graph,vis))
                          return 0;
               }
           }
        return 1;
    }
};