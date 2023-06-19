class Solution { 
    private:
    int n;
    void solve(int node,vector<int>adj[],vector<int>&vis,int &ans){
         queue<pair<int,int>>q;
        q.push({node,-1});
         int count=0; 
        vector<int>dis(n,INT_MAX);
        while(!q.empty()){
            int t=q.size();    // aplying bfs 
            while(t--){
                auto itr=q.front();
                q.pop(); 
                 int node=itr.first;
                int par=itr.second;
                 vis[node]=1;
                dis[node]=count;
                for(auto iit: adj[node]){ 
                      if(iit==par) continue;
                    if(!vis[iit]){
                        dis[iit]=dis[node]+1;
                        q.push({iit,node});
                        vis[iit]=1;
                    }
                    else if(dis[iit]>dis[node]+1){
                            dis[iit]=dis[node]+1; 
                            q.push({iit,node});
                        }
                    else if(iit!=par && vis[iit]){
                        ans=min(ans,dis[node]+dis[iit]+1);  
                    }
                }
            }
            count+=1;
        }
        return;
    }
public:
    int findShortestCycle(int n, vector<vector<int>>& e) {
         vector<int>vis(n,0); 
        this->n=n;
          vector<int>adj[n]; 
          for(auto itr: e){
              adj[itr[0]].push_back(itr[1]);
              adj[itr[1]].push_back(itr[0]);
          }
          int ans=INT_MAX; 
        vector<int>dis(n,INT_MAX);
          for(int i=0;i<n;++i){
                  solve(i,adj,vis,ans);
          }
        return ans==INT_MAX?-1:ans;
    }
};