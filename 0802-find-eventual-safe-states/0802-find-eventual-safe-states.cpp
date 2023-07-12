class Solution { 
    bool iscycle(int node,vector<int>adj[],vector<int>&vis,vector<int>&dfsvis){
           vis[node]=1;
            dfsvis[node]=1;
           for(auto iit : adj[node]){
               if(!vis[iit]){
                   if(iscycle(iit,adj,vis,dfsvis))
                        return 1;
               }
               else if(dfsvis[iit]){
                   return 1;
               }
           }  
         dfsvis[node]=0;
        return 0;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
            vector<int> ans;
           map<int,int>mp;
           int n=g.size();
           vector<int>adj[n];
           for(int i=0;i<n;++i){
               vector<int>ds=g[i];
                for(auto itr: ds){
                    adj[i].push_back(itr);
                }
           } 
            vector<int>vis(n,0),dfsvis(n,0);
           for(int i=0;i<n;++i){
               if(iscycle(i,adj,vis,dfsvis)){
                   mp[i]++;
               }
           } 
           for(int i=0;i<n;++i){
               if(mp.find(i)==mp.end()){
                   ans.push_back(i);
               }
           }
          return ans;
    }
};