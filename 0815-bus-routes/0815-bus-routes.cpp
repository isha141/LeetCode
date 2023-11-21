class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        vector<int>adj[1000002];
        for(auto i=0;i<routes.size();++i){
            for(auto itr: routes[i]){
                adj[itr].push_back(i);
            }
        }
         if(source==target) return 0;
        if(adj[source].size()==0) return -1;
        if(adj[target].size()==0) return -1;
        queue<int>q;
        q.push(source);
        vector<int>dis(1000002,INT_MAX);
        dis[source]=0;
        int ans=0;
        while(!q.empty()){
            int t=q.size();
            while(t--){
                auto itr=q.front();
                q.pop();
                if(itr==target)
                      return ans;
                for(auto it: adj[itr]){
                    for(int j=0;j<routes[it].size();++j){
                        if(dis[routes[it][j]]>dis[itr]+1){
                            q.push(routes[it][j]);
                            dis[routes[it][j]]=dis[itr]+1;
                        }
                    }
                }
            }
            ans+=1;
        }
         return -1;
    }
};