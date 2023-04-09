class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& e) {
        set<int>adj[n+1]; 
        vector<int>indeg(n+1,0);
        for(int i=0;i<e.size();++i){
            adj[e[i][0]].insert(e[i][1]);
            adj[e[i][1]].insert(e[i][0]); 
            indeg[e[i][0]]++;
            indeg[e[i][1]]++;
        }
        vector<int>ds;
        for(int i=1;i<=n;++i){
            if(indeg[i]%2)
                ds.push_back(i);
        } 
        if(ds.size()==0) return 1;
        if(ds.size()>4)
             return 0;
        if(ds.size()%2) return 0;
        if(ds.size()==2){
            for(int i=1;i<=n;++i){
                if(adj[i].find(ds[0])==adj[i].end() && adj[i].find(ds[1])==adj[i].end()) 
                    return  1;
            }
            return 0;
        }
        if(ds.size()==4){
            if(adj[ds[0]].find(ds[1])==adj[ds[0]].end() && adj[ds[2]].find(ds[3])==adj[ds[2]].end())
                  return 1;
            if(adj[ds[0]].find(ds[2])==adj[ds[0]].end() && adj[ds[1]].find(ds[3])==adj[ds[1]].end())
                  return 1;
            if(adj[ds[0]].find(ds[3])==adj[ds[0]].end() && adj[ds[1]].find(ds[2])==adj[ds[1]].end())
                  return 1;
        }
        return 0;
    }
};