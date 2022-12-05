class Solution { 
    private:
     int n;
    bool check(int node,vector<int>adj[],vector<int>&color){
        if(node>=n)
            return 1;
        for(auto itr: adj[node]){
            if(color[itr]==-1){
                color[itr]=1^color[node];
                if(!check(itr,adj,color))
                    return 0;
            }
            else if(color[itr]==color[node])
                return 0;
        }
        return 1;
    }
    int bfs(int node,vector<int>adj[]){
        queue<int>q;
        q.push(node);  
        vector<int>vis(n+1,0);
        int c=0;
        while(!q.empty()){
            int t=q.size();
            while(t--){
                auto itr=q.front(); 
                q.pop(); 
                vis[itr]=1;
                for(auto it: adj[itr]){
                    if(vis[it]==0){
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
            c++;
        }
        return c;
    } 
    int maxdis(int node,vector<int>&dist,vector<int>adj[],vector<int>&vis){ 
        if(vis[node])
            return dist[node];
        vis[node]=1; 
        
        int maxi=dist[node];
        int ans=maxi;
        for(auto itr: adj[node]){
            if(vis[itr]==0){
                // ans=max(ans,dist[itr]);
                ans=max(ans,maxdis(itr,dist,adj,vis));
            }
        }
        return ans;
    }
public:
   
    int magnificentSets(int n, vector<vector<int>>& e) {
        vector<int>adj[n+1];
        this->n=n;
        for(int i=0;i<e.size();++i){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        } 
        vector<int>color(n+1,-1);
        color[1]=0;
        if(!check(1,adj,color))
            return -1; 
        int ans=0;   
        vector<int>dist(n+1,-1);
        for(int i=1;i<=n;++i){
            dist[i]=bfs(i,adj);
        } 
        // for(int i=1;i<=n;++i){
            // cout<<i<<" "<<dist[i]<<endl;
        // }
        vector<int>vis(n+1,0);
        for(int i=1;i<=n;++i){ 
            if(!vis[i]){
                cout<<i<<" ,,";
            int temp=maxdis(i,dist,adj,vis);
            ans+=temp;
            }
        }
        return ans;
        
        
    }
};