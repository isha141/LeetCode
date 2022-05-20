class Solution { 
    private:
    bool bfs(vector<vector<int>>& graph,int i,vector<int>&color)
    {
        queue<int>q;
        q.push(i);
        color[i]=0;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            for(auto itr: graph[temp])
            {
                if(color[itr]==-1)
                {
                    q.push(itr);
                    color[itr]=1^color[temp];
                } 
                else if(color[itr]!=-1)
                {
                    if(color[itr]==color[temp])
                        return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int m=graph.size();
        int n=graph[0].size();
        vector<int>color(m,-1);
        for(int i=0;i<m;i++)
        {
            if(color[i]==-1)
            {
                if(!bfs(graph,i,color))
                    return false;
            }
        }
        return true;
    }
};