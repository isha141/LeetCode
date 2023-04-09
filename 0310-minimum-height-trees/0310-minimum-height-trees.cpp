class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& e) { 
        vector<int>adj[n];
        vector<int>indeg(n,0);
        if(e.size()==0) return {0};
        for(int i=0;i<e.size();++i){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
            indeg[e[i][0]]++;
            indeg[e[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;++i){
            if(indeg[i]==1)
                q.push(i);
        } 
        vector<int>res;
        while(!q.empty()){
            vector<int>ans; 
            int t=q.size();
            while(t--){
                auto itr=q.front();
                q.pop();
                ans.push_back(itr);
                for(auto itt: adj[itr]){
                    indeg[itt]--;
                    if(indeg[itt]==1)
                        q.push(itt);
                }
            }
            res=ans;
        }
        return res;
    }
};