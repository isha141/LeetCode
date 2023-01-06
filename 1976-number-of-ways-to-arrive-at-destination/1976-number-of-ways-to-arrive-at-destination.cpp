typedef long long ll;
class Solution {
public: 
    int mod=1e9 + 7;
    int countPaths(int n, vector<vector<int>>& r) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<r.size();++i){
            adj[r[i][0]].push_back({r[i][1],r[i][2]});
            adj[r[i][1]].push_back({r[i][0],r[i][2]});
        } 
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
        pq.push({0,0});  
        vector<long long>dis(n+1,LONG_MAX); 
        vector<ll>ways(n,0);
        ways[0]=1;
        dis[0]=0;
        int ans=INT_MAX;
        while(!pq.empty()){
            int node=pq.top().second;
            ll weight=pq.top().first;
             pq.pop(); 
            if(dis[node]<weight) { 
                continue; 
            }
            for(auto [itr,itr1]: adj[node]){
                if(dis[itr]>dis[node]+itr1){
                    dis[itr]=dis[node]+itr1;
                    pq.push({dis[itr],itr});
                    ways[itr]=ways[node];
                }
                else if(dis[itr]==dis[node]+itr1){ 
                  ways[itr]=(ways[itr]+ways[node])%mod;                    
                }
            }
        } 
        // for(int i=0;i<n;++i)
        //     cout<<ways[i]<<" ";
        return ways[n-1];
        
    }
};