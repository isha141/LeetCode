class Solution { 
    private:
    int n;
   bool solve(int s,int des,vector<int> adj[]){
       queue<int>q;
       q.push(s); 
       vector<int>vis(n+1,0);
       while(!q.empty()){
           int temp=q.front();
           q.pop();
           if(temp==des)
               return 1;
           for(auto itr: adj[temp]){
               if(vis[itr]==0){
                   q.push(itr);
                   vis[itr]=1;
               }
           }
       }
       return 0;
   }
public:
    bool validPath(int n, vector<vector<int>>& e, int s, int d) {
        vector<int>adj[n+1]; 
        this->n=n;
        for(int i=0;i<e.size();++i){
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
        }
        if(solve(s,d,adj))
            return 1;
        return 0;
    }
};