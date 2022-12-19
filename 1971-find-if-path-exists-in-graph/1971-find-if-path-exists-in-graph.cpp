class Solution { 
    bool solve(int s,vector<int>adj[],int d,vector<int>&vis){
        if(s==d)
            return 1;
        vis[s]=1;
        for(auto itr: adj[s]){
            if(vis[itr]==0){
                if(solve(itr,adj,d,vis))
                    return 1;
                // vis[itr]=0;
            }
        }
        return 0;
    }
public:
    bool validPath(int n, vector<vector<int>>& e, int s, int d) {
        vector<int>adj[n+1];
        for(int i=0;i<e.size();++i){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }
        vector<int>vis(n+1,0); 
        vis[s]=1;
      if(solve(s,adj,d,vis))
          return 1;
        return 0;
    }
};