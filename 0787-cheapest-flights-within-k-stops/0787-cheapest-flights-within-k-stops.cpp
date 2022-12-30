class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<f.size();++i){
            adj[f[i][0]].push_back({f[i][1],f[i][2]});
        }
        queue<pair<int,pair<int,int>>>pq; 
        int ans=1e9;
        vector<int>vis(n,INT_MAX);
        vis[src]=0;
        k+=2;
        pq.push({1,{src,0}});
        while(!pq.empty()){
            auto itr=pq.front();
            pq.pop();
            int n=itr.second.first;
            int dis=itr.second.second;
            int stop=itr.first; 
            if(stop<k){
                if(n==dst){
                    ans=min(ans,dis);
                }
            }
            if(stop>=k){
                 if(n==dst){
                    ans=min(ans,dis);
                }
                continue;
            }
            for(auto itr: adj[n]){
                if(vis[itr.first]>dis+itr.second){
                    vis[itr.first]=dis+itr.second;
                    pq.push({stop+1,{itr.first,dis+itr.second}});
                }
            }
        }
        return ans==1e9?-1:ans;
    }
};