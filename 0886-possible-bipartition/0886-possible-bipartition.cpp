class Solution { 
    bool solve(int node,vector<int>adj[],vector<int>&color){
        for(auto itr: adj[node]){
            if(color[itr]==0){ 
                color[itr]=1^color[node];
                if(!solve(itr,adj,color))
                    return 0;
            }
            else if(color[itr]==color[node])
                return 0;   
        } 
        return 1;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        vector<int>adj[n+1]; 
        vector<int>color(n+1,0);
        for(int i=0;i<d.size();++i){
            adj[d[i][0]].push_back(d[i][1]);
            adj[d[i][1]].push_back(d[i][0]);
        }
        for(int i=1;i<=n;++i){
            if(color[i]==0){
                if(!solve(i,adj,color))
                    return 0;
            }
        }
        return 1;
    }
};