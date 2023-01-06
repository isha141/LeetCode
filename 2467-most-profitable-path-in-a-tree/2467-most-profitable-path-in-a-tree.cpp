class Solution { 
    private:
    void dfs(int node,int par,vector<int>&vis,vector<int>&parent,vector<int>adj[],int count){
          vis[node]=count;
          parent[node]=par;
          for(auto itr: adj[node]){
              if(par==itr)
                  continue;
              dfs(itr,node,vis,parent,adj,count+1);
          }
    } 
    int dfsvis(int node,vector<int>&amount,vector<int>adj[],vector<int>&vis){
        int ans=-INT_MAX;
        int cur=amount[node];
        vis[node]=1;
        for(auto itr: adj[node]){
            if(vis[itr]==0){
                ans=max(ans,dfsvis(itr,amount,adj,vis));
            }
        }
        if(ans==-INT_MAX)
            return cur;
        return ans+cur;
    }
public:
    int mostProfitablePath(vector<vector<int>>& e, int bob, vector<int>& amount) {
        int n=amount.size();
        vector<int>adj[n+1];
        for(int i=0;i<e.size();++i){
         adj[e[i][0]].push_back(e[i][1]);
         adj[e[i][1]].push_back(e[i][0]);
        }
        vector<int>dis(n+1,0);
        vector<int>parent(n+1,0);
         dfs(0,0,dis,parent,adj,0);
        int bob_dis=0;
        while(bob!=0){
            if(dis[bob]>bob_dis){
                amount[bob]=0;
            }
            else if(dis[bob]==bob_dis){
                amount[bob]/=2;
            }
            bob_dis++;
            bob=parent[bob];
        }  
        vector<int>vis(n+1,0);
        return dfsvis(0,amount,adj,vis);
    }
};