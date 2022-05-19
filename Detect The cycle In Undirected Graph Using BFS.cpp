private:
bool iscycle(int i, vector<int>&visited,vector<int>adj[])
    {
        queue<pair<int,int>>q;
        q.push({i,-1}); 
        visited[i]=1;
        while(!q.empty())
        {
                auto itr=q.front();
                int node=itr.first;
                int prev=itr.second; 
                q.pop();
                for(auto &it: adj[node])
                {
                    if(visited[it] && it!=prev)
                    { 
                         return true;
                    }
                    else 
                    {
                          visited[it]=1;
                        q.push({it,node});
                    }
                }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       vector<int>visited(V+1,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(iscycle(i,visited,adj))
                return true;
            }
        }
        return false;
    }
};
