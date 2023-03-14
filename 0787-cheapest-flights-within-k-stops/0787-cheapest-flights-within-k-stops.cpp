class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto itr: f){
            int src=itr[0];
            int des=itr[1];
            int fair=itr[2];
            adj[src].push_back({des,fair});
        }
priority_queue<pair<int,pair<int,int>>>pq; 
        pq.push({0,{src,1}});
        int ans=1e9;  
        vector<int>dis(n+1,1e9); 
        dis[src]=0;
        k+=2;
        while(!pq.empty()){
            auto itr=pq.top();
            pq.pop();
            int fair=itr.first;
            int node=itr.second.first;
            int steps=itr.second.second;   
            if(steps<k){
            if(node==dst){
                ans=min(ans,fair); 
            }  
            }
            if(steps>=k){
                if(node==dst){
                    ans=min(ans,fair);
                }
                continue;
            }
            for(auto itr: adj[node]){
                if(dis[itr.first]>(fair+itr.second)){
                    pq.push({fair+itr.second,{itr.first,steps+1}});  
                    dis[itr.first]=(fair+itr.second);
                }
            }
        }
        return ans==1e9?-1:ans; 
    }
};