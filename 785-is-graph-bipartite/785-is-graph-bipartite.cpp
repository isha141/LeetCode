class Solution { 
    private:
    bool solve(int i,vector<vector<int>>& graph,int m,vector<int>&visited)
    {
        for(auto itr: graph[i])
        {
            if(visited[itr]==-1)
            {
                visited[itr]=!visited[i];
                if(!solve(itr,graph,m,visited))
                    return false;
            }
            else if(visited[itr]==visited[i])
                 return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size(); 
        vector<int> visited(m,-1);
        for(int i=0;i<m;i++)
        {
            if(visited[i]==-1)
            { 
                visited[i]=0;
              if(!solve(i,graph,m,visited))
                  return false;
            }
        }
        return true;
    }
};