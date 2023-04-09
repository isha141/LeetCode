class Solution {
public:
    int largestPathValue(string col, vector<vector<int>>& e) {
          int n=col.size();
         vector<int>adj[n];
        vector<int>indeg(n,0); 
        int m=e.size();
         for(int i=0;i<m;++i){
             adj[e[i][0]].push_back(e[i][1]);
             indeg[e[i][1]]++;
         }
          queue<int>q;
         for(int i=0;i<n;++i){
              if(indeg[i]==0)
                  q.push(i);
         } 
        // for(int i=0;i<n;++i)
            // cout<<i<<" "<<indeg[i]<<" "<<endl;
        vector<vector<int>>ds(n+1,vector<int>(26,0));
        int count=0; 
        int ans=0;
        while(!q.empty()){
            auto node=q.front();
            q.pop(); 
            // cout<<node<<"::"<<endl;
            ans=max(ans,++ds[node][col[node]-'a']); 
            count++;
            for(auto it: adj[node]){
                for(int i=0;i<26;++i){
                  ds[it][i]=max(ds[it][i],ds[node][i]); 
                }
                indeg[it]--;
                if(indeg[it]==0)
                    q.push(it);
            }
        }
        return count<n?-1:ans;
    }
};