class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto itr: flights){
            int src=itr[0];
            int des=itr[1];
            int val=itr[2];
            adj[src].push_back({des,val});
        }
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
         k+=2;
      int ans=INT_MAX;      
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({1,{0,src}});
        while(!pq.empty()){
            auto itr=pq.top();
            pq.pop();
            int steps=itr.first;
            int cost=itr.second.first;
            int node=itr.second.second;
            if(node==dst){
                ans=min(ans,cost);
            }
            if(steps>=k)
                continue;
            for(auto iit: adj[node]){
                int n=iit.first;
                int val=iit.second;
                if(dis[n]>cost+val && (steps+1)<=k){
                    dis[n]=cost+val;
                    pq.push({steps+1,{dis[n],n}});
                }
            }
        }
         return ans==INT_MAX?-1:ans;
    }
};