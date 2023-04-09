class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int des, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<f.size();++i){
            adj[f[i][0]].push_back({f[i][1],f[i][2]});
        }
        k+=2;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
         pq.push({1,{0,src}});
        int ans=1e9; 
        vector<int>dis(n,1e9);
        dis[src]=0;
        while(!pq.empty()){
            auto itr=pq.top();
            pq.pop();
            int steps=itr.first;
            int cost=itr.second.first;
            int node=itr.second.second; 
            if(steps<=k){
                if(node==des){
                    ans=min(ans,cost);
                }
            }
            if(steps>=k)  
                continue;
            for(auto itt: adj[node]){
                if(dis[itt.first]>cost+itt.second ){
                    dis[itt.first]=cost+itt.second;
                    pq.push({steps+1,{dis[itt.first],itt.first}});
                }
            }
        }
        return ans==1e9?-1:ans;
    }
};