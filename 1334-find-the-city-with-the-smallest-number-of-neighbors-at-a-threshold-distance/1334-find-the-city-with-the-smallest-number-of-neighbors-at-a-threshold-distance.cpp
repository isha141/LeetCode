class Solution { 
    private:
    int maxi=INT_MAX;
    int ans=0;
    void solve(int node,vector<pair<int,int>>adj[],int d,int n){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,node});
        vector<int>dis(n,INT_MAX);
        dis[node]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int weight=it.first;
            for(auto itt: adj[node]){
                if(dis[itt.first]>dis[node]+itt.second){
                    dis[itt.first]=dis[node]+itt.second;
                    pq.push({dis[itt.first],itt.first});
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;++i){
            if(dis[i]<=d){
                cnt+=1;
            }
        }
        if(maxi>=cnt){
            maxi=cnt;
            ans=node;
        }
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dis) {
        vector<pair<int,int>>adj[n];
        for(auto itt: edges){
            adj[itt[0]].push_back({itt[1],itt[2]});
            adj[itt[1]].push_back({itt[0],itt[2]});
        }
        for(int i=0;i<n;++i){
            solve(i,adj,dis,n);
        }
        return ans;
    }
};