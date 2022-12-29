class Solution { 
    private:
    vector<vector<int>>adj;
     vector<int>dis;
    vector<int>par;
    vector<int>vis;
    void dfs(int node,int parent=0,int count=0){
        dis[node]=count;
         par[node]=parent; 
        for(auto itr: adj[node]){
            if(parent==itr){
                continue;
            }
            dfs(itr,node,count+1);
        }
    }
    int dfs2(int node,vector<int>&amount){
        int ans=-INT_MAX;
        int ret=amount[node];
        vis[node]=1;
        for(auto itr: adj[node]){
            if(vis[itr]==0){
               ans=max(ans,dfs2(itr,amount));
            }
        }
        if(ans==-INT_MAX)
            return ret;
        return ans+ret;
    }
public:
    int mostProfitablePath(vector<vector<int>>& e, int bob, vector<int>& am) {
        int n=am.size();
         adj.resize(n,vector<int>());
        par.resize(n);
        dis.resize(n);
        for(int i=0;i<e.size();++i){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }
        dfs(0); 
        int cur=bob;
        int bob_dis=0;
        while(cur!=0){
            if(dis[cur]>bob_dis){
                am[cur]=0;
            }
            else if(dis[cur]==bob_dis){
                am[cur]/=2;
            } 
            bob_dis++;
            cur=par[cur];
        } 
        vis.resize(n,0);
        vis[0]=1;
        return dfs2(0,am);
        // return 0;
    }
};