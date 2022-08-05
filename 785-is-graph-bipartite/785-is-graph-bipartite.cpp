class Solution { 
    private:
    bool solve(int node,vector<vector<int>>& graph,vector<int>&color)
    {
        for(auto itr: graph[node]){
            if(color[itr]==-1){
                color[itr]=1^color[node];
              if(!solve(itr,graph,color))
                  return 0;
            }
            else if(color[itr]==color[node])
                return 0;
        }
        return 1;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) { 
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;++i){
            if(color[i]==-1){ 
                color[i]=1;
            if(!solve(i,graph,color))
                return 0;
            }
        }
        return 1;
    }
};