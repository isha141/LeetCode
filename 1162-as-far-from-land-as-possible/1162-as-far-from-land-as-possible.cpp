class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       int ans=-1;
        vector<pair<int,int>>ds;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1){
                    ds.push_back({i,j});
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1)
                    continue;
                int res=INT_MAX;
                for(auto itr: ds){
                    int x=abs(itr.first-i);
                    int y=abs(itr.second-j);
                    res=min(res,x+y);
                }
                ans=max(ans,res);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};