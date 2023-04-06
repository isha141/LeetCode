class Solution { 
    private:
    int n,m;
public:
    int leastBricks(vector<vector<int>>& wall) {
         n=wall.size();
         m=wall[0].size();
        int maxi=0; 
        long long mini=1e9;
        map<int,int>mp;
         for(int i=0;i<n;++i){
             int sum=0;
             map<int,int>ds;
             for(int j=0;j<wall[i].size()-1;++j){ 
                 sum+=wall[i][j];
                 mp[sum]++;
             }
         }
        int ans=0;
        for(auto itr: mp)
            ans=max(ans,itr.second);
        return n-ans;
    }
};