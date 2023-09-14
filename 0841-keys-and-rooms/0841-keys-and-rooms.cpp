class Solution { 
    void solve(int node,vector<vector<int>>&rooms,vector<int>&vis,int count){ 
           if(vis[node]==0){
               vis[node]=1;
               count+=1;
           }
          for(auto itr: rooms[node]){
              if(vis[itr]==0){
                  solve(itr,rooms,vis,count);
              }
          }
        return ;
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) { 
        
        queue<int>q;
        int n=rooms.size();
         vector<int>vis(n,0);
          vis[0]=1;
          vector<int>ds=rooms[0];
          for(auto iit: ds){
                // cout<<iit<<";;"; 
                vis[iit]=1;
              q.push(iit);
          }
          int count=1;
          while(!q.empty()){
              auto itr=q.front();
              q.pop();   
               // cout<<itr<<"**";
              // vis[itr]=1;
              for(auto iit: rooms[itr]){ 
                    // cout<<iit<<";;";
                    if(!vis[iit]){
                          // cout<<iit<<";;";
                          vis[iit]=1;
                        q.push(iit);
                    }
              }
          }
          for(auto i=0;i<n;++i){
               // cout<<i<<"-->"<<vis[i]<<endl;
              if(vis[i]==0)
                    return 0;
          }
         return 1;
        
    }
};