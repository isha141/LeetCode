class Solution { 
    private: 
    int ans=0; 
    int val=1; 
    int dis[100000];
   void solve(int node,int par,vector<int>adj[],string &s,char ch){
        dis[node]=1;
       
        for(auto itr: adj[node]){ 
            if(itr==par) continue;
            solve(itr,node,adj,s,ch);
            if(s[itr]!=s[node]){
                val=max(dis[node]+dis[itr],val);
                dis[node]=max(dis[node],dis[itr]+1);
            }
        }
    }
public:
    int longestPath(vector<int>& par, string s) {
        int n=par.size(); 
        vector<int>adj[n]; 
        memset(dis,1,sizeof(dis));
        for(int i=1;i<n;++i){
            adj[par[i]].push_back(i);
        } 
        solve(0,-1,adj,s,'.');
        return val;
    }
};