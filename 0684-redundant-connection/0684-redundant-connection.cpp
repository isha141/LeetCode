class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        vector<int>ans; 
        int n=e.size();
        set<int>s; 
        vector<int>indeg(n+1,0);
        vector<int>adj[n+1];
        for(int i=0;i<n;++i){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
            indeg[e[i][0]]++;
            indeg[e[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<=n;++i){
            if(indeg[i]==1)
                  q.push(i);
        }
        while(!q.empty()){
            auto itr=q.front();
            q.pop(); 
            for(auto it: adj[itr]){
                indeg[it]--;
                if(indeg[it]==1)
                    q.push(it);
            }
        }
         for(int i=1;i<=n;++i){
            if(indeg[i]>1)s.insert(i);
        }
        for(auto itr: e){
            if(s.find(itr[0])!=s.end() && s.find(itr[1])!=s.end())
                ans=itr;
        }
        return ans;
    }
};