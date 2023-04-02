class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) { 
        vector<pair<int,int>>adj[n];
        for(int i=0;i<f.size();++i){
            adj[f[i][0]].push_back({f[i][1],f[i][2]});
        } 
        k+=2; 
        int ans=1e9; 
        vector<int>dis(n,1e9);
        dis[src]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({1,{0,src}});
        while(!pq.empty()){
             auto itr=pq.top();
             pq.pop();
            int steps=itr.first;
            int cost=itr.second.first;
            int node=itr.second.second;   
            if(steps>k) continue;
            if(node==dst && steps<=k){ 
                // cout<<k<<"::"<<cost<<endl;
                ans=min(ans,cost);
            } 
            if(steps>=k) continue;
            for(auto itr: adj[node]){
                int nm=itr.first;
                int c=itr.second;
                if(dis[nm]>cost+c && steps+1<=k){
                    dis[nm]=cost+c;
                    pq.push({steps+1,{dis[nm],nm}});
                }
                
            }
        }
        return ans==1e9?-1:ans;
    }
};