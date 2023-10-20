class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
          vector<pair<int,int>>adj[n];
          for(auto it: flights){
               adj[it[0]].push_back({it[1],it[2]});
          }
          k+=2;
         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq; 
         vector<int>dis(n,INT_MAX);
          dis[src]=0;
         pq.push({1,{0,src}}); 
         int ans=INT_MAX;
         while(!pq.empty()){
             auto itr=pq.top();
             pq.pop();
             int node=itr.second.second;
             int steps=itr.first;
             int cost=itr.second.first;
             if(node==dst){
                 ans=min(ans,cost);
                 // continue;
             }
             if(steps>=k){
                 continue;
             }
             for(auto iit: adj[node]){
                 if(dis[iit.first]>cost+iit.second){
                     dis[iit.first]=cost+iit.second;
                     pq.push({steps+1,{dis[iit.first],iit.first}});
                 }
             }
         }
         return ans==INT_MAX?-1:ans;
    } 
};