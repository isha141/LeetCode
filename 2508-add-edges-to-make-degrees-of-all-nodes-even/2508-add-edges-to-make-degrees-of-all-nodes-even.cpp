class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& e) {
        vector<int>indeg(n+1,0); 
        set<int>adj[n+1];
        for(int i=0;i<e.size();++i){
            adj[e[i][0]].insert(e[i][1]);
            indeg[e[i][0]]++;
            adj[e[i][1]].insert(e[i][0]);
            indeg[e[i][1]]++;
        }
        vector<int>odd;
        for(int i=0;i<=n;++i){
            if(1 & indeg[i]){
            odd.push_back(i); 
                // cout<<i<<"::"<<endl;
            }
        }
        if(odd.size()==0)
              return 1;
        if(odd.size()%2) return 0; 
        if(odd.size()>4) return 0;
        if(odd.size()==2){
            for(int i=1;i<=n;++i){
                if(adj[odd[0]].find(i)==adj[odd[0]].end() && adj[odd[1]].find(i)==adj[odd[1]].end()) 
                       return 1;
            }
        }
        if(odd.size()==4){
                 if(adj[odd[0]].find(odd[1])==adj[odd[0]].end() && adj[odd[2]].find(odd[3])==adj[odd[2]].end())
                       return 1;
               if(adj[odd[0]].find(odd[2])==adj[odd[0]].end() && adj[odd[1]].find(odd[3])==adj[odd[1]].end()) 
                   return 1;                 
            if(adj[odd[0]].find(odd[3])==adj[odd[0]].end() && adj[odd[1]].find(odd[2])==adj[odd[1]].end()) 
                return 1;
        }
        return 0;
    }
};