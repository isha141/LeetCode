class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& r, int source, int target) {
        int n=r.size();
        vector<int>adj[100002]; 
        for(int i=0;i<r.size();++i){
             vector<int>ds=r[i];
             for(auto itr: ds){
                 adj[itr].push_back(i);
             }
        }
        if(adj[source].size()==0) return -1;
        if(adj[target].size()==0) return -1;
        queue<int>q;
        q.push(source);
        int ans=0;
        vector<int>dis(100002,INT_MAX);
        dis[source]=0;
        while(!q.empty()){
             int t=q.size();
             while(t--){
               auto itr=q.front();
                 q.pop();
                 if(itr==target)
                      return ans;
                 for(auto iit: adj[itr]){
                     for(int j=0;j<r[iit].size();++j){
                         if(dis[r[iit][j]]>dis[itr]+1){
                             dis[r[iit][j]]=dis[itr]+1;
                             q.push(r[iit][j]);
                         }
                     }
                 }
             }
            ans+=1;
        }
        return -1;
    }
};