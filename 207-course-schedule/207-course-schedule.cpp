class Solution { 
    private:
    bool solve(int node, int par,vector<int>adj[],vector<int>&vis,vector<int>&dfsvis)
    {
        vis[node]=1;
        dfsvis[node]=1;
        for(auto itr: adj[node]){
            if(vis[itr]==0){
               if( solve(itr,node,adj,vis,dfsvis))
                   return 1;
            }
            else if(dfsvis[itr])
                return 1;
        }
        dfsvis[node]=0;
        return 0;
    }
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        int n=pre.size(); 
        vector<int>adj[num];
        for(int i=0;i<pre.size();++i){
            // adj[pre[i][0]].push_back(pre[i][1]);
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int>vis(num+1,0); 
        vector<int>dfsvis(num+1,0);
      for(int i=0;i<num;++i){
          if(vis[i]==0)
          {
              if(solve(i,-1,adj,vis,dfsvis))
                  return 0;
          }
      }
        return 1;
    }
};