class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& succ, int src, int end) {
          vector<pair<int,double>>adj[n+1];
        for(int i=0;i<e.size();++i){
            adj[e[i][0]].push_back({e[i][1],succ[i]}); 
            adj[e[i][1]].push_back({e[i][0],succ[i]});
        }
        priority_queue<pair<double,int>,vector<pair<double,int>>>pq;
        pq.push({1.0,src}); 
        double ans=0.000; 
        vector<double>vis(n+1,0); 
        vis[src]=1.0;
        while(!pq.empty()){
            auto itr=pq.top();
            pq.pop();
            int node=itr.second;
            double prob=itr.first;
            if(node==end){
                ans=prob;
                return ans;
            }
            for(auto itr: adj[node]){
                if(vis[itr.first]<prob*itr.second){
                    vis[itr.first]=prob*itr.second;
                    pq.push({prob*itr.second,itr.first});
                }
            }
        }
        return ans;
    }
};