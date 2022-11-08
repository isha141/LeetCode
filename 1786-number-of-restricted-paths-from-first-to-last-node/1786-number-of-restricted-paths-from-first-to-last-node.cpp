class Solution { 
    long long mod=1e9+7; 
    int dp[20005]; 
    int n;
    long long solve(vector<vector<pair<int,int>>>&adj,int node,vector<int>&dis){
        if(node==1)
            return 1;
        if(dp[node]!=-1)
            return dp[node];
        long long path=0;
        for(auto i : adj[node]){
            int u=i.first;
            if(dis[u]>dis[node])
                path=(path%mod+solve(adj,u,dis)%mod)%mod;
        }
        
        return dp[node]=path;
    }
public:
    int countRestrictedPaths(int n, vector<vector<int>>& e) {
        this->n=n;
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<e.size();++i){
            int u=e[i][0];
            int v=e[i][1];
            int w=e[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }  
        vector<int>dis(n+1,INT_MAX);
        dis[n]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; 
        pq.push({0,n});
        while(!pq.empty()){
            auto itr= pq.top(); 
            pq.pop(); 
            int node=itr.second;
            for(auto it: adj[node]){
                int u=it.first;
                int w=it.second; 
                if(dis[u]>dis[node]+w){
                    dis[u]=dis[node]+w;  
                    pq.push({dis[u],u});
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        return solve(adj,n,dis);
    }
};