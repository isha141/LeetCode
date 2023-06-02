class Solution { 
    private:
    int n; 
    void solve(int node ,vector<int>adj[],vector<int>&vis,int &c){
        int ans=0;
        c+=1;
        for(auto itr: adj[node]){
            if(!vis[itr]){ 
                 vis[itr]=1;
               solve(itr,adj,vis,c); 
                // vis[itr]=0;
            }
        }
        // return ans;
    }
public:
    int maximumDetonation(vector<vector<int>>& b) {
         n=b.size();
         vector<int>adj[n];
         for(int i=0;i<n;++i){
             int x=b[i][0];
             int y=b[i][1];
             int r1=b[i][2];
             for(int j=0;j<n;++j){
                 if(i==j) continue;
                 int x1=abs(x-b[j][0]);
                 int y1=abs(y-b[j][1]);
                 if(1ll*x1*x1+1ll*y1*y1<=1ll*r1*r1){
                     adj[i].push_back(j);
                 }
             }
         }
        int ans=0;
        for(int i=0;i<n;++i){
            vector<int>vis(n+1,0);
                vis[i]=1; 
                 int c=0;
                solve(i,adj,vis,c);
            ans=max(ans,c);
        }
        return ans;
    }
};