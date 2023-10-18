class Solution {
    private:
//     int solve(int node,vector<int>adj[],vector<int>&time,int c){
        
    // }
public:
    int minimumTime(int n, vector<vector<int>>& r, vector<int>& time) {
          vector<int>adj[n];
          vector<int>indeg(n,0);
          for(auto itr: r){
              adj[itr[0]-1].push_back(itr[1]-1);
              indeg[itr[1]-1]++;
          }   
          queue<int>q;
          vector<int>maxi(n,0);
          for(int i=0;i<n;++i){
           if(indeg[i]==0){
               q.push(i);
               maxi[i]=time[i];
           }   
         }
         int ans=0;
         while(!q.empty()){
             int t=q.size();
             // int maxi=0;
             while(t--){
                 int itr=q.front();
                 q.pop();
                 for(int iit : adj[itr]){
                     maxi[iit]=max(maxi[iit],maxi[itr]+time[iit]);
                     indeg[iit]--;
                     if(indeg[iit]==0){
                         q.push(iit);
                     }
                 }
             }
             // ans+=maxi;
         }
         for(int i=0;i<n;++i){
              ans=max(ans,maxi[i]);
         }
        return ans;
    }
};