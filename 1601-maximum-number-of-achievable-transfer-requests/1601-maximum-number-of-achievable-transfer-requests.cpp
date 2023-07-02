class Solution { 
    private:
    int ans=0; 
    int m;
    void solve(int i,vector<vector<int>>&r,vector<int>&indeg,int count){
        if(i>=m){
            for(auto itr: indeg){
                if(itr!=0){
                    return ;
                }
            }
            ans=max(ans,count);
            return;
        }
        auto itr=r[i];
        indeg[itr[0]]++;
        indeg[itr[1]]--;
        solve(i+1,r,indeg,count+1);
        indeg[itr[0]]--;
        indeg[itr[1]]++;
        solve(i+1,r,indeg,count);
        return;
    }
public:
    int maximumRequests(int n, vector<vector<int>>& r) {
            m=r.size();
           // vector<int>adj[n];
           //  for(auto itr: r){
           //      adj[itr[0]].push_back(itr[1]);
           //      adj[itr[1]].push_back(itr[0]);
           //  } 
        vector<int>indeg(n,0);
        solve(0,r,indeg,0);
        return ans;
    }
};