#define ll long long  
class Solution { 
    private:
  int dfs(int src, vector<vector<int>>&g,vector<int>&count){
        int c=1;
        for(auto itr: g[src])
        {
            c+=dfs(itr,g,count);
        }
      return   count[src]=c;
    }
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int ans=0; 
        int n =parents.size();
        vector<vector<int>>g(n);
        for(int i=1;i<n;i++){
            g[parents[i]].push_back(i);
        }
        vector<int>count(n);
        dfs(0,g,count); 
        // int ans=0; 
        ll maxi=0;
        for(int i=0;i<n;i++){
            ll product =1;
            product=max(product,(ll)(n-count[i]));
            for(auto itr: g[i])
            {
                product=product*count[itr];
            }
            if(product>maxi){
                maxi=product;
                ans=1; 
                continue;
            }
            else if(product==maxi){
                ans++;
            }
        }
        return ans;
    }
};