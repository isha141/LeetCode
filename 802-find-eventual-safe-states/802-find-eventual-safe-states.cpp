class Solution { 
    private:
    bool iscycle(int node,vector<int>adj[],vector<int>&vis,vector<int>&dfsvis)
    {
        vis[node]=1;
        dfsvis[node]=1;
        for(auto itr: adj[node])
        {
            if(vis[itr]==0){
                if( iscycle(itr,adj,vis,dfsvis))
                    return 1;
            }
            else if(dfsvis[itr])
                return 1;
        }
        dfsvis[node]=0;
        return 0;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n=g.size();
        vector<int>adj[n];  
        for(int i=0;i<n;++i){
            for(auto itr: g[i]){
                adj[i].push_back(itr);
            }
        } 
        map<int,int>mp;
        vector<int>ans; 
        vector<int>dfsvis(n,0);
        vector<int>vis(n,0); 
        for(int i=0;i<n;++i){
            if(iscycle(i,adj,vis,dfsvis)){
                mp[i]++;
            }
        }
        for(int i=0;i<n;++i){
            if(mp.find(i)==mp.end())
                ans.push_back(i);
        }
        return ans;
    }
};